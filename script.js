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

function caller(age, name, sign) {return `${age} ${name} ${sign}`;}

// /OBJECTS are collection of related properties aand/or methods
// object = {key: value, function()}


//this keyword refers to the object in immediate context 
const person = {
    name: "reqwta",
    age: 312, 
    sign:  `RAAWRRR...`,
    callSign: function () {return caller(person.age, this.name, person.sign)},
    bullSign: () => {return this.age},              //this doesn't work with arrow operators
}
logger(person.callSign());
logger(this);

///////////CONSTRUTORS construct objects

function cPerson(name, age, sign) {
    this.name = name;
    this.age = age;
    this.sign = sign;
    // this.callSign = caller(this.age, this.name, this.sign);
    this.callSign = `${this.age} ${this.name} ${this.sign}`;
    return this;
}

const motu = cPerson("motu", 50, "modak");
logger(motu.callSign);


//CLASS are bluprints for objects for encapsulation of properties and method

class pearson{
    constructor (name, age, sign) {
        this.name = name;
        this.age = age;
        this.sign = sign;
        this.pear = this.birthyear();
        this.year = (() => {
            let cDate = new Date();
            let yob = cDate.getFullYear() - this.age;
            return `${yob-1} - ${yob+1}`;
        }) (); 
    }
    
    callSign =  function () {
        logger(`${this.age} ${this.name} ${this.sign} ${this.year} uisng function: ${this.pear}`);
    };

    birthyear = function () {
        let cDate = new Date();
        let yob = cDate.getFullYear() - this.age;
        return `${yob-1} - ${yob+1}`;
    };
}
const patlu = new pearson("patlu", 50, "battery");
patlu.callSign();
