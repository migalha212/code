<?php function output_article_comments($comments) { ?>
    <section id="comments">
        <h1>Comments</h1>
        <?php foreach($comments as $comment) output_comment($comment); ?>
    </section>
<?php } ?>

<?php function output_comment($comment) { ?>
    <article>
        <header>
            <h1> <?= $comment['username'] ?> </h1>
        </header>
            <?= "<p> $comment[text] </p>" ?>
        <footer>
            <span class="date"><?= date('F j',$comment['published']) ?></span>
        </footer>
    </article>
<?php } ?>