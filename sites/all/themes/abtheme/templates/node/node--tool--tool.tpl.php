<?php
  hide($content['links']);
?>
<article class="tool" role="article">
  <div class="tool__image">
    <?php print render($content['field_image']); ?>
  </div>

  <header>
    <h2 class="tool__title">
      <?php print render($content['field_resource_url']); ?>
    </h2>
    <em class="tool__cost">
      <?php print !empty($content['field_cost']) ? '$' . render($content['field_cost']) : t('Free'); ?>
    </em>
  </header>

  <div class="tool__description">
    <?php print render($content['body']); ?>
  </div>

  <div class="tool__platforms">
    <?php print render($content['field_platform']); ?>
  </div>

  <div class="tool__category">
    <span class="tool__category-label">Use for: </span>
    <?php print render($content['field_category']); ?>
  </div>

  <a href="<?php print($content['field_author']['#items'][0]['url']); ?>" title="Visit <?php print($content['field_author']['#items'][0]['title']); ?>">
    <div class="tool__author">
      <span class="tool__author-intro"> Made by </span>
      <?php print render($content['field_author']); ?>
    </div>
  </a>
</article>
