<?php
/**
 * Migrates additional resources - file
 *
 * Set hwc_migration_highlights_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesFileMigration extends NCWFileMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesFileSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'file';
    $this->description = 'Import additional files from NCW';
  }
}

/**
 * Migrates additional resources - infographic
 *
 * Set hwc_migration_infographic_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesInfographicsMigration extends NCWInfographicsMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesInfographicsSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'infographic';
    $this->description = 'Import additional infographic from NCW';
  }
}

/**
 * Migrates additional resources - youtube
 *
 * Set hwc_migration_youtube_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesYoutubeMigration extends NCWYoutubeMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesYoutubeSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'youtube';
    $this->description = 'Import additional youtube from NCW';
  }
}

/**
 * Migrates additional resources - slideshare
 *
 * Set hwc_migration_highlights_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesSlideshareMigration extends NCWSlideshareMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesSlideshareSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'slideshare';
    $this->description = 'Import additional slideshares from NCW';
  }
}

/**
 * Migrates additional resources - highlights
 *
 * Set hwc_migration_highlights_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesHighlightsMigration extends NCWHighlightMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesNewsSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'highlight';
    $this->description = 'Import additional highlights (into news) from NCW';
  }
}

/**
 * Migrates additional resources - news
 *
 * Set hwc_migration_events_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesNewsMigration extends NCWNewsMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesNewsSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'news';
    $this->description = 'Import additional highlights (into news) from NCW';
  }
}

/**
 * Migrates additional resources - press_release
 *
 * Set hwc_migration_press_releases_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesPressReleasesMigration extends NCWPressMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesPressReleasesSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'press_release';
    $this->description = 'Import additional press releases from NCW';
  }
}

/**
 * Migrates additional resources - publication
 *
 * Set hwc_migration_publications_add_res_url variable for explicit source URL.
 */
class NCWAdditionalResourcesPublicationsMigration extends NCWPublicationsMigration {

  public function __construct($arguments) {
    $arguments['source_klass'] = 'NCWAdditionalResourcesPublicationsSource';
    parent::__construct($arguments);
    /** @var NCWAdditionalResourcesBaseSource content_type */
    $this->source->content_type = 'publication';
    $this->description = 'Import additional publications from NCW';
  }
}

abstract class NCWAdditionalResourcesBaseSource extends AbstractNCWNodeSource {

  public $content_type = NULL;

  /**
   * Source node ids.
   */
  public function getSourceIds() {
    return $this->source_ids;
  }

  /**
   * Total number of entities.
   */
  public function computeCount() {
    $skip_name = variable_get('hwc_migration_exclude_tag_name', 'Campaign 2020-2022');
    ncw_migration_debug('!klass: Starting counting !url', array(
      '!klass' => get_class($this),
      '!url' => $this->endpoint_url
    ));
    if ($this->count == -1) {
      $data = $this->fileGetContents($this->endpoint_url);
      $this->count = 0;
      if ($data = json_decode($data)) {
        foreach ($data->items as $row) {
          if (strpos('.' . $row->item->field_tags, $skip_name)) {
            continue;
          }
          if ($row->item->type == $this->content_type) {
            $this->count++;
          }
        }
      }
    }
    ncw_migration_debug('!klass: Found !count items', array(
      '!klass' => get_class($this),
      '!count' => $this->count
    ));
    return $this->count;
  }

  /**
   * Remote call to load the data from the endpoint URL
   */
  public function readData() {
    $skip_name = variable_get('hwc_migration_exclude_tag_name', 'Campaign 2020-2022');
    $msg = format_string('Updating from !url', array('!url' => $this->endpoint_url));
    watchdog('ncw_migration', $msg, []);
    ncw_migration_debug('!klass: Starting reading items from !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      ncw_migration_debug('!klass:      * Processing !count items', array('!klass' => get_class($this), '!count' => count($data->items)));
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        if (strpos('.' . $ob->field_tags, $skip_name)) {
          continue;
        }
        if ($ob->type == $this->content_type) {
          $id = $this->itemIdentifier($ob);
          $node_url = $this->itemURL($id);
          ncw_migration_debug('!klass:      * Reading item: !url', array(
            '!klass' => get_class($this),
            '!url' => $node_url
          ));
          if ($rowd = $this->fileGetContents($node_url)) {
            if ($row_ob = json_decode($rowd, TRUE)) {
              $row = new stdClass();
              foreach ($row_ob as $k => $v) {
                $row->$k = $v;
              }
              $this->rows[$id] = $row;
            }
          }
          else {
            $msg = format_string('Failed to read data from !url', array('!url' => $node_url));
            watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
            $this->rows[$id] = NULL;
          }
        }
      }
    }
    else {
      $msg = format_string('Failed to read data from !url', array('!url' => $this->endpoint_url));
      watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
      throw new MigrateException($msg, Migration::MESSAGE_ERROR);
    }
    ncw_migration_debug('!klass: Done reading items', array('!klass' => get_class($this)));
    reset($this->rows);
  }
}

