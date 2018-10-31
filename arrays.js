window.setTimeout(function() {
  // put all of your JS code from the lecture here

var todos = [];

var input = prompt("What would you like to do?")


while(input !== "quit") {
	
	if(input === "list") {
	console.log(todos);
	} 	else if(input == "new") {
		//ask for new todo and add to new todos array
		var newTodo = prompt("Enter new todo");
		todos.push(newTodo);
		}
var input = prompt("What would you like to do?")
}

console.log("Goodbye")
}, 500);
