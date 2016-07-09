 
<table class="table table-striped">

    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>

    <tbody>
   <?php
   foreach($histories as $historiess)
   {
       print"<tr>";
       print"<td>".$historiess["transaction"]."</td>";
       print"<td>".$historiess["date/time"]."</td>";
       print"<td>".$historiess["symbol"]."</td>";
       print"<td>".$historiess["share"]."</td>";
       print"<td>".$historiess["price"]."</td>";
       print"</tr>";
      
   }
   
   
   
   
   
   
   ?>
</table>
            </div>