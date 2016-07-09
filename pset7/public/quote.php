<?php
// configuration
require("../includes/config.php");
// if form was submitted
if($_SERVER["REQUEST_METHOD"] == "POST")
{
	// If the symbol doensn't exist, display error message
	$_POST = lookup($_POST["symbol"]);
	 if($_POST === false)
	 {
	 	apologize("No such stock available");
	 }
	 render("../views/quote.php", ["title" => "Quote"]);
}
else
{
  // else render form
  render("quote_form.php", ["title" => "Quote"]);
}
?>