<?php
// configuration 
require("../includes/config.php");

 

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
   $id = $_SESSION["id"];
    $symbol=$_POST["symbol"];
    
    $shares= cs50::query ("SELECT shares FROM portfolio WHERE user_id=? AND symbol=?",$_SESSION["id"],$symbol);
    //delete
   $delete = cs50::query ("DELETE from portfolio WHERE symbol=? AND user_id=?",$symbol,$_SESSION["id"]);
   
   
   
   // calculate the profit 
  
   $sell=lookup($symbol);               //get the current price of the stock
   $profit = $shares[0]["shares"] * $sell["price"];        
   
   
   $update= cs50::query ("UPDATE users SET cash=cash + $profit WHERE id=?",$_SESSION["id"]);
   			if($update==false)
   			{
   			    echo "error ";
   			}
   
   
   			
   
   // redirect to portfolio
			redirect("/");
    
    
}


else
    {
        // query user's portfolio
        $rows = cs50::query("SELECT * FROM portfolio WHERE user_id = ?", $_SESSION["id"]);	
        // create new array to store stock symbols
        $stocks = [];
        // for each of user's stocks
        foreach ($rows as $row)	
        {   
            // save stock symbol
            $stock = $row["symbol"];
            
            // add stock symbol to the new array
            $stocks[] = $stock;       
        }    
   //for debugging     // print_r($stocks);
        // render sell form
        render("sell_form.php", ["title" => "Sell Form", "stocks" => $stocks]);
    }



?>