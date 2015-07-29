<?php

    // configuration
    require("../includes/config.php"); 

    $rows = query("Select * from transactions where 
            id = ?",$_SESSION['id']);  
        
    $transactions = [];
    foreach ($rows as $row)
    {
            $transactions[] = [
                "name" => $row["name"],
                "price" => number_format($row["shares"]*$row["pricepershare"], 2, '.',','),
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "type" => $row["trans_type"],
                "dt" => $row["datetime"]    
            ];
        
    }
    
  
    // render portfolio
    render("history.php", ["title" => "History","transactions" => $transactions]);

?>