class NCWAdditionalResourcesNewsSource extends NCWAdditionalResourcesBaseSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_image',
      'field_image_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'field_expiration_date',
      'field_expiration_date_timezone',
      'field_expiration_date_value2',
      'field_tags',
      'field_archived',
      'field_character_count',
      'field_page_count',
    );
    return array_combine($fields, $fields);
  }
}

class NCWAdditionalResourcesPressReleasesSource extends NCWAdditionalResourcesBaseSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_image_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'field_pr_embargo_date',
      'field_pr_embargo_date_timezone',
      'field_pr_embargo_date_value2',
      'field_expiration_date',
      'field_expiration_date_timezone',
      'field_expiration_date_value2',
      'field_image',
      'field_quote',
      'field_quote_format',
      'field_quote_language',
      'field_tags',
      'field_archived',
      'field_character_count',
      'field_page_count',
      //@todo: 'field_pr_notes_to_editor' - recursive! :-(
      //@todo: 'field_aditional_resources' - recursive! :-(
    );
    return array_combine($fields, $fields);
  }
}

class NCWAdditionalResourcesPublicationsSource extends NCWAdditionalResourcesBaseSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_archived',
      'field_author',
      'field_author_language',
      'field_character_count',
      'field_cover_image',
      'field_cover_image_language',
      'field_file',
      'field_file_language',
      'field_expiration_date',
      'field_expiration_date_timezone',
      'field_expiration_date_value2',
      'field_page_count',
      'field_publication_bookshop_id',
      'field_publication_bookshop_id_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'field_publication_related_res',
      'field_publication_related_res_language',
      'field_publication_type',
      'field_tags',
      'field_related_publications',
      //@todo: 'field_aditional_resources' - recursive! :-(
    );
    return array_combine($fields, $fields);
  }

  /**
   * Include the related publications recursively into the migrated content.
   */
  public function readData() {
    $skip_name = variable_get('hwc_migration_exclude_tag_name', 'Campaign 2020-2022');
    $msg = format_string('Updating from !url', array('!url' => $this->endpoint_url));
    watchdog('ncw_migration', $msg, []);
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        if (strpos('.' . $ob->field_tags, $skip_name)) {
          continue;
        }
        if ($ob->type == $this->content_type) {
          $id = $this->itemIdentifier($ob);
          $node_url = $this->itemURL($id);
          if ($rowd = $this->fileGetContents($node_url)) {
            if ($row_ob = json_decode($rowd, TRUE)) {
              $row = new stdClass();
              foreach ($row_ob as $k => $v) {
                $row->$k = $v;
              }
              $this->rows[$id] = $row;
              $this->children_recursive_publications($row);
            }
          }
          else {
            if ($this->activeMigration) {
              $this->activeMigration->saveMessage(format_string('Failed to read data from !url', array('!url' => $node_url)));
            }
          }
        }
      }
    }
    reset($this->rows);
  }

  protected function children_recursive_publications($row) {
    // Check the field_related_publications for children and add to source
    $tmp = new stdClass();
    $tmp->field_related_publications = $row->field_related_publications;
    $firp = field_info_field('field_related_publications');
    osha_migration_normalize_field_entityreference($tmp, 'field_related_publications', $firp);
    foreach($tmp->field_related_publications as $cid) {
      // Skip records already added
      if (array_key_exists($cid, $this->rows)) {
        continue;
      }
      $child_url = $this->itemURL($cid);
      if ($child_rowd = $this->fileGetContents($child_url)) {
        if ($child_row_ob = json_decode($child_rowd, TRUE)) {
          $child_row = new stdClass();
          foreach ($child_row_ob as $k => $v) { $child_row->$k = $v; }
          $this->rows[$cid] = $child_row;
          $this->children_recursive_publications($child_row);
        }
      }
    }
  }
}

class NCWAdditionalResourcesFileSource extends NCWAdditionalResourcesBaseSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_file',
      'field_file_language',
    );
    return array_combine($fields, $fields);
  }
}

class NCWAdditionalResourcesSlideshareSource extends NCWAdditionalResourcesBaseSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_slideshare',
      'field_slideshare_slide_id',
      'field_tags',
      'field_character_count',
      'field_page_count',
    );
    return array_combine($fields, $fields);
  }
}

class NCWAdditionalResourcesInfographicsSource extends NCWAdditionalResourcesBaseSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_tags',
      'field_image',
      'field_image_language',
      'field_thumbnail',
      'field_thumbnail_language',
      'field_file',
      'field_file_language',
      'field_twin_infographics',
      'field_migration_path_alias',
    );
    return array_combine($fields, $fields);
  }
}

class NCWAdditionalResourcesYoutubeSource extends NCWAdditionalResourcesBaseSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_youtube',
      'field_migration_path_alias',
      'field_character_count',
      'field_page_count',
    );
    return array_combine($fields, $fields);
  }
}
