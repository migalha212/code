<?php 
    function getAllcomments($db, $news_id) {
        $stmt = $db->prepare('SELECT * FROM comments JOIN news on news.id = comments.news_id WHERE news.id = :id ORDER BY published DESC');
        $stmt->bindParam(':id', $news_id);
        $stmt->execute();
        return $stmt->fetchAll();
    }
?>