<?php
?>
<header id="site-header" role="banner">
  <nav id="main-nav" role="navigation">
    <?php print render($main_menu); ?>
  </nav>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h1><?php print $title; ?></h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
</header>

<?php print render($page['content']); ?>

<?php include_once "_footer.tpl.php"; ?>
