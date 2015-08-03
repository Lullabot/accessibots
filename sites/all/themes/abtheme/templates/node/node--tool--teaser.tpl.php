<?php
  hide($content['links']);
?>
<article <?php print drupal_attributes($attributes_array); ?>>
  <div class="tool__image">
    <?php print render($content['field_image']); ?>
  </div>

  <header>
    <h2 class="tool__title">
      <?php print render($content['field_resource_url']); ?>
    </h2>
    <em class="tool__cost">
      <?php print !empty($content['field_cost']) ? render($content['field_cost']) : t('Free'); ?>
    </em>
  </header>

  <?php print render($content); ?>
</article>
