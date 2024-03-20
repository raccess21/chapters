/////////////////////------------------//////////////////
//populate h and label
function populate(h1, label) {
    document.getElementById("myH1").textContent = h1;
    document.getElementsByTagName("label")[0].textContent = label;
}

//logger to log message when coding on android
function logger(msg) {
    const div = document.getElementById("ps");
    div.innerHTML += `<p style="font-size: medium;">${div.childElementCount}. ${msg}</p>`;
}


//string methods
function strMethods() {
    let sampleStr = "HtecVncvLxwc   ";
    console.log(`Sample string: ${sampleStr}--`)
    console.log(`str.charAt(index)      : ${sampleStr.charAt(1)}`);      //value at index
    console.log(`str[2]                 : ${sampleStr[2]}`);             //value at index
    console.log(`str.indexof('c')       : ${sampleStr.indexOf('c')}`);   //index of first occurence
    console.log(`str.length             : ${sampleStr.length}`);         //length
    console.log(`str.trim()             : ${sampleStr.trim()}--`);         //removes leading/trailing space newlines
    console.log(`str.toLowercase()      : ${sampleStr.toLowerCase()}--`);         //length
    console.log(`str.repeat(times)      : ${sampleStr.repeat(2)}--`);         //repeat n times
    console.log(`str.startsWith('Ht')   : ${sampleStr.startsWith('Ht')}`);    //check if starts with
    console.log(`str.endsWith('Wc')     : ${sampleStr.endsWith('Wc')}`);    //check if ends with
    console.log(`str.includes('Wc')     : ${sampleStr.includes('Wc')}`);    
    console.log(`str.replaceAll('t','@'): ${sampleStr.replaceAll('t','@')}`); //replaceAll all occurence, replace first occurence
    console.log(`str.padStart(len,'0')  : ${sampleStr.padStart(25, '-')}`); //padEnds padding at end
    console.log(`str.includes('Wc')     : ${sampleStr.includes('Wc')}`);    
}

//how to slice strings in javascript
function strSlice() {
    let nm = "ywjwcjen acjkebc";
    console.log(`Original string  : ${nm}`);
    console.log(`Capitalised      : ${nm[0].toUpperCase() + nm.slice(1)}`);
    console.log(`Sliced (1, 12)   : ${nm.slice(1, 12)}`);
    console.log(`Sliced(-len, -1) : ${nm.slice(-nm.length, -1)}`);

    console.log(`Split @ space 1st: ${nm.slice(0, nm.indexOf(' '))}`);
    console.log(`Split @ space 2nd: ${nm.slice(nm.indexOf(' ') + 1)}`);

}

//exercise
//take string, remove leading/trailing spaces, capitalize and lower case everything else
function strFormat() {
    let nm = "  kkwebc akscbh  ";
    console.log(`Original String :  ${nm}`);
    nm = nm.trim()
    nm = nm.charAt(0).toUpperCase() + nm.slice(1).toLowerCase();    //method chaining
    console.log(`Formatted String:  ${nm}`);
}

//arrays
function arrays() {
    let games = ["cricket"];
    
    games.push("hockey", "rugby", "go");         //push item at the end
    games.push("football", "golf");         //push item at the end
    console.log(games.pop());               //pop item at the end
    games.unshift("chess");                 //add element in the beginning
    games.shift();                          //pop item at the beginning


    let i = 0;
    console.log(`index${i} : ${games[i++]}`);
    console.log(`index${i} : ${games[i++]}`);
    console.log(`index${i} : ${games[i++]}`);
    console.log(`index${i} : ${games[i++]}`);
    console.log(`index${i} : ${games[i++]}`);
    console.log(`index${i} : ${games[i++]}`);
    console.log(`Total games : ${games.length}`);
    console.log(`Indexof cri: ${games.indexOf("cricket")}`);

    console.log("Looping games - Method 1");
    for (let i = games.length-1; i >= 0; i--) {
        console.log(`games${i} : ${games[i]}`);
    }

    console.log(games);
    
    i = 0;
    console.log("Looping games - Method 2");
    for (game of games.sort().reverse()) {              //sorted and reversed
        console.log(`games${i++} : ${game}`);
    }

    //in js arrays are implemented as hashmaps so this is legal
    let a = [1,2,3];
    a[100] = 101;
    console.log(a);
}

//rest operator recieves array of parameters
function restParam(...games) {
    console.log("Rest parameter example");
    console.log(games);
    for (game of games) {
        console.log(game);
    }
}

//spread operator unpacks iterables into each of it's elements
function spreadParam() {
    let games = ["cricket", "football", "chess"];
    let gamesjoined = [...games].join("-");             ///... spread operator unpacks iterables
    console.log(gamesjoined);

    let activities = ["walking", "running"];
    console.log("Activities: " +  [...games, ...activities, "sleeping"]);
    restParam(games[0], games[1], games[2]);
}

//////////////////FUNCTIONS//////////////////////
//functions perform some functions

//USING DEFINITIONS
//function_name(parameters)            //function definition
function isEven(num) {
    return num % 2 === 0 ? true : false;
} 

function isEven2(num) {
    return num % 2 === 0;
}

function average(...num) {
    let sum = 0;
    for (let n of num) {
        sum += n;
    }
    return sum/num.length
}

function sentence(...strings) {
    return strings.join(" ");
}

//funcion_name(arguments)           //function call

strFormat();
console.log(isEven2(7));

//USING FUNCTION EXPRESSIONS OR VARIABLES
//in js functions can be used without definition by using 
//function expression. 
//the entire function can be passed as an argument
// or it can stored in a variable

setTimeout(function () {
    console.log(`Timeout!!`);
}, 2000);


const hello = function () {
    logger("ello mate!!");
};
hello();

//ARROW FUNCTIONS
// it is concise way of writing fun exp that are used only once
// (param) => code
const avg2 = (...num) => {
    let sum = 0;
    for (let n of num) {
        sum += Number(n);
    }
    return sum/num.length;
};

const avg3 = (...num) => {
    return num.reduce(function (accu, ele) {
        return accu + ele;
    }) / num.length;
};

const squares = [1,2,3,4,5].map((element) => Math.pow(element, 2));


console.log(`Average is ${avg3(1,2,3)}`);
logger(`Average is  : ${avg3(1,2,3)}`);
logger(`Squares are : ${squares}`);
//testing web codespace
//testing web codespace and pull
