const app_getter = require("express");
const app = app_getter();
const fileUpload = require('express-fileupload');
const { body, validationResult } = require('express-validator');
const ejs = require('ejs');
const path = require('path');
const con = require('./connection');

app.use(app_getter.static('profile_photo'));
app.use('/profile_photo', app_getter.static('profile_photo'));
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
app.use(app_getter.static('/'))
app.use(app_getter.json());
app.use(app_getter.urlencoded({ extended: false }));
app.use(fileUpload());

app.get("/", function (req, res) {
    res.sendFile(__dirname + "/list.html");
});

app.get("/index.html", function (req, res) {
    res.sendFile(__dirname + "/index.html");
});

app.get('/views/edit/:id', function (req, res) {
    const id = req.params.id;
    con.query(`SELECT name,email,id,password,gender,picpath FROM user_data where id=${id}`, function (err, data) {

        (err) ? console.log("error to fetch data for id " + id + " due to : " + err) : '';
        console.log("data for id " + id + " is " + data[0]);
        res.render('edit', {
            title: '',
            user_data: data[0]
        });
    });
});

//to display user data
app.get("/views/view_data.ejs", function (req, res) {
    con.query("SELECT id,name,email,gender,picpath FROM user_data", function (err, data, col) {
        (err) ? console.log("error in get data due to : " + err) : '';
        console.log(data);
        res.render('view_data', {
            title: '',
            users: data
        });
    });
});

//to edit user data
app.post('/edit_form', function (req, res) {

    let sampleFile_pic = req.files ? req.files.photo_pic : null;

    let password = req.body.password ? req.body.password : null;

    let new_name = req.body.name;
    let new_email = req.body.email;
    let id = req.body.userid;
    let gender = req.body.gender;

    var mysqlpath = null;

    console.log("sample file:" + sampleFile_pic);

    if (sampleFile_pic) {
        let uploadPath = __dirname + '/profile_photo/' + Date.now() + '_' + sampleFile_pic.name;
        mysqlpath = '/profile_photo/' + Date.now() + '_' + sampleFile_pic.name;

        sampleFile_pic.mv(uploadPath, function (err) {
            (err) ? console.log(err) : '';
        });
    }

    let update_query = "UPDATE user_data SET name='" + new_name + "',email='" + new_email + "',gender='" + gender + "' WHERE id=" + id;

    if (mysqlpath)
        update_query = "UPDATE user_data SET name='" + new_name + "',email='" + new_email + "',gender='" + gender + "',picpath='" + mysqlpath + "' WHERE id=" + id;

    if (password)
        update_query = "UPDATE user_data SET name='" + new_name + "',email='" + new_email + "',password='" + password + "',gender='" + gender + "' WHERE id=" + id;

    if (password && mysqlpath)
        update_query = "UPDATE user_data SET name='" + new_name + "',email='" + new_email + "',password='" + password + "',gender='" + gender + "',picpath='" + mysqlpath + "' WHERE id=" + id;

    console.log(mysqlpath);
    console.log(update_query);
    // console.log(password);


    con.query(update_query, function (err, result) {

        (err) ? console.log("error in edit data due to : " + err) : console.log("data has been updated for the user : " + new_name + "\nTo go the main page!");
        // res.redirect('list.hhtl');
        (err) ? res.end("error in edit data due to : " + err) : res.redirect('/views/view_data.ejs');

    });

});

//to delete the record
app.get('/views/del/:id', function (req, res) {
    let id = req.params.id;

    con.query("DELETE FROM user_data WHERE id='" + id + "'", function (err, data) {

        (err) ? console.log("error in delete data due to : " + err) : console.log("data has been delete for the user");
        (err) ? res.end("error in delete data due to : " + err) : res.redirect('/views/view_data.ejs');
    });

});

//to insert get data from form
app.post("/post_method",
    body('email').isEmail().isLength({ max: 255 }),
    body('name').isLength({ max: 255, min: 3 }),
    body('password').isLength({ min: 6, max: 15 }),
    function (req, res) {

        let sampleFile = req.files ? req.files.photo : null
        // console.log(req.files);

        let mysqlpath = null;

        //for validation
        const errors = validationResult(req);
        if (!errors.isEmpty()) {
            console.log(errors.mapped());
            return res.status(400).json({ errors: errors.array() });
        }

        if (sampleFile) {
            let uploadPath = __dirname + '/profile_photo/' + Date.now() + '_' + sampleFile.name;
            mysqlpath = '/profile_photo/' + Date.now() + '_' + sampleFile.name;

            sampleFile.mv(uploadPath, function (err) {
                (err) ? console.log(err) : '';
            });
        }

        var name = req.body.name;
        var email = req.body.email;
        var password = req.body.password;
        var gender = (req.body.gender == undefined) ? 'not choosen' : req.body.gender;

        console.log("\ndata got from submit\nname : " + name);
        console.log("email : " + email);
        console.log("password : " + password);
        console.log("gendor : " + gender);
        console.log("filepath : " + mysqlpath);

        con.query("INSERT INTO user_data(name,email,password,picpath,gender) VALUES('" + name + "','" + email + "','" + password + "','" + mysqlpath + "','" + gender + "')", function (err) {
            err ? console.log("data is not inserted due to : " + err) : console.log("data is inserted!");
            !err ? res.end("data is stored sucessfully!\nname : " + name + "\nemail : " + email + "\npassword : " + password + '\nFilepath:' + mysqlpath) : "";
        });

    });

//to listen at port no at 8081
app.listen(8081, function () {
    console.log("\nconnected at port no : " + this.address().port);
});
