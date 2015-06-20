<?php
  hide($content['links']);
?>
<article class="teaser teaser__tool" role="article">
  <div class="tool__image">
    <?php print render($content['field_image']); ?>

    <div class="tool__cost">
      <?php
      if(!empty($content['field_cost'])){
        print '$' . render($content['field_cost']);
      }
      else {
        print 'Free';
      }
      ?>
    </div>
  </div>

  <div class="tool__details">
    <div class="tool__title">
      <?php print render($content['field_resource_url']); ?>
    </div>

    <div class="tool__platforms">
      <?php print render($content['field_platform']); ?>
    </div>

    <div class="tool__description">
      <?php print render($content['body']); ?>
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

  </div>
</article>
