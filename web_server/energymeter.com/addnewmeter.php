<html>
 <head>
   <title> IoT Based Energy Meter </title>
  </head>
  <body>  
<?php
    
   include "banner.php";
   include "leftpanel.php";
   

?>
<div style="float:left";>
   <div style="height:50px;"></div>
   <form action=insertnewmeter.php method=POST>
   <table>
     <tr><td>Meter ID</td><td> <input type=text name=MID style="width:100px;"></input></td></tr>
     <tr><td> Capacity</td><td>
                             <select name=Capacity style="width:100px;">
							    <option value='1KV'>1KV</option>
								<option value='2KV'>2KV</option>
								<option value='3KV'>3KV</option>
								<option value='4KV'>4KV</option>
								
                             </select>
  							 </td></tr>
	 <tr><td> Current Unit </td> <td><input type=number name=Unit style="width:100px;"></input></td></tr>						 
     <tr><td></td><td align=right> <input type=reset value=Clear></input> <input type=submit value=Add></input></tr></td>
	</table>
	</form>
</div>

</body>
</html>
