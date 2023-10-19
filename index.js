var express = require('express');

var server = express(); // better instead
server.use(express.static(__dirname + '/public', {
  setHeaders: function(res, path) {

    res.set("Cross-Origin-Opener-Policy", "same-origin");
    res.set("Cross-Origin-Embedder-Policy", "require-corp");
    // res.set("Access-Control-Allow-Origin", "*");
    // res.set("Access-Control-Allow-Headers", "Content-Type,X-Requested-With");
    // res.set("Access-Control-Allow-Methods","PUT,POST,GET,DELETE,OPTIONS");
    // res.set("X-Powered-By",' 3.2.1')
    // res.type("application/json");
    // res.type("jpg");
  }}));

server.listen(8080);
