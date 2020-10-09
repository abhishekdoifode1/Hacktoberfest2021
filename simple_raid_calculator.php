<?php 
//Simple RAID configuration calculator written in PHP:
?>
<!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title>Simple RAID Calculator</title>
	</head>
	<body>
	
	<h1>Simple RAID Calculator</h1>
	<p>DO NOT USE THIS CALCULATION FOR PRODUCTION ENVIRONMENTS!</p>
	<p>This calculator's main aim is not provide a bulletproof RAID calculation. It's rather using PHP POST method and switch-case statement.</p>
	<p>There is not neither input validation nor RAID disk number and size validation included in this calculator.</p>
	<form action="#" method="post">
 
		Number of disks: <input type="text" name="disks">
		<br>
		Size of disks (GiB): <input type="text" name="size">
		<br>
		RAID Type: <input type="radio" name="type" value="0" checked>RAID 0 <input type="radio" name="type" value="1">RAID 1 <input type="radio" name="type" value="5">RAID 5
		<br>
		<input type="submit" value="Calculate">
	</form> 
	<?php
	//Calculation part:
	//If calculate button has clicked:
	if (!empty($_POST))
	{
		//Get the form values:
		$disks = $_POST["disks"];
		$size = $_POST["size"];
		$type = $_POST["type"];
		$totalSize = 0;
		//Do the calculation according to selected RAID type:
		switch($type)
		{
			case 0:
			$totalSize = $disks * $size;
			break;
			case 1:
			$totalSize = ($disks * $size)/2;
			break;
			case 5:
			$totalSize = ($disks-1) * $size;
			break;
		}
		echo $totalSize."GiB";
	}
	
	?>
	</body>
</html>

