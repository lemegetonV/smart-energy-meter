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
     <tr style="background-color:darkblue;color:white;"><td> Meter ID </td><td> Capacity </td><td>Unit</td></tr>
         <?php
		    $rs=mysql_query("select * from meter");
			$rc=1;
			while($data=mysql_fetch_row($rs))
			{
				if($rc==1)
				{
				 echo "<tr style='background-color:white;'><td>".$data[0]."</td><td>".$data[1]."</td><td>".$data[2]."</td></tr>";
				 $rc=2;
			    }	 
			 else
				{
				 echo "<tr style='background-color:lightblue;'><td>".$data[0]."</td><td>".$data[1]."</td><td>".$data[2]."</td></tr>";
				 $rc=1;
			    }	 	
			}
			
		 
		 ?>
	</table>	 
  

  


</div>


</body>
</html>
