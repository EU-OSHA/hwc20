<h2><?php echo t('Frequently asked questions'); ?></h2>
<?php
$entities_to_load = array();
foreach ($items as $item) {
  $entities_to_load[] = $item['value'];
}
$entities = entity_load('field_collection_item', $entities_to_load);
$in = 'in';
?>
  <div class="panel-group" id="faq">
    <?php foreach ($entities as $key => $entity) {
      //todo check lang...
      $question = $entity->field_question['und'][0]['safe_value'];
      $answer = $entity->field_answer['und'][0]['value'];
      ?>
      <div class="panel panel-default">
        <div class="panel-heading">
          <h3 class="panel-title">
            <a data-toggle="collapse" data-parent="#faq" href="#collapse<?php echo $key ?>"><?php echo $question; ?></a>
          </h3>
        </div>
        <div id="collapse<?php echo $key ?>" class="panel-collapse collapse <?php echo $in; ?>">
          <div class="panel-body"><?php echo $answer; ?></div>
        </div>
      </div>
    <?php
      $in = '';
    } ?>
  </div>
