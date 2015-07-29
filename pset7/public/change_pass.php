<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["opass"]))
        {
            apologize("You must provide old password.");
        }
        
        else if (empty($_POST["npass"]))
        {
            apologize("Please Provide the new password.");
        }

        else if ($_POST["npass"]!=$_POST["cpass"])
        {
            apologize("Confirmation passwords dont match.");
        }        

        $rows = query("select * from users where id = ? ",$_SESSION['id']);
        if(crypt($_POST["opass"], $rows[0]["hash"]) == $rows[0]["hash"])
        {
            $x = query("update users set hash = ? where id =?",
            crypt($_POST['npass']),$_SESSION['id']);
        }
        else
        {
            apologize("Wrong Password");
        }        
            redirect("/");             
              
    }
    else
    {
          render("pass_form.php", ["title" => "Change Password"]);
    }

?>
