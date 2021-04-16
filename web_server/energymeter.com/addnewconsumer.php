<html>
 <head>
   <title> IoT Based Energy Meter </title>
  </head>
  <body>  
<?php
    
   include "banner.php";
   include "leftpanel.php";
   

?>

<div align=center style="float:left;">
    <div style="height:50px;"> </div>
   <form action=insertconsumer.php method=POST>	
   <table style="border-top-style:solid;border-bottom-style:solid;">
      <tr><td>Consumer ID</td><td><input type=text name=CID style="width:200px;"> </input></td></tr>
	  <tr><td>Consumer Name</td><td><input type=text name=CName style="width:200px;"> </input></td></tr>
	  <tr><td> Address</td><td> <textarea name=Address rows=5 style="width:200px;"></textarea></td></tr>
	  <tr><td>Contact Number</td><td><input type=text name=ContactNo style="width:200px;"> </input></td></tr>
	  <tr><td>Email</td><td><input type=email name=email style="width:200px;"> </input></td></tr>
	  <tr><td>Meter ID</td><td><input type=text name=MID style="width:200px;"> </input></td></tr>
	  <tr><td></td><td align=right><input type=reset value=Clear></input> <input type=submit value=Submit></input></td></tr>	  
   </table>
   </form>
   

</div>


</body>
</html>
