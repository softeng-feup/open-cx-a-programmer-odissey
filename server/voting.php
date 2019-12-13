<?php
    $question = $_GET["question"];
    $db = new PDO('sqlite:votes.db');
    $db->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $stmt = $db->prepare("select * from votes where question = ?");
    $stmt->execute(array($question));
    $votes = $stmt->fetchAll();

    if (empty($votes)) {
        $insert = $db->prepare("insert into votes values(?, 0, 0)");
        $db_status = $insert->execute(array($question));
    }
?>

<!DOCTYPE html>
<html lang="en-US">
<head>
<title>Vote!!!</title>
</head>

<body>
<h1><?= $question ?></h1>
<p>Yes <?= $yes_votes ?></p>
<p>No <?= $no_votes ?></p>
</body>
</html>
