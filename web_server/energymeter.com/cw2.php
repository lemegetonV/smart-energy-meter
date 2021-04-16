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
	      $CID=$_POST['CID'];
	     if($CID=="") $CID=$_GET['CID']; 
		 $sql="select consumer.*, Meter.Unit from Consumer inner join Meter on Consumer.MID=Meter.MID where Consumer.cID='".$CID."'";
		 //echo $sql;
		 $rs=mysql_query($sql);
		 
	     if($data=mysql_fetch_row($rs))
		 {
			 echo "<table style='font-size:20;'>";
			 echo "<tr><td style='border-top-left-radius:10px;border-bottom-left-radius:10px;background-color:#b3c6ff;width:200px;'>Consumer ID</td><td style='background-color:#ffcccc;width:200px;border-top-right-radius:10px;border-bottom-right-radius:10px;'>".$data[0]."</td></tr>";
			 echo "<tr><td style='border-top-left-radius:10px;border-bottom-left-radius:10px;background-color:#b3c6ff;width:200px;'>Consumer Name</td><td style='background-color:#ffcccc;width:200px;border-top-right-radius:10px;border-bottom-right-radius:10px;'>".$data[1]."</td></tr>";
			 echo "<tr><td style='border-top-left-radius:10px;border-bottom-left-radius:10px;background-color:#b3c6ff;width:200px;'>Contact Number</td><td style='background-color:#ffcccc;width:200px;border-top-right-radius:10px;border-bottom-right-radius:10px;'>".$data[3]."</td></tr>";
			 echo "<tr><td style='border-top-left-radius:10px;border-bottom-left-radius:10px;background-color:#b3c6ff;width:200px;'>Email</td><td style='background-color:#ffcccc;width:200px;border-top-right-radius:10px;border-bottom-right-radius:10px;'>".$data[4]."</td></tr>";
			 echo "<tr><td style='border-top-left-radius:10px;border-bottom-left-radius:10px;background-color:#b3c6ff;width:200px;'>Meter ID</td><td style='background-color:#ffcccc;width:200px;border-top-right-radius:10px;border-bottom-right-radius:10px;'>".$data[5]."</td></tr>";
			 echo "<tr><td style='border-top-left-radius:10px;border-bottom-left-radius:10px;background-color:#b3c6ff;width:200px;'>Meter Reading</td><td style='background-color:#ffcccc;width:200px;border-top-right-radius:10px;border-bottom-right-radius:10px;'>".$data[8]."</td></tr>";
			 echo "</table>";
			 
			 
			 echo "<a href=detailreport.php?CID=".$CID."> Detail Report </a>";
			 
			 
		 }
		 else
	     {
			 echo "Sorry!!! Invalid Consumer ID";
			 
		 }		 
	 
	 ?>
	 
	 
	 
	 
</div>

</body>
</html>
