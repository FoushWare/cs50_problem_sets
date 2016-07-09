
<?php
/* 
 index.php is the file that’s loaded by default 
 when you visit a URL like https://ide50-username.cs50.io/
  ......its purpose in life is to control the behavior of
         your website when a user visits 
*/
/* 
 Eventually, you’ll need to add some more PHP code to this file
 in order to pass more than just title to render(show in the page).
 But for now, let’s take a look at portfolio.php,
 the view that this controller ultimately renders.


*/




  require("../includes/config.php");
   
     $id = $_SESSION["id"];
    // Retrieve all the shares this users owns
    $rows = CS50::query("SELECT symbol,shares FROM portfolio WHERE user_id = ?",$_SESSION["id"]);
    $user= CS50::query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
   
    $positions = [];
foreach ($rows as $row)
{
    $stock = lookup($row["symbol"]);
    if ($stock !== false)
    {
        $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
           
        ];
    }
}
 //get cash balance from list of users
	$balance = cs50::query("SELECT cash FROM users WHERE id=?", $_SESSION["id"]);
   
    if (empty($positions))
    {
       
        apologize("you haven't any stocks ");
    }
  else{  
   
   
 
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio","user"=>$user,"balance" => $balance[0]["cash"]]);
}
?>
 