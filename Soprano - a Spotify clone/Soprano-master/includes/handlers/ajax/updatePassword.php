<?php
include("../../config.php");

if(!isset($_POST['email'])) {
	echo "ERROR: Could not set email";
	exit();
}

if(!isset($_POST['oldPassword']) || !isset($_POST['newPassword1'])  || !isset($_POST['newPassword2'])) {
	echo "Not all passwords have been set";
	exit();
}

if($_POST['oldPassword'] == "" || $_POST['newPassword1'] == ""  || $_POST['newPassword2'] == "") {
	echo "Please fill in all fields";
	exit();
}

$email = $_POST['email'];
$oldPassword = $_POST['oldPassword'];
$newPassword1 = $_POST['newPassword1'];
$newPassword2 = $_POST['newPassword2'];

$oldMd5 = md5($oldPassword);

$passwordCheck = mysqli_query($con, "SELECT * FROM users WHERE email='$email' AND password='$oldMd5'");
if(mysqli_num_rows($passwordCheck) != 1) {
	echo "Password is incorrect";
	exit();
}

if($newPassword1 != $newPassword2) {
	echo "Your new passwords do not match";
	exit();
}

if(preg_match('/[^A-Za-z0-9]/', $newPassword1)) {
	echo "Your password must only contain letters and/or numbers";
	exit();
}

if(strlen($newPassword1) > 30 || strlen($newPassword1) < 5) {
	echo "Your password must be between 5 and 30 characters";
	exit();
}

$newMd5 = md5($newPassword1);

$query = mysqli_query($con, "UPDATE users SET password='$newMd5' WHERE email='$email'");
echo "Update successful";

?>