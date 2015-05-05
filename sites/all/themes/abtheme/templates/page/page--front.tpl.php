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
      <h2>You're Next, LA!</h2>
      <p>We don't have a session at DrupalCon LA, but we'll be BOFing it up! Come talk accessibility with us!</p>
      <p>May 11 - 15, 2015</p>
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

<?php include_once "_footer.tpl.php"; ?>
