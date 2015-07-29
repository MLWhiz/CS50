<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"]
    $place = $_GET["geo"];
    $word1 = explode("+", $place)[0];
    $word2 = explode(",", $place)[0];
    $word3 = explode(" ", $place)[0];
    $rows = query("select * from places where postal_code = ? or place_name like ? or place_name like ? or place_name like ?",$place,$word1,$word2,$word3);
    
    foreach ($rows as $row){
        $places[] = $row;
    }    
    
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>
