<?php
include "conn.php";

//for insert data
if (isset($_POST["create"])) {
    $username = $_POST["name"];
    $password = $_POST["password"];

    echo "<br>";
    echo "The username: " . $username . "<br>" . "Password: " . $password;

    $query = "INSERT INTO users (name, password) VALUES ('$username', '$password')";
    $result = mysqli_query($con, $query);
    if (!$result) {
        die("<br>Delete Failed" . mysqli_error($con));
    } else {
        echo "<br>task complete";
    }
    mysqli_close($con);
}

//for retrieve data
else if (isset($_POST['retrieve'])) {
    $query = "select * from users";
    $result = mysqli_query($con, $query);
    while ($raw = mysqli_fetch_assoc($result)) {
        ?>
        <pre>
        <?php
print_r($raw);
        ?>
        </pre>
        <?php
}
    if (!$result) {
        die("<br>Delete Failed" . mysqli_error($con));
    } else {
        echo "<br>task complete";
    }
    mysqli_close($con);
}

//for update the data
else if (isset($_POST['update'])) {
    $username = $_POST['name'];
    $password = $_POST['password'];
    $id = $_POST['id'];
    $query = "update users set name='$username',password='$password' where userid=$id";
    $result = mysqli_query($con, $query);

    if (!$result) {
        die("<br>Delete Failed" . mysqli_error($con));
    } else {
        echo "<br>task complete";
    }
    mysqli_close($con);
}

//for delete the data
else if (isset($_POST['delete'])) {
    $id = $_POST['id'];
    $query = "delete from users where userid=$id";
    $result = mysqli_query($con, $query);

    if (!$result) {
        die("<br>Delete Failed" . mysqli_error($con));
    } else {
        echo "<br>task complete";
    }
    mysqli_close($con);
}
