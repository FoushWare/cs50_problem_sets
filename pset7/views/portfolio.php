<!DOCTYPE html>
<html lang="en">
<head>
  <title>portfolio.php</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js"></script>
  <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
</head>
<body>

<div class="container">
  <h2>portfolio information</h2>
              
  <table class="table table-striped">
    <thead>
      <tr>
        <th>Name</th>
        <th>symbol</th>
        <th>share</th>
        <th>prise</th>
        
        
      </tr>
    </thead>
    <tbody>
     
       <?php
        foreach ($positions as $position)
        {
         print"<tr>";   
             print("<td>" . $position["name"] . "</td>");
            print("<td>" . $position["symbol"] . "</td>");
            print("<td>" . $position["shares"] . "</td>");
            print("<td>" . $position["price"] . "</td>");
            print"</tr>";
        }
    ?>
   
    
  
		<tr>
				<td>CURRENT MONEY </td>
				
				 <td >$<?= number_format($balance, 2); ?></td>
    
				
			</tr>
    </tbody>
  </table>
</div>

</body>
</html>
