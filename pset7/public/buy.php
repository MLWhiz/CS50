<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        
        else if (empty($_POST["num_shares"]))
        {
            apologize("Please Provide the number of shares you want to buy.");
        }
        
        // num_shares not a proper integer
        else if (!preg_match("/^\d+$/", $_POST["num_shares"]))
        {
            apologize("Please Provide the number of shares you want to buy.");
        }
        
        
        $rows = query("select * from users where id = ? ",$_SESSION['id']);
        $cash_available=$rows[0]['cash'];
        // get the associative array for stock price.
        $stock = lookup($_POST["symbol"]);
        $cash_required = $stock['price']*$_POST["num_shares"]; 
                
        if ($cash_required>$cash_available){
            apologize("The price of the shares is more than you have in account. Please buy less shares");
        }
        
        $rows=query("select * from holdings where id = ? and symbol=upper(?)",$_SESSION['id'],$_POST["symbol"]);

        if($rows!=false){ 
        $x=query("update holdings set shares =shares + ? where id = ? and symbol= upper(?)",$_POST["num_shares"],$_SESSION['id'],$_POST["symbol"]);
        }
        else
        {
        $x=query("insert into holdings values(?,upper(?),?)",$_SESSION['id'],$_POST["symbol"],$_POST["num_shares"]);
        
        }
        $x=query("update users set cash =cash - ? where id = ? ",$cash_required,$_SESSION['id']);
        
        //transactions log
        $x=query("insert into transactions values(?,upper(?),'BUY',?,?,?,CURRENT_TIMESTAMP)",$_SESSION['id'],$_POST["symbol"],$_POST["num_shares"],$stock['price'],$stock['name']);
        
        redirect("/");             
        
        
        
    }
    else
    {
        // else render form                 
        render("buy_form.php", ["title" => "Buy Shares"]);
    }

?>
