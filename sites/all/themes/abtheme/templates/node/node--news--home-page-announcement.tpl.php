<?php
?>
<div id="siteinfo" style="background-image: url('<?php print $background_image_path; ?>');">
  <figure>
    <?php print render($content['field_primary_image']); ?>
  </figure>
  <article id="lead-story">
    <?php print render($title_prefix); ?>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php print render($title_suffix); ?>

    <?php print render($content['body']); ?>
  </article>
</div>
