const mysql = require("mysql");

//connection
const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",
    database: "user",
});

con.connect((err) =>
    err ? console.log("error in connection due to : " + err) : console.log("dabase connection succesfull!")
);

module.exports = con;