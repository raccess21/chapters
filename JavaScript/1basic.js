/*
This
   is a
       multiline comment 
       */

const PI = 3.14;                //global scope, pi accessible everywhere in this script
//logging a message on console
function logger(msg) {
    console.log(`Logging val: ${msg}\nLogging typ: ${typeof msg}`);
}

//creating alert window
function alerter(msg) {
    window.alert(`${msg}`);
}

/////////////-------------------------------/////////////
//WORKING WITH VARIABLES

//data types in js
function dataTypes() {
    let a = "pibloo";           //string
    let b = 10;                 //number                
    let c = 10.01;              //number
    let d = true;               //boolean -> true or false
    let e = 10;                 //
    
    logger(a);
    logger(b);
    logger(c);
    logger(d);
    logger(e);

}

//type conversion
function typeConversion() {
    let a = "12";
    const PI = 3.14;            //value of constants can't be changed
    console.log(a, typeof a);
    a += 1;
    console.log(a, typeof a);
    console.log(Number(a), typeof Number(a));
    console.log(boolean(''), typeof boolean(''));
    console.log(boolean(0), typeof boolean(0));
    console.log(boolean('ilya'), typeof boolean('ilya'));

    a = Number(a) + 1;
    console.log(a, typeof a);
}

//populating html tags with data in variables
function textOfElement(name, times) {
    document.getElementById("myH1").textContent = `Hello ${name}!!`;
    document.getElementById("myP").textContent = `Nimbudaa(${times} baar) trrrrr....`;
}


///////////----------------------------////////////////////
//OPERATORS

//arithmetic operators
function arithmetic() {
    let num1 = 10, num2 = 5;                        //num1 num2 have scope in arithmetic function only
    logger(`Addition      : ${num1 + num2}`);       //meaning they exist only inside this function
    logger(`Subtraction   : ${num1 - num2}`);
    logger(`Multiplication: ${num1 * num2}`);
    logger(`Division      : ${num1 / num2}`);
    logger(`Exponential   : ${num1 ** num2}`);
    logger(`Modulus       : ${num1 % num2}`);
    logger(`In/De crement : ${num1} ${num1+=2} ${num1++} ${num1} ${++num1}`);

    //Precedence -> () -> ** -> * / % -> + -
    //solving left to right
    logger(`Precedence   : ${num2 + num2**2*3}`);
    
}

textOfElement("Admin", 3);
arithmetic();


//////////////////////////////////////
function classListExplain(){
    //classList is list of class applied to an html element
    let h = document.getElementById("myH1");
    h.classList.add('cls1');                    //add a class
    h.classList.remove('cls1');                 //remove a class
    h.classList.toggle('cls1');                 //remove cls1 if present, add if not
    h.classList.replace('cls1', 'cls2');        //replace a cls1 with cls2
    h.classList.contains('cls1');               //if ele has cls1 as it's class return true else false
}