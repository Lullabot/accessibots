<?php
?>
<article class="<?php print $id_node . $classes; ?>" <?php print $attributes; ?> role="article">
  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
  <footer>
    <?php print render($content['field_publication_date']); ?>
    <span class="author"><?php print t('Posted by'); ?> <?php print $name; ?></span>
  </footer>
  <?php endif; ?>

  <div class="content">
    <?php print render($content);?>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>
</article>
