var express = require("express");
var app = express();

app.get("/", function(req, res){
	res.send("Hi there, welcome to my assignment!");
});

// Another way to do this is store each sound in a variable that gets
// plugged into the res.send statement, just one, at the end.
// And yet another way is to create a dictionary of animal sounds,
// key value pairs for each animal and sound.
/*
app.get("/speak/:animal", function(req, res){
	var animal = req.params.animal;
	if (animal === "cat"){
		res.send("The cat says, 'Meow!'");
	}
	else if (animal === "dog"){
		res.send("The dog says, 'Woof!'");
	}
	else if (animal === "pig"){
		res.send("The pig says, 'Oink oink!'");
	}
});
*/
app.get("/speak/:animal", function(req, res){
	var sounds = {
		pig: "Oink!",
		cat: "I hate you, human",
		dog: "Woof!",
		goldfish: "...",
	}
	var animal = req.params.animal.toLowerCase();
	var sound = sounds[animal];
	res.send("The " + animal + " says '" + sound + "'");
});

// This will repeat the :word :num number of times
app.get("/repeat/:word/:num", function(req, res){
	var num = parseInt(req.params.num, 10);
	var word = req.params.word;
	var result = "";
	for (var i = 0; i < num; i++){
		result += word + " ";
	}
	res.send(result);
});

app.get("*", function(req, res){
	res.send("Page not found. Breathe deeply.")
});

app.listen(3000, () => console.log("check localhost:3000"));
