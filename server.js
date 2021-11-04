// http server

var http = require('http');
var express = require('express');
var app = express();
var server = http.createServer(app);
var io = require('socket.io').listen(server);

// app.configure(function(){
// 	app.use(express.static(__dirname + '/public'));
// 	app.use(express.errorHandler({ dumpExceptions: true, showStack: true }));
// });

app.use(express.static(__dirname + '/public'));

app.get('/', function(req, res){
	res.sendfile(__dirname + '/index.html');
});

io.sockets.on('connection', function(socket){
	socket.on('message', function(data){
		io.sockets.emit('message', data);
	});
});

server.listen(3000);