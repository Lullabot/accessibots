<?php
  hide($content['links']);
?>
<article class="news teaser" role="article">
  <?php print render($content['field_primary_image']); ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <?php print render($content['field_publication_date']); ?>
    <span class="author"><?php print t('Posted by'); ?> <?php print $name; ?></span>
  <?php endif; ?>
</article>
