<?php
?>
<header role="banner">
  <nav id="main-nav" role="navigation">
    <?php print render($main_menu); ?>
  </nav>
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
