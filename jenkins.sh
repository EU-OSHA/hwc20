#!/bin/bash

# Go to docroot/
cd docroot/
# Drupal breaks permissions for sites/default and jenkins fails
chmod u+w sites/default

# Drop all tables (including non-drupal)
drush sql-drop -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Error cleaning database"
  exit ${ecode};
fi

# Sync from edw staging
drush downsync_sql @hwc.staging @self -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "downsync_sql has returned an error"
  exit ${ecode};
fi

# Devify the installation
drush -y devify
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify has returned an error"
  exit ${ecode};
fi

# Devify the installation
drush devify_solr
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify Solr has returned an error"
  exit ${ecode};
fi

# Build the site
drush osha_build -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "osha_build has returned an error"
  exit ${ecode};
fi

drush fl | grep -i overridden > /dev/null 2>&1
c=$?
if [ ${c} == 0 ]; then
  echo "Found overriden features after rebuild, failing ..."
  exit -1
fi
