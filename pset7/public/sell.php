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
            apologize("Please Provide the number of shares you want to sell.");
        }
        
        $rows = query("select * from holdings where id = ? and symbol= ?",$_SESSION['id'],$_POST["symbol"]);
        $shares_available=$rows[0]['shares'];
        
        if ($_POST["num_shares"]>$shares_available){
            apologize("You are trying to sell more number of shares than you have currently. Please Specify a lower number");
        }
        
        // get the associative array for stock price.
        $stock = lookup($_POST["symbol"]);
        
        // check if the stock exists
        if (!is_numeric($stock["price"]))
        {
            apologize("Could not find the symbol you provided.");
        }
        else // if exists run queries to delete the stock from holdings and increase the amount of user cash  available
        {
            //render the quote value
            if ($_POST["num_shares"]==$shares_available)
            {
            $x=query("delete from holdings where id = ? and symbol= ?",$_SESSION['id'],$_POST["symbol"]);
            }
            else
            {
            $x=query("update holdings set shares = shares - ? where id = ? and symbol= ?",$_POST["num_shares"],$_SESSION['id'],$_POST["symbol"]);
            }  
            
            $x=query("update users set cash =cash + ? where id = ? ",$stock["price"]*$_POST["num_shares"],$_SESSION['id']);
            //transactions log
            $x=query("insert into transactions values(?,upper(?),'SELL',?,?,?,CURRENT_TIMESTAMP)",$_SESSION['id'],$_POST["symbol"],$_POST["num_shares"],$stock['price'],$stock['name']);
        
            redirect("/");             
        }
        
        
    }
    else
    {
        // else render form
        $rows = query("select * from holdings where id = ?",$_SESSION['id']);
        $stocks=[];
        foreach ($rows as $row)
        {
            $stocks[]=['symbol'=>$row['symbol'],"shares" => $row["shares"]];
        }
                 
        render("sell_form.php", ["title" => "Sell Shares","stocks"=>$stocks]);
    }

?>
