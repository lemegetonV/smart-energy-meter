<?php
    include "dbconnect.php";
	
	$CID=$_POST['CID'];
	$MID=$_POST['MID'];
	
	$sql="update Consumer set MID='".$MID."' where CID='".$CID."'";
	mysql_query($sql);
    echo "New Meter ASsign Succesfull";
?>
