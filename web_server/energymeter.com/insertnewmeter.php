<?php
    include "dbconnect.php";
	
	$MID=$_POST['MID'];
	$Capacity=$_POST['Capacity'];
	$Unit=$_POST['Unit'];
	
	$sql="insert into Meter (MID, Capacity, UNIT) values('".$MID."','".$Capacity."','".$Unit."')";
	mysql_query($sql);
    include "meterlist.php";
?>	
