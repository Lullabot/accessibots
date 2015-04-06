<!doctype html>

<!--[if IE 7]>    <html class="no-js ie7 oldie" lang="<?php print $language->language; ?>" <?php print $rdf_namespaces; ?> <?php print $html_attributes; ?>> <![endif]-->
<!--[if IE 8]>    <html class="no-js ie8 oldie" lang="<?php print $language->language; ?>" <?php print $rdf_namespaces; ?> <?php print $html_attributes; ?>> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang="<?php print $language->language; ?>" <?php print $rdf_namespaces; ?> <?php print $html_attributes; ?>> <!--<![endif]-->
<?php print $mothership_poorthemers_helper; ?>
<head>
<title><?php print $head_title; ?></title>
<?php print $head; ?>
  <meta name="mobile-web-app-capable" content="yes">
<link rel="apple-touch-icon" href="<?php print base_path() . $directory; ?>/images/icons/badge/ios/AppIcon.appiconset/Icon-60@2x.png" />
<link rel="apple-touch-icon" sizes="180x180" href="<?php print base_path() . $directory; ?>/images/icons/badge/ios/AppIcon.appiconset/Icon-60@3x.png" />
<link rel="apple-touch-icon" sizes="76x76" href="<?php print base_path() . $directory; ?>/images/icons/badge/ios/AppIcon.appiconset/Icon-76.png" />
<link rel="apple-touch-icon" sizes="152x152" href="<?php print base_path() . $directory; ?>/images/icons/badge/ios/AppIcon.appiconset/Icon-76@2x.png" />
<link rel="apple-touch-icon" sizes="58x58" href="<?php print base_path() . $directory; ?>/images/icons/badge/ios/AppIcon.appiconset/Icon-Small@2x.png" />
  <link rel="icon" sizes="192x192" type="image/png" href="<?php print base_path() . $directory; ?>/images/icons/lilly/lilly_192.png">
  <link rel="icon" sizes="128x128" type="image/png" href="<?php print base_path() . $directory; ?>/images/icons/lilly/lilly_128.png">

  <?php if(theme_get_setting('mothership_mobile')){  ?>
<meta name="MobileOptimized" content="width">
<meta name="HandheldFriendly" content="true"><?php } ?>
<?php if(theme_get_setting('mothership_viewport')){  ?><meta name="viewport" content="width=device-width, initial-scale=1"><?php } ?>
<?php if(theme_get_setting('mothership_viewport_maximumscale')){  ?><meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0"><?php } ?>
<meta http-equiv="cleartype" content="on">
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
  <link href='http://fonts.googleapis.com/css?family=Arvo:400,700,400italic|Raleway:400,700' rel='stylesheet' type='text/css' />
<?php print $styles; ?>
<?php if(theme_get_setting('mothership_respondjs')) { ?>
<!--[if lt IE 9]>
  <script src="<?php print $mothership_path; ?>/js/respond.min.js"></script>
<![endif]-->
<?php } ?>
<!--[if lt IE 9]>
  <script src="<?php print $mothership_path; ?>/js/html5.js"></script>
<![endif]-->
<?php print $selectivizr; ?>
<?php
  if(!theme_get_setting('mothership_script_place_footer')) {
    print $scripts;
  }
?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
<?php print $page_top; //stuff from modules always render first ?>
<?php print $page; // uses the page.tpl ?>
<?php
  if(theme_get_setting('mothership_script_place_footer')) {
    print $scripts;
  }
?>
<?php print $page_bottom; //stuff from modules always render last ?>
</body>
</html>

