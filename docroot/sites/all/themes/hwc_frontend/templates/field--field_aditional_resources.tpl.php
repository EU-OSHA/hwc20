<?php

// Render a mini panel instead of field.
ctools_include('context');
$panel_mini = panels_mini_load('additional_resources');
$context = new StdClass();
$context->type = 'node';
$context->data = menu_get_object();
$contexts =  array($context);
$context = ctools_context_match_required_contexts($panel_mini->requiredcontexts, $contexts);
$panel_mini->context = $panel_mini->display->context = ctools_context_load_contexts($panel_mini, FALSE, $context);
$pane = panels_render_display($panel_mini->display);

?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?></div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php print $pane;?>
  </div>
</div>