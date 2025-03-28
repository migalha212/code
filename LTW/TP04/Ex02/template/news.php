<?php function output_article_list($articles) { ?>
    <section id="news">
        <?php foreach($articles as $article) output_article($article); ?>
    </section>
<?php } ?>

<?php function output_article($article) { ?>
    <article>
        <header>
            <h1> <?= '<a href="article.php?id=' . $article['id'] . '">' . $article['title'] . '</a>'; ?> </h1>
        </header>
        <img src="https://picsum.photos/600/300?business" alt="">
            <?= "<p> $article[introduction] </p>" ?>
        <footer>
            <span class="author"><?= $article['username'] ?></span>
            <span class="edit"><a href="edit_article.php?id=<?=$article['id'] ?>">Edit</a></span>
            <span class="tags"><?php foreach(explode(',',$article['tags']) as $tag){echo "<a href='index.php'>#$tag</a> "; }?></span>
            <span class="date"><?= date('F j',$article['published']) ?></span>
            <a class="comments" href="article.php#comments"><?= $article['comments'] ?></a>
        </footer>
    </article>
<?php } ?>


<?php function output_full_article($article) { ?>
    <section id="news">
        <article>
            <header>
                <h1> <?= '<a href="article.php?id=' . $article['id'] . '">' . $article['title'] . '</a>'; ?> </h1>
            </header>
            <img src="https://picsum.photos/600/300?business" alt="">
                <?= "<p> $article[introduction] </p>" ?>
                <?= "<p> $article[fulltext] </p>" ?>
            <footer>
                <span class="author"><?= $article['username'] ?></span>
                <span class="edit"><a href="edit_article.php?id=<?=$article['id'] ?>">Edit</a></span>
                <span class="tags"><?php foreach(explode(',',$article['tags']) as $tag){echo "<a href='index.php'>#$tag</a> "; }?></span>
                <span class="date"><?= date('F j',$article['published']) ?></span>
            </footer>
        </article>
    </section>
<?php } ?>