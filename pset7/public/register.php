

<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    // check the validation of the field of the form     
        // Required field names
$required = array('username', 'password', 'confirm');

// Loop over field names, make sure each one exists and is not empty
$error = false;
foreach($required as $field) {
  if (empty($_POST[$field])) {
    $error = true;
  }
}

if ($error) {
  apologize("All fields are required.");
} else {
  //check if the password is equal to confirmpassword
  if($_POST["password"]!=$_POST["confirm"])
  {
      apologize("password is not matched");
  }
}

/* ***************Add user to database********** */
if ( CS50::query("INSERT INTO users (username,hash,cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"])) === false)
        {
            apologize("Username already exists");
            
        }
else{
    
    // the process is successed   .. ... then   log the user in automatacly
    //get the last id inserted to the database
    $rows= CS50::query("SELECT LAST_INSERT_ID() as id");
    $id=$rows[0]["id"];
    //store the id of the user in the session 
    $_SESSION["id"]=$id;
    redirect("index.php");
}

        
    }

?>

