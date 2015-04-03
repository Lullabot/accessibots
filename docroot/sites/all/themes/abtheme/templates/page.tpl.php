<?php
  //kpr(get_defined_vars());
?>
<header role="banner">
  <nav id="main-nav" role="navigation">
    <?php print render($main_menu); ?>
  </nav>
  <div id="siteinfo">
    <figure>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
        <img src="<?php print base_path() . $directory; ?>/images/badge.png" alt="<?php print t('Accessibots badge logo.'); ?>" />
      </a>
    </figure>
    <article id="lead-story">
      <h2>Look Out, Orlando!</h2>
      <p>The Accessibots are coming to Florida DrupalCamp to give you a lesson on accessibility!</p>
      <p>April 10-12, 2015</p>
    </article>
  </div>
</header>

<div class="page">
  <div role="main" id="main-content">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <h1><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($messages){ ?>
      <div class="drupal-messages">
        <?php print $messages; ?>
      </div>
    <?php } ?>

    <?php if ($action_links): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>

    <?php print render($page['content']); ?>
  </div><!-- /main -->
</div><!-- /page -->

<footer role="contentinfo">

</footer>

