mysql = require('mysql');
var express = require('express');
var app = express();
bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({ extended: false }));

//var fs = require("fs");
//var df = require('dateformat');

var connection = mysql.createConnection({
  host: '10.42.0.157',
  port: '3000',
  user: 'sensor',
  password: '123',
  database: 'data'
});
connection.connect();


app.get('/', function (req, res) {
  console.log("temperature: " + req.query.temp);
  var html = "Temperature: "+ req.query.temp;

  res.send(html);

  var fs = require('fs');
  fs.appendFile('temperature.txt', "temperature: "+req.query.temp+"\n"  , function(err){
    if (err) throw err;
      console.log('temperature.txt: Saved!');
  }); 

 // rq = req.query;

  r={}; 
  r.seq=1; 
  r.type='T'; 
  r.device='102'; 
  r.unit='0'; 
 // r.ip="192.168.0.2"; 
 // r.value=rq.temp; 

  r.ip=req.ip;
  r.value=req.query.temp;
  var query = connection.query('insert into sensors set ?', r, function(err, rows, cols){
    if (err) throw err;
    console.log("DB: done");
  });  
});

app.listen(3000, function () {
  console.log('Example app listening on port 3000!');
});


