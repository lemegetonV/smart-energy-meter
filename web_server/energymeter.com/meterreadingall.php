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
<div align=center style="float:left;">

   <div style="height:50px;"></div>
   <table>
     <tr style="background-color:darkblue;color:white;"><td> CID </td><td> Consumer Name</td><td>Address</td><td> Contact No</td><td> Email </td><td> Meter ID </td><td>Current Unit </td></tr>
         <?php
		    $rs=mysql_query("select consumer.*, Meter.Unit from Consumer inner join meter on Consumer.MID=Meter.MID");
			$rc=1;
			while($data=mysql_fetch_row($rs))
			{
				if($rc==1)
				{
				 echo "<tr style='background-color:white;'><td>".$data[0]."</td><td>".$data[1]."</td><td>".$data[2]."</td><td>".$data[3]."</td><td>".$data[4]."</td><td>".$data[5]."</td><td>".$data[8]."</td></tr>";
				 $rc=2;
			    }	 
			 else
				{
				 echo "<tr style='background-color:lightblue;'><td>".$data[0]."</td><td>".$data[1]."</td><td>".$data[2]."</td><td>".$data[3]."</td><td>".$data[4]."</td><td>".$data[5]."</td><td>".$data[8]."</td></tr>";
				 $rc=1;
			    }	 	
			}
			
		 
		 ?>
	</table>	 
  

  


</div>


</body>
</html>
