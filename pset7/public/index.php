<?php

    // configuration
    require("../includes/config.php"); 

    $rows = query("Select * from holdings where 
            id = ?",$_SESSION['id']);  
        
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => number_format($stock["price"], 2, '.',','),
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    $rows = query("Select * from users where 
            id = ?",$_SESSION['id']);  
    $cash= number_format($rows[0]['cash'], 2, '.',',')
    ;

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio","positions" => $positions,"cash"=>$cash]);

?>
