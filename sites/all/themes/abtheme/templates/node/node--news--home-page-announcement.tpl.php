<?php
//kpr($variables);
?>
<div id="siteinfo" style="background-image: url('<?php print $background_image_path; ?>');">
  <article id="lead-story" role="article">
    <figure>
      <?php print render($content['field_primary_image']); ?>
    </figure>

    <?php print render($title_prefix); ?>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php print render($title_suffix); ?>

    <?php print render($content['body']); ?>
  </article>
</div>
<div class="header-badge">
  <img src="<?php print base_path() . $directory; ?>/images/badge.png" alt="The Accessibots" />
</div>