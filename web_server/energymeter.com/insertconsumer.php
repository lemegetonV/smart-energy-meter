<?php
    include "dbconnect.php";
	
	$CID=$_POST['CID'];
	$CName=$_POST['CName'];
	$Address=$_POST['Address'];
	$ContactNo=$_POST['ContactNo'];
	$email=$_POST['email'];
	$MID=$_POST['MID'];
	
	$sql="insert into Consumer(CID, CName, Address, ContactNo, Email, MID,Password) values('".$CID."','".$CName."','".$Address."','".$ContactNo."','".$email."','".$MID."','".$ContactNo."')";
	mysql_query($sql);
    include "addnewconsumer.php";
?>
