<?php
    function add(int $a, int $b) {
        return $a + $b;
    }
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $num1 = $_POST['num1'];
        $num2 = $_POST['num2'];
        $sum = add($num1, $num2);
        echo "Sum from Post is: $sum";
    }
    else{
        $num1 = $_GET['num1'];
        $num2 = $_GET['num2'];
        $sum = add($num1,$num2);
        echo "Sum from URL arguments is: $sum";
    }
?>

<p><a href="form2.html">Do another Sum!</a></p>