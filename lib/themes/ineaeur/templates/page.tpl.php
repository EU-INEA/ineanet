<?php

/**
 * @file
 * Ec_resp's theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system folder.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/ec_resp.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 * - $menu_visible: Checking if the main menu is available in the
 *    region featured
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header_top']: Displayed at the top line of the header
 *    -> language switcher, links, ...
 * - $page['header_right']: Displayed in the right part of the header
 *    -> logo, search box, ...
 * - $page['featured']: Displayed below the header, take full width of screen
 *    -> main menu, global information, ...
 * - $page['tools']: Displayed on top right of content area
 *    -> login/logout buttons, author information, ...
 * - $page['sidebar_left']: Small sidebar displayed on left of the content
 *    -> navigation, pictures, ...
 * - $page['sidebar_right']: Small sidebar displayed on right of the content
 *    -> latest content, calendar, ...
 * - $page['content_top']: Displayed in middle column
 *    -> carousel, important news, ...
 * - $page['help']: Displayed between page title and content
 *    -> information about the page, contextual help, ...
 * - $page['content']: The main content of the current page.
 * - $page['content_right']: Large sidebar displayed on right of the content
 *    -> 2 column layout
 * - $page['content_bottom']: Displayed below the content, in middle column
 *    -> print button, share tools, ...
 * - $page['footer']: Displayed at bottom of the page, on full width
 *    -> latest update, copyright, ...
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see ec_resp_process_page()
 */
?>

<?php
global $base_url;
?>

<a id="top-page"></a>

<!-- <div class="container">
    <?php /*print $regions['header_top']; */ ?>
  </div>-->

