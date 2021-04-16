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
   
       $rs=mysql_query("select Dated, TimeStamp,MID,Unit from datalog where CID='".$_GET['CID']."'");
	   echo "<table>";
	   echo "<tr style='background-color:darkblue;color:white;'><td>Dated</td><td> Time</td><td> Meter ID</td><td> Unit</td></tr>";
	   $rc=1;	   
	   while($data=mysql_fetch_row($rs))
	   {
		   if($rc==1)
		   {   
		    echo "<tr style='background-color:white;'><td>".$data[0]."</td><td>".$data[1]."</td><td>".$data[2]."</td><td>".$data[3]."</td></tr>"; 
	        $rc=2;
           }
		  else
		   {   
		    echo "<tr style='background-color:lightblue;'><td>".$data[0]."</td><td>".$data[1]."</td><td>".$data[2]."</td><td>".$data[3]."</td></tr>"; 
	        $rc=1;
           } 
	   }		   
      echo "</table>";
   ?>
   
   
   
   
</div>

</body>
</html>
