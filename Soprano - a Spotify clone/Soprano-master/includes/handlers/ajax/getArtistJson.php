<?php
include("../../config.php");

if(isset($_POST['artistId'])) {
	$artistId = $_POST['artistId'];

	$query = mysqli_query($con, "SELECT * FROM artists WHERE id='$artistId'");

	$resultArray = mysqli_fetch_array($query);

	echo json_encode($resultArray);
}
?>