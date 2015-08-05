<?php
//kpr($variables);
?>
<article id="lead-story" role="article" style="background-image: url('<?php print $background_image_path; ?>');">
  <div class="inner">
    <figure>
      <?php print render($content['field_primary_image']); ?>
    </figure>

    <div class="col2">
      <?php print render($title_prefix); ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <?php print render($title_suffix); ?>

      <?php print render($content['body']); ?>
    </div>
  </div>
</article>
