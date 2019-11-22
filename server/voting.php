<?php
    $question = $_GET["question"];
    $db = new PDO('sqlite:votes.db');
    $stmt = $db->prepare("select * from votes where question = ?");
    $db_status = $stmt->execute(array($question));

    if ($db_status) {
        $votes = $stmt->fetchAll();
    } else {
        $stmt = $db->prepare("insert into votes values(?, 0, 0)");
        $db_status = $stmt->execute(array($question));
    }
?>

<!DOCTYPE html>
<html lang="en-US">
<head>
<title>Vote!!!</title>
</head>

<body>
<h1><?= $question ?></h1>
<p>Yes</p>
<p>No</p>
</body>
</html>
