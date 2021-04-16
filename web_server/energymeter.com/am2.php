<html>
 <head>
   <title> IoT Based Energy Meter </title>
  </head>
  <body>  
<?php
    
   include "banner.php";
   include "leftpanel.php";
   include "dbconnect.php";
   

?>
<div style="float:left";>
    <div style="height:50px;"></div>
	<?php
	    $rs=mysql_query("select * from Consumer where CID='".$_POST['CID']."'");
		if($data=mysql_fetch_row($rs))
		{
			echo "<form action=am3.php method=POST>";
			echo "<table>";
			echo "<tr><td>Consumer ID</td><td>".$data[0]."</td></tr>";
			echo "<tr><td>Consumer Name</td><td>".$data[1]."</td></tr>";
			echo "<tr><td>Address</td><td>".$data[2]."</td></tr>";
		    echo "<tr><td>Contact Bumber</td><td>".$data[3]."</td></tr>";
			echo "<tr><td>Email</td><td>".$data[4]."</td></tr>";
		  	echo "<tr><td>Present Meter ID</td><td>".$data[5]."</td></tr>";
			echo "<input type=hidden name=CID value=".$_POST['CID']."></input>";
		  	echo "<tr><td>New Meter ID</td><td><input type=text name=MID></input></td></tr>";
		  	echo "<tr><td></td><td align=right><input type=submit value=Assign></input></td></tr>";
		  
		  echo "</table>";
		  echo "</form>";
		}
       else
	   {
		   echo "Consumer ID:".$_POST['CID']." not Found";
	   }    

			
			
		
			
	
	?>
	

</div>

</body>
</html>
