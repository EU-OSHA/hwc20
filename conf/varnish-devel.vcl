#
# Customized VCL file for serving up a Drupal site with single back-end
#
# For more information on this VCL, visit the Lullabot article:
# http://www.lullabot.com/articles/varnish-multiple-web-servers-drupal
#

import std;

# Default backend definition. Set this to point to your content server.
backend default {
  .host = "127.0.0.1";
  .port = "8080";
  .max_connections = 250;
  .connect_timeout = 300s;
  .first_byte_timeout = 300s;
  .between_bytes_timeout = 300s;
}

# Define the list of hosts allowed to purge the cache
acl purge {
  "localhost";
  "127.0.0.1";
  "10.0.0.0"/24;
}

# Define the internal network subnet.
# These are used below to allow internal access to certain files while not
# allowing access from the public internet.
acl internal {
  "10.0.0.0"/24;
}

# Respond to incoming requests.
sub vcl_recv {

  set req.grace = 120s;

  # Register URL to check Varnish status
  if (req.request == "GET" && req.url ~ "^/varnishcheck$") {
    error 200 "Varnish is Ready";
  }

  if (req.request == "PURGE") {
    if (!client.ip ~ purge) {
      error 403 "Not allowed";
    }
    return (lookup);
  }

  # Use anonymous, cached pages if all backends are down.
  if (req.backend.healthy) {
    set req.grace = 15s;
  } else {
    unset req.http.Cookie;
    set req.grace = 5m;
  }

  # Get rid of progress.js query params
  if (req.url ~ "^/misc/progress\.js\?[0-9]+$") {
    set req.url = "/misc/progress.js";
  }

  # If global redirect is on
  #if (req.url ~ "node\?page=[0-9]+$") {
  #  set req.url = regsub(req.url, "node(\?page=[0-9]+$)", "\1");
  #  return (lookup);
  #}

  # Do not cache these paths.
  if (req.url ~ "^/status\.php$" ||
      req.url ~ "^/update\.php$" ||
      req.url ~ "^/ooyala/ping$" ||
      req.url ~ "^/admin" ||
      req.url ~ "^/admin/.*$" ||
      req.url ~ "^/user" ||
      req.url ~ "^/user/.*$" ||
      req.url ~ "^/users/.*$" ||
      req.url ~ "^/info/.*$" ||
      req.url ~ "^/flag/.*$" ||
      req.url ~ "^.*/ajax/.*$" ||
      req.url ~ "^.*/ahah/.*$") {
    return (pass);
  }

  # Pipe these paths directly to Apache for streaming.
  if (req.url ~ "^/admin/content/backup_migrate/export") {
    return (pipe);
  }

  # Do not allow outside access to cron.php or install.php.
  if (req.url ~ "^/(cron|install)\.php$" && !client.ip ~ internal) {
    # Have Varnish throw the error directly.
    error 404 "Page not found.";
    # Use a custom error page that you've defined in Drupal at the path "404".
    # set req.url = "/404";
  }

  # Handle compression correctly. Different browsers send different
  # "Accept-Encoding" headers, even though they mostly all support the same
  # compression mechanisms. By consolidating these compression headers into
  # a consistent format, we can reduce the size of the cache and get more hits.=
  # @see: http:// varnish.projects.linpro.no/wiki/FAQ/Compression
  if (req.http.Accept-Encoding) {
    if (req.http.Accept-Encoding ~ "gzip") {
      # If the browser supports it, we'll use gzip.
      set req.http.Accept-Encoding = "gzip";
    }
    else if (req.http.Accept-Encoding ~ "deflate") {
      # Next, try deflate if it is supported.
      set req.http.Accept-Encoding = "deflate";
    }
    else {
      # Unknown algorithm. Remove it and send unencoded.
      unset req.http.Accept-Encoding;
    }
  }

  # Always cache the following file types for all users.
  if (req.url ~ "(?i)\.(png|gif|jpeg|jpg|ico|swf|css|js)(\?[a-z0-9]+)?$") {
    unset req.http.Cookie;
  }

  # Remove all cookies that Drupal doesn't need to know about. ANY remaining
  # cookie will cause the request to pass-through to a backend. For the most part
  # we always set the NO_CACHE cookie after any POST request, disabling the
  # Varnish cache temporarily. The session cookie allows all authenticated users
  # to pass through as long as they're logged in.
  #
  # 1. Append a semi-colon to the front of the cookie string.
  # 2. Remove all spaces that appear after semi-colons.
  # 3. Match the cookies we want to keep, adding the space we removed
  #    previously, back. (\1) is first matching group in the regsuball.
  # 4. Remove all other cookies, identifying them by the fact that they have
  #    no space after the preceding semi-colon.
  # 5. Remove all spaces and semi-colons from the beginning and end of the
  #    cookie string.
  if (req.http.Cookie) {
    set req.http.Cookie = ";" + req.http.Cookie;
    set req.http.Cookie = regsuball(req.http.Cookie, "; +", ";");
    set req.http.Cookie = regsuball(req.http.Cookie, ";(S{1,2}ESS[a-z0-9]+|NO_CACHE)=", "; \1=");
    set req.http.Cookie = regsuball(req.http.Cookie, ";[^ ][^;]*", "");
    set req.http.Cookie = regsuball(req.http.Cookie, "^[; ]+|[; ]+$", "");

    if (req.http.Cookie == "") {
      # If there are no remaining cookies, remove the cookie header. If there
      # aren't any cookie headers, Varnish's default behavior will be to cache
      # the page.
      unset req.http.Cookie;
    }
    else {
      # If there is any cookies left (a session or NO_CACHE cookie), do not
      # cache the page. Pass it on to Apache directly.
      return (pass);
    }
  }

  ## From default below ##
  if (req.restarts == 0) {
    if (req.http.X-Forwarded-For) {
      set req.http.X-Forwarded-For = req.http.X-Forwarded-For + ", " + client.ip;
    } else {
      set req.http.X-Forwarded-For = client.ip;
    }
  }

  if (req.request != "GET" &&
    req.request != "HEAD" &&
    req.request != "PUT" &&
    req.request != "POST" &&
    req.request != "TRACE" &&
    req.request != "OPTIONS" &&
    req.request != "DELETE") {
      /* Non-RFC2616 or CONNECT which is weird. */
      return (pipe);
  }

  if (req.request != "GET" && req.request != "HEAD") {
      /* We only deal with GET and HEAD by default */
      return (pass);
  }

  ## Unset Authorization header if it has the correct details...
  #if (req.http.Authorization == "Basic ") {
  #  unset req.http.Authorization;
  #}

  if (req.http.Authorization || req.http.Cookie) {
      /* Not cacheable by default */
      return (pass);
  }
  return (lookup);
}

