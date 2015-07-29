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
        
        // get the associative array for stock price.
        $stock = lookup($_POST["symbol"]);
        
        // if we found user, check password
        if (!is_numeric($stock["price"]))
        {
            apologize("Could not find the symbol you provided.");
        }
        else
        {
            //render the quote value
            render("quote_val.php", ["title" => "Quotes", "price" => number_format($stock["price"], 2, '.',','), "name" => $stock["name"], "symbol" => $stock["symbol"]]);             
        }
        
        
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Get Quotes"]);
    }

?>
