<?php function output_form($id){ ?>
    <form method="post" action="action_edit_news.php" id="form">
        <h2>Edit Article</h1>

        <input type="hidden" name="id" value="<?php echo $id; ?>">

        <label for="title">Title</label>
        <input type="text" name="title" id="title" required>
        
        <label for="introduction">Introduction</label>
        <input type="textarea" name="introduction" id="introduction" required>

        <label for="fulltext">Full Text</label>
        <input type="textarea" name="fulltext" id="fulltext" required>

        <input type="submit" value="Submit">
<?php }?>

<?php function output_login_form(){
    
<?php } ?>