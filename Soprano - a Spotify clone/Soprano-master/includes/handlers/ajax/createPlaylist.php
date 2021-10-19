<?php
include("../../config.php");

if(isset($_POST['name']) && isset($_POST['email'])) {

	$name = $_POST['name'];
	$email = $_POST['email'];
	$date = date("Y-m-d");

	$query = mysqli_query($con, "INSERT INTO playlists VALUES('', '$name', '$email', '$date')");

}
else {
	echo "Name or email parameters not passed into file";
}

?>