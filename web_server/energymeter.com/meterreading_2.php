<?php
        
  	   session_start();
	   error_reporting(0);
	   $CID=$_POST['CID'];
       if($CID!="")
	   {
		  $_SESSION['CID']=$CID; 
	   }	
       else
       {
		   $CID=$_SESSION['CID'];
	   }		   
	   
?>
<html>
 <head>
   <meta http-equiv="refresh" content="1">
  </head> 
<body>
<?php 
  include "banner.php";  
  include "leftpanel.php";  
  include "dbconnect.php";  
?>


<div style="float:left;padding-top:100px;padding-left:100px;">

      <h2> Consumer Details </h2> 
     <?php
	 
       	   
		$rs=mysql_query("select * from Consumer where CID='".$CID."'");
		if($data=mysql_fetch_row($rs))
		{
			echo "<table width=90%>";
			   echo "<tr><td style='background-color:tomato;width:150px;border-radius:15px;'>Consumer ID</td><td>".$data[0]."</td></tr>";
			   echo "<tr><td style='background-color:tomato;width:150px;border-radius:15px;'>Consumer Name</td><td>".$data[1]."</td></tr>";
			   echo "<tr><td style='background-color:tomato;width:150px;border-radius:15px;'>Address</td><td>".$data[2]."</td></tr>";
			   echo "<tr><td style='background-color:tomato;width:150px;border-radius:15px;'>Contact No</td><td>".$data[3]."</td></tr>";
               echo "<tr><td style='background-color:tomato;width:150px;border-radius:15px;'>Email</td><td>".$data[4]."</td></tr>";
			   echo "<tr><td style='background-color:red;width:150px;border-radius:15px;'>Meter ID</td><td>".$data[5]."</td></tr>";
			   $MID=$data[5];
			   echo "<tr><td style='background-color:red;width:150px;border-radius:15px;'> Unit Consumed</td><td>".$data[6]."</td></tr>";
					
		echo "</table>";   
		
		    echo "<div style='height:50px;'></div>";
		   echo "<a href=cw2.php?CID=".$CID."> <div align=center style='background-color:blue;color:white;width:200px; border-radius:15px;'>Show Details</div> </a>"; 

			
		}
        else
		{
			
			 echo "<h2>Invalid Consumer ID</h2>";
			
		}			
		
		
	 ?>
	 

   

</div>




</body>
</html>