<header class="ecl-site-header" role="banner">

    <div class="ecl-container">

      <?php if ($logged_in): ?>
        <nav class="ecl-navigation-list-wrapper ecl-u-f-r">
            <h2 class="ecl-u-sr-only">User menu</h2>
            <ul class="ecl-navigation-list ecl-navigation-list--small">
                <li class="ecl-navigation-list__item">
                    <a class="ecl-navigation-list__link ecl-link" href="admin/workbench">My
                        workbench</a>
                </li>
                <li class="ecl-navigation-list__item">
                    <a class="ecl-navigation-list__link ecl-link" href="#">My
                        account</a>
                </li>
                <li class="ecl-navigation-list__item">
                    <a class="ecl-navigation-list__link ecl-link" href="ecas/logout">Log
                        out</a>
                </li>
            </ul>
        </nav>
      <?php endif; ?>
    </div>

    <div class="ecl-site-switcher ecl-site-switcher--header">
        <ul class="ecl-site-switcher__list ecl-container">
            <li class="ecl-site-switcher__option"><a
                        class="ecl-link ecl-site-switcher__link" href="#">Commission
                    and its
                    priorities</a></li>
            <li
                    class="ecl-site-switcher__option ecl-site-switcher__option--is-selected">
                <a class="ecl-link ecl-site-switcher__link" href="#">Policies,
                    information and services</a></li>
        </ul>
    </div>

    <div class="ecl-container ecl-site-header__banner">

        <a href="https://ec.europa.eu"
           class="ecl-logo ecl-logo--logotype ecl-site-header__logo"
           title="Home - European Commission">
           <span class="ecl-u-sr-only">Home - European Commission</span> 
        </a>
               <div class="ecl-language-list ecl-language-list--overlay ecl-site-header__language-list">

      <div id="ecl-overlay-language-list" class="ecl-dialog__overlay ecl-dialog__overlay--blue" aria-hidden="true"></div>

      <div class="ecl-lang-select-sites ecl-link" data-ecl-dialog="ecl-dialog" id="ecl-lang-select-sites__overlay">
        <a href="#" class="ecl-lang-select-sites__link">
    <span class="ecl-lang-select-sites__label">English</span>
    <span class="ecl-lang-select-sites__code">
      <span class="ecl-icon ecl-icon--language ecl-lang-select-sites__icon"></span>
      <span class="ecl-lang-select-sites__code-text">en</span>
    </span>
  </a>
      </div>

      <div class="ecl-dialog ecl-dialog--transparent ecl-dialog--wide" id="ecl-dialog" aria-labelledby="ecl-dialog-title" aria-describedby="ecl-dialog-description" aria-hidden="true" role="dialog">
        <h3 id="ecl-dialog-title" class="ecl-heading ecl-heading--h3 ecl-u-sr-only">Dialog</h3>
        <div class="ecl-dialog__body">
          <section>
            <div>
              <div class="ecl-container">
                <div class="ecl-row">
                  <div class="ecl-col-lg-8 ecl-offset-lg-2">
                    <h2 lang="en" class="ecl-heading ecl-heading--h2 ecl-dialog__title">
                      <span class="ecl-icon ecl-icon--generic-lang"></span> Select your language
                    </h2>
                    <div class="ecl-row">
                      <div class="ecl-col-md-6">

                        <a href="index_bg" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="bg" hreflang="bg" rel="alternate">български</a>

                        <a href="index_cs" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="cs" hreflang="cs" rel="alternate">čeština</a>

                        <a href="index_da" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="da" hreflang="da" rel="alternate">dansk</a>

                        <a href="index_de" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="de" hreflang="de" rel="alternate">Deutsch</a>

                        <a href="index_et" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="et" hreflang="et" rel="alternate">eesti</a>

                        <a href="index_el" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="el" hreflang="el" rel="alternate">ελληνικά</a>

                        <a href="index_en" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button ecl-language-list__button--active" lang="en" hreflang="en" rel="alternate">English<span class="ecl-icon ecl-icon--check ecl-u-f-r"></span></a>

                        <a href="index_es" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="es" hreflang="es" rel="alternate">español</a>

                        <a href="index_fr" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="fr" hreflang="fr" rel="alternate">français</a>

                        <a href="index_ga" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="ga" hreflang="ga" rel="alternate">Gaeilge</a>

                        <a href="index_hr" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="hr" hreflang="hr" rel="alternate">hrvatski</a>

                        <a href="index_it" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="it" hreflang="it" rel="alternate">italiano</a>
                      </div>
                      <div class="ecl-col-md-6">

                        <a href="index_lv" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="lv" hreflang="lv" rel="alternate">latviešu</a>

                        <a href="index_lt" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="lt" hreflang="lt" rel="alternate">lietuvių</a>

                        <a href="index_hu" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="hu" hreflang="hu" rel="alternate">magyar</a>

                        <a href="index_mt" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="mt" hreflang="mt" rel="alternate">Malti</a>

                        <a href="index_nl" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="nl" hreflang="nl" rel="alternate">Nederlands</a>

                        <a href="index_pl" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="pl" hreflang="pl" rel="alternate">polski</a>

                        <a href="index_pt" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="pt-pt" hreflang="pt" rel="alternate">português</a>

                        <a href="index_ro" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="ro" hreflang="ro" rel="alternate">română</a>

                        <a href="index_sk" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="sk" hreflang="sk" rel="alternate">slovenčina</a>

                        <a href="index_sl" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="sl" hreflang="sl" rel="alternate">slovenščina</a>

                        <a href="index_fi" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="fi" hreflang="fi" rel="alternate">suomi</a>

                        <a href="index_sv" class="ecl-button ecl-button--default ecl-button--block ecl-language-list__button" lang="sv" hreflang="sv" rel="alternate">svenska</a>
                      </div>
                      <button class="ecl-message__dismiss ecl-message__dismiss--inverted">Close</button>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </section>

        </div>

      </div>
    </div>
        
            <form action="http://ec.europa.eu/geninfo/query/index.do?" class="ecl-search-form ecl-site-header__search">
                <label class="ecl-search-form__textfield-wrapper">
                    <span class="ecl-u-sr-only">Search the Commission's websites</span>

                    <input
                            type="search"
                            class="ecl-text-input ecl-search-form__textfield"
                            id="global-search"
                            name="default-name"

                    />
                </label>

                <button class="ecl-button ecl-button--form ecl-search-form__button"
                        type="submit">Search
                </button>
            </form>
        </div>

        <div
                class="region-featured-wrapper <?php print ($has_responsive_sidebar ? 'sidebar-visible-sm' : ''); ?>">
          <?php if ($menu_visible || $has_responsive_sidebar): ?>
              <div class="mobile-user-bar navbar navbar-default visible-xs"
                   data-spy="affix" data-offset-top="82">
                  <div class="container">

                      <!-- Brand and toggle get grouped for better mobile display -->
                      <div class="navbar-header" data-spy="affix"
                           data-offset-top="165">
                        <?php if ($menu_visible): ?>
                            <button id="menu-button" type="button"
                                    class="navbar-toggle"
                                    data-toggle="collapse"
                                    data-target=".navbar-ex1-collapse">
                                <div class="arrow-down"></div>
                            </button>
                        <?php endif; ?>

                        <?php if ($has_responsive_sidebar): ?>
                            <div class="sidebar-button-wrapper">
                                <button class="sidebar-button">
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                </button>
                            </div>
                        <?php endif; ?>
                      </div>
                  </div><!-- /.container -->
              </div><!-- /.navbar -->
          <?php endif; ?>

          <?php print $regions['featured']; ?>

        </div>

      <?php if ($has_responsive_sidebar): ?>
          <div id="responsive-sidebar">
              <div id="responsive-header-right"></div>
              <div id="responsive-sidebar-left"></div>
              <div id="responsive-sidebar-right"></div>
          </div><!-- /#responsive-sidebar-->
      <?php endif; ?>

        <div id="layout-body" class="container">
            <div class="row">

                <div
                        class="col-lg-<?php print $cols['tools']['lg']; ?> col-md-<?php print $cols['tools']['md']; ?> col-sm-<?php print $cols['tools']['sm']; ?> col-xs-<?php print $cols['tools']['xs']; ?>">
                  <?php print $regions['tools']; ?>
                </div>
            </div>

          <?php if ($messages): ?>
              <div id="messages">
                <?php print $messages; ?>
              </div><!-- /#messages -->
          <?php endif; ?>

            <div class="row">
              <?php if ($regions['sidebar_left']): ?>
                  <div id="sidebar-left"
                       class="col-lg-<?php print ($cols['sidebar_left']['lg']); ?> col-md-<?php print ($cols['sidebar_left']['md']); ?> col-sm-<?php print ($cols['sidebar_left']['sm']); ?> col-xs-<?php print ($cols['sidebar_left']['xs']); ?> sidebar-left visible-lg visible-md">
                    <?php print $regions['sidebar_left']; ?>
                  </div>
              <?php endif; ?>

                <div id="content-wrapper"
                     class="col-lg-<?php print $cols['content_main']['lg']; ?> col-md-<?php print $cols['content_main']['md']; ?> col-sm-<?php print $cols['content_main']['sm']; ?> col-md-<?php print $cols['content_main']['xs']; ?>">

                    <a id="content"></a>

                  <?php print render($title_prefix); ?>

                  <?php if ($title): ?>
                      <h1
                              class="col-lg-<?php print $cols['title']['lg']; ?> col-md-<?php print $cols['title']['md']; ?> col-sm-<?php print $cols['title']['sm']; ?> col-xs-<?php print $cols['title']['xs']; ?> <?php print $page_type; ?>-title"
                              id="page-title">
                        <?php if ($title_image): ?>
                          <?php print $title_image; ?>
                        <?php endif; ?>
                        <?php print $title; ?>
                      </h1>
                  <?php endif; ?>

                  <?php print render($title_suffix); ?>

                  <?php print $regions['content_top']; ?>

                    <a id="main-content"></a>

                  <?php if ($tabs): ?>
                      <div class="tabs">
                        <?php print render($tabs); ?>
                      </div>
                  <?php endif; ?>

                  <?php print $regions['help']; ?>

                  <?php if ($action_links): ?>
                      <ul class="action-links">
                        <?php print render($action_links); ?>
                      </ul>
                  <?php endif; ?>

                    <div class="row">
                        <div
                                class="col-lg-<?php print $cols['content']['lg']; ?> col-md-<?php print $cols['content']['md']; ?> col-sm-<?php print $cols['content']['sm']; ?> col-xs-<?php print $cols['content']['xs']; ?>  <?php print $page_type; ?>">
                          <?php print $regions['content']; ?>
                        </div>

                        <div
                                class="col-lg-<?php print $cols['content_right']['lg']; ?> col-md-<?php print $cols['content_right']['md']; ?> col-sm-<?php print $cols['content_right']['sm']; ?> col-xs-<?php print $cols['content_right']['xs']; ?>">
                          <?php print $regions['content_right']; ?>
                        </div>
                    </div>

                  <?php print $feed_icons; ?>

                  <?php print $regions['content_bottom']; ?>
                </div>

                <div class="clearfix visible-sm visible-xs"></div>
              <?php if ($cols['sidebar_right']['md'] == 12): ?>
                  <div class="clearfix visible-md"></div>
              <?php endif; ?>

              <?php if ($regions['sidebar_right']): ?>
                  <div id="sidebar-right"
                       class="col-lg-<?php print ($cols['sidebar_right']['lg']); ?> col-md-<?php print ($cols['sidebar_right']['md']); ?> col-sm-<?php print ($cols['sidebar_right']['sm']); ?> col-xs-<?php print ($cols['sidebar_right']['xs']); ?> sidebar-right visible-lg visible-md">
                    <?php print $regions['sidebar_right']; ?>
                  </div>
              <?php endif; ?>
            </div>
            <div class="row">
              <?php if ($regions['site_bottom']): ?>
                  <div id="site-bottom"
                       class="col-lg-12 col-md-12 col-sm-12 col-xs-12 site-bottom visible-lg visible-md">
                    <?php print $regions['site_bottom']; ?>
                  </div>
              <?php endif; ?>
            </div>
        </div>
        <footer class="ecl-footer">
            <div class="ecl-footer__site-identity">
                <div class="ecl-container">
                    <div class="ecl-row">
                        <div class="ecl-col-sm ecl-footer__column"
                        <h4 class="ecl-h4">
                            <a class="ecl-link ecl-footer__link" href="/"><b>INEA
                                    Home</b></a>
                        </h4>
                    </div>
                    <div class="ecl-col-sm ecl-footer__column">

                        <p class="ecl-footer__label">Follow us: </p>
                        <p>
                        <ul class="ecl-footer__menu ecl-list--inline ecl-footer__social-links">
                            <li class="ecl-footer__menu-item">
                                <a class="ecl-link ecl-footer__link"
                                   href="https://www.linkedin.com/company/3034908/"><span
                                            class="ecl-icon ecl-icon--linkedin ecl-footer__social-icon"></span>LinkedIn</a>
                            </li>
                            <li class="ecl-footer__menu-item">
                                <a class="ecl-link ecl-footer__link"
                                   href="https://twitter.com/inea_eu"><span
                                            class="ecl-icon ecl-icon--twitter ecl-footer__social-icon"></span>Twitter</a>
                            </li>
                        </ul>
                        </p>
                    </div>
                    <!-- <div class="ecl-col-sm ecl-footer__column">-->

                    <!--  <li class="ecl-footer__menu-item">
                          <a class="ecl-link ecl-footer__link"
                             href="https://ec.europa.eu/commission/priorities/digital-single-market_en">Digital
                              single single
                              market</a>
                      </li>
                      <li class="ecl-footer__menu-item">
                          <a class="ecl-link ecl-footer__link"
                             href="https://ec.europa.eu/commission/priorities/energy-union-and-climate_en">Energy
                              union and climate</a>
                      </li>

                      </li>
                      <li class="ecl-footer__menu-item">
                          <a class="ecl-link ecl-footer__link"
                             href="https://ec.europa.eu/commission/priorities/jobs-growth-and-investment_en">Jobs,
                              growth and investment</a>
                      </li>-->

                    <!--</div>-->
                    <div class="ecl-col-sm ecl-footer__column">

                        <ul class="ecl-footer__menu ecl-list--unstyled">
                            <li class="ecl-footer__menu-item">
                                <a class="ecl-link ecl-footer__link"
                                   href="mission-objectives/contact-us">Contact</a>
                            </li>
                            <!-- <li class="ecl-footer__menu-item">
                                 <a class="ecl-link ecl-footer__link" href="#">Site
                                     map</a>
                             </li>-->

                        </ul>
                    </div>
                </div>
            </div>
            <div class="ecl-footer__site-corporate">
                <div class="ecl-container">
                    <div class="ecl-row">
                        <div class="ecl-col-sm ecl-footer__column">

                            <h4 class="ecl-h4 ecl-footer__title">European
                                Commission</h4>

                            <ul class="ecl-footer__menu">
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="https://ec.europa.eu/commission/index_en">Commission
                                        and its priorities</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="https://ec.europa.eu/info/index_en">Policies
                                        information and services</a>
                                </li>
                            </ul>
                        </div>
                        <div class="ecl-col-sm ecl-footer__column">

                            <h4 class="ecl-h4 ecl-footer__title">Follow the
                                European
                                Commission</h4>

                            <ul
                                    class="ecl-footer__menu ecl-list--inline ecl-footer__social-links">
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="#"><span
                                                class="ecl-icon ecl-icon--linkedin ecl-footer__social-icon"></span>LinkedIn</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="#"><span
                                                class="ecl-icon ecl-icon--twitter ecl-footer__social-icon"></span>Twitter</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link ecl-link--external"
                                       href="#">Other social media</a>
                                </li>
                            </ul>
                        </div>
                        <div class="ecl-col-sm ecl-footer__column">

                            <h4 class="ecl-h4 ecl-footer__title">European
                                Union</h4>

                            <ul class="ecl-footer__menu">
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link ecl-link--external"
                                       href="#">EU institutions</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link ecl-link--external"
                                       href="#">European Union</a>
                                </li>
                            </ul>
                        </div>
                    </div>
                </div>
            </div>
            <div class="ecl-footer__ec">
                <div class="ecl-container">
                    <div class="ecl-row">
                        <div class="ecl-col-sm ">

                            <ul class="ecl-list--inline ecl-footer__menu">
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="http://ec.europa.eu/info/about-commissions-new-web-presence_en">About
                                        the Commission's new web presence</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="http://ec.europa.eu/info/resources-partners_en">Resources
                                        for partners</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="http://ec.europa.eu/info/cookies_en">Cookies</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="http://ec.europa.eu/info/legal-notice_en">Legal
                                        notice</a>
                                </li>
                                <li class="ecl-footer__menu-item">
                                    <a class="ecl-link ecl-footer__link"
                                       href="http://ec.europa.eu/info/contact_en">Contact</a>
                                </li>
                            </ul>
                        </div>
                    </div>
                </div>
            </div>
        </footer>
