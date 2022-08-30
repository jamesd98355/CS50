// buttons change colour when clicked

let button1 = document.getElementById("button1");
let button2 = document.getElementById("button2");
let button3 = document.getElementById("button3");
let textBox = document.getElementById("input1");
let submit = document.getElementById("input");


button1.addEventListener("click", () => {
    button1.style.backgroundColor = "red";
})

button2.addEventListener("click", () => {
    button2.style.backgroundColor = "#7FFFD4";
})
button3.addEventListener("click", () => {
    button3.style.backgroundColor = "red";
})

submit.addEventListener("click", () => {
    textBox.style.backgroundColor = "#7FFFD4";
})