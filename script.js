import {PI, checkNumber, getCircumference} from './8import_error.js';

console.log(PI);
checkNumber('a');
//populate h and label
function populate(h1, label) {
    document.getElementById("myH1").textContent = h1;
    document.getElementsByTagusrname("label")[0].textContent = label;
}

//logger to log message when coding on android
function logger(msg) {
    const div = document.getElementById("ps");
    div.innerHTML += `<p style="font-size: medium;">${div.childElementCount}. ${msg}</p>`;
}

function header(msg) {
    const div = document.getElementsByTagName("title")[0];
    div.textContent = msg;
    document.getElementsByTagName("body")[0].innerHTML = msg.toLocaleString();
}
///CLOSURE///////////////////////
//function inside function for privatisation of variables while offering state maintenance
//in create counter count is only available inside the function
function createCounter() {
    let count = 0;

    function increment(val = 1) {
        count += val;
        console.log(count + ":using closures");
    }

    function decrement(val = 1) {
        count += -val;
        console.log(count + ":using closures");
    }
    return {in: increment, decrement};      
    //object returned has key name and key value as function name,
    //by default if only function name is returned it can be accessed using function name  
}

let ncount = createCounter();
ncount.in();
ncount.in(3);
ncount.decrement();
class counter {
    count = 0;

    in = function(val=1) {
        this.count += val;
        console.log(this.count + ":using classes");
    }
}
let ccount = new counter;
ccount.in();
ccount.in(3);

function paalo(i=1) {
    console.log("Paalo: " + i);
}

setTimeout(() => paalo(5), 3000);
setTimeout(paalo, 3000);

let timeOut;
function startTimer() {
    timeOut = setTimeout(() => window.alert("Action Complete"), 3000);
    console.log("Starting...");
}

function clearTimer() {
    clearTimeout(timeOut);
    console.log("Stopped!!!");
}