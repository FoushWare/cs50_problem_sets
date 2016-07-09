<?php

//require the configuration 
require("../includes/config.php");

$history= cs50::query("SELECT * FROM history WHERE user_id=?",$_SESSION["id"]);

$histories=[];
foreach($history as $historys)
{
    $histories[]=["transaction" =>$historys["transaction"],
                "date/time" =>$historys["date/time"],
                "symbol" =>$historys["symbol"],
                "share" =>$historys["share"],
                "price" =>$historys["price"],
        
        ];
}

render("history_table.php",["title"=>"history.php","histories"=>$histories]);





?>