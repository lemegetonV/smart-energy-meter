<?php
   include "dbconnect.php";
   date_default_timezone_set("Asia/calcutta");
   $MID=$_GET['MID'];
   $UNIT=$_GET['UNIT'];
   $Dated=date('Y-m-d');
   $TimeStamp=date('h:i:s A');
   
   $rs=mysql_query("select CID from Consumer where MID='".$MID."'");
   if($data=mysql_fetch_row($rs))
   {
	   $CID=$data[0];  
   } 
  else
  {
	 $CID="ERROR002"; 
  }	  
  
  $sql="insert into datalog(Dated, TimeStamp,CID, MID, UNIT) values('".$Dated."','".$TimeStamp."','".$CID."','".$MID."','".$UNIT."')";
  mysql_query($sql);
  mysql_query("update Meter set Unit='".$UNIT."' where MID='".$MID."'");
  mysql_query("update consumer set Unit='".$UNIT."' where CID='".$CID."'");
  
  
 ?>
  