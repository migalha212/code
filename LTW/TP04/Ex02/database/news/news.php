<?php
    function getAllNews($db){
        $stmt = $db->prepare('SELECT news.*, users.*, COUNT(comments.id) AS comments
                            FROM news JOIN
                            users USING (username) LEFT JOIN
                            comments ON comments.news_id = news.id
                            GROUP BY news.id, users.username
                            ORDER BY published DESC');
        $stmt->execute();
        return $stmt->fetchAll();
    }
?>

<?php
    function getArticle($db, $id) {
        $stmt = $db->prepare('SELECT news.*, users.*, COUNT(comments.id) as comments
                            FROM news JOIN
                            users USING (username) LEFT JOIN
                            comments ON comments.news_id = news.id
                            WHERE news.id = :id
                            GROUP BY news.id, users.username');
        $stmt->bindParam(':id', $id);
        $stmt->execute();
        return $stmt->fetch();
    }
?>

<?php
    function insertArticle($db, $title, $content, $username) {
        $stmt = $db->prepare('INSERT INTO news (title, content, username) VALUES (:title, :content, :username)');
        $stmt->bindParam(':title', $title);
        $stmt->bindParam(':content', $content);
        $stmt->bindParam(':username', $username);
        return $stmt->execute();
    }
?>

<?php
    function editArticle($db, $id, $title, $intro, $fulltext) {
        $stmt = $db->prepare('UPDATE news SET title = :title, introduction = :intro, fulltext = :fulltext WHERE id = :id');
        $stmt->bindParam(':id', $id);
        $stmt->bindParam(':title', $title);
        $stmt->bindParam(':intro', $intro);
        $stmt->bindParam(':fulltext', $fulltext);
        return $stmt->execute();
    }
?>
