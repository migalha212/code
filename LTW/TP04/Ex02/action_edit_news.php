<?php
    require_once 'database/connection.php';
    require_once 'database/news/news.php';

    $db = getDatabaseConnection();
    editArticle($db, $_POST['id'], $_POST['title'], $_POST['introduction'], $_POST['fulltext']);
    header('Location: article.php?id=' . $_POST['id']);
    exit;
?>