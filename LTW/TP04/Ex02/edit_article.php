<?php
    require_once 'template/common.php';
    require_once 'template/forms.php';
    require_once 'database/connection.php';

    $db = getDatabaseConnection();

    output_header();
    output_form($_GET['id']);
    output_footer();
?>