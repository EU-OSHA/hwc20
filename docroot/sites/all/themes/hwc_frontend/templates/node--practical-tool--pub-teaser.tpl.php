<?php
/** @var array $variables */
$content = $variables['content'];
$node = $variables['node'];
$view = node_view($node, 'teaser');
?>
<div class="practical-tool-item">
  <?php print render($view); ?>
</div>
