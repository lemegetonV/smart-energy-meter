<?php

   include "dbconnect.php";
   
   $UserID=$_POST['UserID'];
   $Password=$_POST['Password'];
   
   $rs=mysql_query("select * from User where UserID='".$UserID."' and Password='".$Password."'");
   if($data=mysql_fetch_row($rs))
   {
	   include "main.php";  
   }
   else
   {
	   
	   include "ERR01.php";
   }   

?>
