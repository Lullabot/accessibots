<?php
  hide($content['links']);
?>
<article <?php print drupal_attributes($attributes_array); ?>>
  <?php print render($content['field_primary_image']); ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php print render($content['field_cost']); ?>

  <?php print render($content); ?>
</article>
