var express = require("express");
var app = express();


// "/" => "HI"
app.get("/", function(req, res){
	res.send("HI THERE HOOMAN");
});

// "dog" => "woof" ... This example shows a shorter notation equivalent of above
app.get("/dog", (req, res) => res.send("dog says woof"))

// route parameters: used so that you don't have to define routes for thousands
// of pages. the colon indicates the variable. then typing anything into URL
// that matches the (e.g.) /r/anything pattern will return this message:
// app.get("/r/:subredditName", (req, res) => res.send("please stop looking at reddit"))

// now we actually plug a variable in there - what the user typed into the URL
app.get("/r/:subredditName", function(req, res){
	var subreddit = req.params.subredditName;
	res.send("Welcome to the " + subreddit  + " subreddit!");
});

// using other operators (wildcard in this case) for routing
// will show this special message instead of "cannot get page"
// this must come after defining other routes, or it will always display 404
app.get("*", (req, res) => res.send("OMG 404 LOL"))
	
app.listen(3000, function(){
	console.log("server has started, check localhost:3000");
});
