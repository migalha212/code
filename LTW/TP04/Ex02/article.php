<?php
  require_once('database/connection.php'); // database connection
  require_once('database/news/news.php');       // news table queries
  require_once('database/comments/comments.php'); // comments table queries
  require_once('template/common.php');    // common templates
  require_once('template/news.php');      // news templates
  require_once('template/comments.php'); // comments templates
  $db = getDatabaseConnection();           // connect to database
  $article = getArticle($db,$_GET['id']);             // get articles from database
  $comments = getAllcomments($db,$_GET['id']);         // get comments from database


  output_header();                         // output page header
    output_full_article($article);          // output list of articles
    output_article_comments($comments);          // output list of comments
  output_footer();                         // output page footer
?>