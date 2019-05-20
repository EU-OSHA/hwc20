#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

# Get the full path to the directory containing this script.
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd "$SCRIPT_DIR/docroot"

db_en=`drush --exact --format=string vget environment`
# Avoid dropping non-local environments
if [ "$?" == 0 ] && [ "$db_en" != 'development' ]; then
  echo -e "${RED}Refusing to drop non-development db instance, use «drush vset environment local»' to override${WHITE}\n";
  exit -1
fi

drush sql-drop -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Error cleaning database"
  exit ${ecode};
fi

# Sync from staging
drush downsync_sql @staging @self -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "downsync_sql has returned an error"
  exit ${ecode};
fi

if [ ! -z "$pre_update" ]; then
  echo "Run pre update"
  ../$pre_update
fi

drush devify --yes
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify has returned an error"
  exit ${ecode};
fi

drush devify_solr
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify Solr has returned an error"
  exit ${ecode};
fi

drush updatedb -y
if [ ${ecode} != 0 ]; then
  echo "updatedb has returned an error"
  exit ${ecode};
fi

drush devify_ldap
if [ ${ecode} != 0 ]; then
  echo "devify_ldap has returned an error"
  exit ${ecode};
fi

if [ ! -z "$files" ]; then
echo "Run drush rsync"
drush -y rsync @staging:%files @self:%files
fi

if [ ! -z "$post_update" ]; then
  echo "Run post update"
  ../$post_update
  drush cc all
fi

# Set the environment to development
drush vset environment development