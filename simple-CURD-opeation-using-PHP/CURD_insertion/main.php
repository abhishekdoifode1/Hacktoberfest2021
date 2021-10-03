<!DOCTYPE html>
<html lang="en">

<head>
    <!--Meta tags-->
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0 ,user-scalable=no" />

    <!--Title-->
    <title></title>

    <!--Fevicon-->
    <link rel="icon" href="images/favicon.ico" />

    <!--Google Fonts-->
    <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300;400;600;700&display=swap"
        rel="stylesheet" />

    <!--Font-Awesome-->
    <link rel="stylesheet" href="css/font-awesome/css/font-awesome.min.css" />

    <!--bootstrap css-->
    <link rel="stylesheet" href="css/bootstrap/bootstrap.min.css" />

    <!--Custom css-->
    <link rel="stylesheet" href="css/style.css" />

    <!--Responsive css-->
    <link rel="stylesheet" href="css/responsive.css" />
</head>

<body>
    <form action="index.php" method="post">
        <div class="container">
            <div class="row">
                <div class="col-12">
                    <h1 style="width: 40%;" class="big">Registration Form</h1>
                </div>
                <div class="col-3">
                    <label class="form-control">Name:</label>
                </div>
                <div class="col-9">
                    <input type="text" name="name" class="form-control" placeholder="Write Name" />
                </div>
                <div class="col-3">
                    <label for="" class="form-control">password:</label>
                </div>
                <div class="col-9">
                    <input type="password" name="password" class="form-control" placeholder="Write Password" />
                </div>

                <div style="margin-top: 20px;" class="col-12">
                    <select name="id" id="">
                        <?php
include "conn.php";
include "index.php";
$query = "select * from users";
$result = mysqli_query($con, $query);
while ($raw = mysqli_fetch_assoc($result)) {
    $id = $raw['userid'];
    echo "<option value='$id'>$id</option>";
}
?>
                    </select>
                    <div style="padding: 0;" class="col-12">
                        <button style="margin-right: 50px;" class="btn btn-primary btnn" name="create">create</button>
                        <button style="margin-right: 50px;" class="btn btn-primary btnn"
                                  name="retrieve">retrieve</button>
                        <button class="btn btn-primary btnn" name="update">update</button>
                        <button style="margin-left: 50px;" class="btn btn-primary btnn"
                                  name="delete">delete</button>
                    </div>
                </div>
            </div>
        </div>
    </form>

    <!--popper js-->
    <script src="js/popper/popper.min.js"></script>

    <!--jquery js-->
    <script src="js/jquery/jquery.min.js"></script>

    <!--bootstrap js-->
    <script src="js/bootstrap/bootstrap.min.js"></script>

    <!--Custom Script-->
    <script src="js/script.js"></script>
</body>

</html>