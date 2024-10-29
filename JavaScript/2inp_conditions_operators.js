/////////////////////------------------//////////////////

//taking input from user

//using input window
function inputWindow() {
    let name = window.prompt(`Enter name: `);
    document.getElementById("myH1").textContent = `Hello ${name}`;
}

//populate h and label
function populate(h1, label) {
    document.getElementById("myH1").textContent = h1;
    document.getElementsByTagName("label")[0].textContent = label;
}

//using custom input box
function inputter() {
    let name;
    populate("Hello Admin", "Enter Name: ");   
    document.getElementById("sub").onclick = function() {
        name = document.getElementById("inp").value;
        document.getElementById("myH1").textContent = `Hello ${name}`;
    }
}

//
function circumference() {
    const PI = 3.14159;
    populate("Calculate cirumference", "Enter Radius: ");    
    document.getElementById("sub").onclick = function() {
        let radius = Number(document.getElementById("inp").value);
        document.getElementById("myP").textContent = PI * 2 * radius + " units";
    }
}

///////////////-------------------------////////////////////
//CONDITIONALS

function ifElse() {
    populate("If else test", "Enter Age: ");
    
    document.getElementById("sub").onclick = function() {
        let text = "";
        const age = document.getElementById("inp").value;
        if (age > 18) {
            text += "You may enter."
            if (age > 60) {
                text += " Beware!!"
            }
        } else {
            text += "You can't enter.";
        }
        document.getElementById("myP").textContent = text;
    }
}

function moreOp() {
    populate("More operators test", "Enter Age: ");
    
    const PI  = 3.14;
    const PI2 = "3.14";                                 //assignment operators
    let mes = "";

    if (PI == PI2) {                                     //equality operator   
        mes += "PI and PI2 have equal values. PI and PI2 have ";
        if (PI === PI2) {                               //strict equality operator
            mes += "same data types.";
        }
        if (PI !== PI2) {                               //strict inequality operator
            mes += "different data types.";
        }
    }
    if (PI != PI2) {                                     //inequality operator   
        mes += "PI and PI2 have unequal values.";
    }
    console.log(mes);
}

function logicalOp() {
    populate("AND, OR, NOT test", "Enter Age: ");
    
    document.getElementById("sub").onclick = function() {
        let text = "";
        const age = document.getElementById("inp").value;
        if (age >= 18 && age < 60) {
            text += "You may enter. "
        }
        if (age > 60 || age < 0) {
            text += "Beware!! "
        }
        if (!(age > 18) && age >= 0) {
            text += "You can't enter. ";
        }
        document.getElementById("myP").textContent = text;
    }
}

function ternary() {
    populate("Ternary Test", "Enter Age: ");
    document.getElementById("sub").onclick = function() {
        const age = Number(document.getElementById("inp").value);
        let text = age > 18 ? "You can't enter." : "You may enter.";
        text += age > 60 ? " Beware!!!" : "";
        document.getElementById("myP").textContent = text;
    }
}

function switchCase() {
    populate("Switch Test", "Enter day: ");
    document.getElementById("sub").onclick = function() {
        const day = String(document.getElementById("inp").value).toLowerCase();
        let text = '';
        switch (true) {
            case day == 'sunday': 
                text += "Sunday is off.";
                break;
            case day == 'saturday' || day == "friday": 
                text += "Weekends are off.";
                break;
            case day == 'monday' || day == "tuesday" || day == "wednesday" || day == "thursday": 
                text += "Weekdays are on.";
                break;
            default:
                text += "Enter a valid Day."
        }
        document.getElementById("myP").textContent = text;
    }
}

moreOp();