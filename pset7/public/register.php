<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if ($_POST["confirmation"]!=$_POST["password"] )
        {
            apologize("Passwords dont match.");
        }
        
        // insert user into database
        $rows = query("INSERT INTO users (username, hash, cash) VALUES
        (?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));

        // if the query is not a success!!
        if ($rows === false)
        {
            // Insert has failed
            apologize("Something bad happened. Please try again");
        }
        else
        {
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            $_SESSION["id"]=$id;
            redirect("/");
        }
    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
