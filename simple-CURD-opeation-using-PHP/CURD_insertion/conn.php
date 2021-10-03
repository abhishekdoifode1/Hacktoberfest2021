<?php

// Connection

$server = "localhost";
$name = "root";
$password = "";

$con = mysqli_connect($server, $name, $password, "primary");

if (!$con) {
    echo "Connection is FAILED Due to ";
    echo mysqli_error($con) . "<br>";
} else {
    echo "Database Connected Sucessfully......." . "<br>";
}
