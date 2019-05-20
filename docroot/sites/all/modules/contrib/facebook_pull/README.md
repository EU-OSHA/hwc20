# Facebook-Pull 7.x-3.x
Drupal Module: https://www.drupal.org/project/facebook_pull

<div class="field-item even"><p><em>Facebook Pull</em> is a fast and efficient module for displaying Facebook feeds on your site.</p>
<p>This module caches all queries to the graph, the time period default is 20 minutes.</p>
<h3>Usage</h3>
<p>Configure the module then add the block, or <a href="/project/boxes" rel="nofollow">box</a>, or use the API directly:<br></p><div class="codeblock"><pre><code>&lt;?php<br>echo facebook_pull_render($graph_id, $type, $app_id, $app_secret, $options);<br>?&gt;</code></pre></div>
<p>You must obtain an app_id and app_secret from Facebook before you can use this module. You can do this through the <a href="https://www.facebook.com/developers/createapp.php" rel="nofollow">Developer App</a> on Facebook.</p>
<p>You can configure this module at: "admin/config/services/facebook-pull"</p>

<p>More information about the facebook Graph API, the API which this module interfaces with, is available on the Facebook website:<br><a href="https://developers.facebook.com/docs/graph-api/reference/" rel="nofollow">https://developers.facebook.com/docs/graph-api/reference/</a></p>

<h3>Credits</h3>
<p>This module is currently maintained by @daveferrara1.</p>
</div>