# Routine used to determine the cache key if storing/retrieving a cached page.
sub vcl_hash {
  # Include cookie in cache hash.
  # This check is unnecessary because we already pass on all cookies.
  # if (req.http.Cookie) {
  #   set req.hash += req.http.Cookie;
  # }

  # Cache also per User-Agent
  # if (req.url ~ "^/stylesheets/browser_specific.css") {
  #  set req.hash += req.http.User-Agent
  # }
}

# Code determining what to do when serving items from the Apache servers.
sub vcl_fetch {
  # Don't allow static files to set cookies.
  if (req.url ~ "(?i)\.(png|gif|jpeg|jpg|ico|swf|css|js)(\?[a-z0-9]+)?$") {
    # beresp == Back-end response from the web server.
    unset beresp.http.set-cookie;
  }
  else if (beresp.http.Cache-Control) {
    unset beresp.http.Expires;
  }
  #if (beresp.status == 301) {
  #  set beresp.ttl = 1h;
  #  return(deliver);
  #}

  ## Doesn't seem to work as expected
  #if (beresp.status == 500) {
  #  set beresp.saintmode = 10s;
  #  return(restart);
  #}

  # Allow items to be stale if needed.
  set beresp.grace = 1h;
}

# Set a header to track a cache HIT/MISS.
sub vcl_deliver {
  if (obj.hits > 0) {
    set resp.http.X-Varnish-Cache = "HIT";
  }
  else {
    set resp.http.X-Varnish-Cache = "MISS";
  }
}

sub vcl_hit {
  if (req.request == "PURGE") {
    purge;
    error 200 "Varnish cache has been purged for this object";
  }
}

sub vcl_miss {
  if (req.request == "PURGE") {
    purge;
    error 404 "Object not in cache";
  }
}

# In the event of an error, show friendlier messages.
sub vcl_error {
     set obj.http.Content-Type = "text/html; charset=utf-8";
     set obj.http.Retry-After = "15";
     synthetic {"
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
  <head>
    <title>"} + obj.status + " " + obj.response + {"</title>
    <style>
      body { background: #303030; text-align: center; color: white; }
      #page { border: 1px solid #CCC; width: 500px; margin: 100px auto 0; padding: 30px; background: #323232; }
      a, a:link, a:visited { color: #CCC; }
      .error { color: #222; }
    </style>
   </head>
   <body onload="setTimeout(function() { window.location = '/' }, 15000)">
     <div id="page">
       <h1 class="title">Varnish status page</h1>
       <p>The requested page has been intercepted by the cache server due to an abnormal condition.</p>
       <p>We're redirecting you to the <a href="/">homepage</a> in 15 seconds.</p>
       <div class="error">(Error "} + obj.status + " " + obj.response + {")</div>
       <strong>Guru Meditation</strong> XID: "} + req.xid + {"
       <hr />
       <p>Generated by Varnish cache server for URL: http://"} + req.http.host + req.url + {"</p>
     </div>
   </body>
</html>
"};
     return (deliver);
}