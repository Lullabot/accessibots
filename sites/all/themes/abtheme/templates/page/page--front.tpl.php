<?php
//dpm($variables);
?>
<header id="site-header" role="banner">
  <nav id="main-nav" role="navigation">
    <div class="js-nav-toggle-wrapper">
      <button class="js-nav-toggle">
        <span>Open menu</span>
      </button>
    </div>
    <?php print render($main_menu); ?>
  </nav>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h1><?php print $title; ?></h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php print render($page['home_page_intro']); ?>

  <img src="<?php print $base_path . $directory; ?>/images/badge.png" alt="The Accessibots" />
</header>

<?php print render($page['content']); ?>

<?php include_once "_footer.tpl.php"; ?>
