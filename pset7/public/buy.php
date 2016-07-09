<?php 
//get configuration 
require("../includes/config.php");

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    //******************check what coming from the form *************************************
    
    // field  symbol is empty or not 
    if(empty($_POST["symbol"]))
    {
        apologize("You must provide a symbol.");
    }
    
    // field shares  is empty or not 
	        if (empty($_POST["shares"]))
	        {
		        apologize("You must provide exact numer of shares you want to buy.");
		}
		
		//to upper if the user type it in lowercase 
		 if ($_POST["symbol"] !== strtoupper($_POST["symbol"]))
		    	{
				$_POST["symbol"] = strtoupper($_POST["symbol"]);
			}
    
    // accept only non-negative integer of shares accept only digits 
			if (ctype_digit($_POST["shares"]) === true)
		    	{
	//**********************************************************************************	
	
	
	//search for the current price of the symbol 
    $stock= lookup($_POST["symbol"]);
    
    //check if there is as symbol assosititive with the symbol the user type
    if($stock==false)
    {
        apologize("symbol not found");
        
        }
        
        $users= cs50::query("SELECT cash FROM users WHERE id=?",$_SESSION["id"]);
		    	    
	//calculate the total prise to compare it with the actual money of the user  	    
	   $cost= $stock["price"] * $_POST["shares"];	    
	   	/* check if user can afford it */
		    	 if($users[0]["cash"] >= $cost)  
               {
                   
                    				// insert new shares into table (portfolios)			
			        $result = cs50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?)
				    ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", 
				    $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
				    
				     if($result==false)
				    {
				        apologize("i can't insert these shares ");
				    }
				    
				    
				    // update user's current balance
			    	$current_balance = cs50::query("UPDATE users SET cash = cash - $cost
			    	WHERE id = ?", $_SESSION["id"]);  
	                        
	                        if($current_balance==false)
	                        {
                              apologize("i can't update you cash ");
   
	                        }
	                        
                   
               }
		    	    
		    	    
	  	}
	  	redirect("/");
    
}
    
    
    
    
    
    

else{
    render("buy_form.php",["title"=>"buy.php"]);
}










   ?>


