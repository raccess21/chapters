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
class String {
    constructor (val) {
        this.val = val;
        this.length = (() =>  {return (this.val).length * 10;} )();
    }
}

//g is object of class String
let g = new String("asdf");
logger(g.length);
let b = "asdfa";
logger(b.length);

//STATIC
//objects own properties and methods
//static properties and objects are owned by class itself
//properties and methods are accessed using objectName.whatever 
class Pearson{
    static eats = true;         //static property (explained below)
    static pearsons = 0;

    constructor (name, age, sign) {
        logger("in registered indian.");
        this.name = name;
        this.age = age;
        this.sign = sign;
        this.pear = this.birthyear();
        this.year = (() => {
            let cDate = new Date();
            let yob = cDate.getFullYear() - this.age;
            return `${yob-1} - ${yob+1}`;
        }) (); 
        Pearson.pearsons++;         //accessed using class name
    }
    
    callSign =  function () {
        return `${this.age} ${this.name} ${this.sign} ${this.year}`;
    };
    
    birthyear = function () {
        let cDate = new Date();
        let yob = cDate.getFullYear() - this.age;
        return `${yob-1} - ${yob+1}`;
    };

    indainTrue = function () {
        return "We are Indains";
    }

    //static method
    static isAdult(obj) {
        return `${Pearson.pearsons} ${obj.name} is adult?: ${(obj.age >= 18)}`;
    }
}

//patlu is object of class Person
const patlu = new Pearson("patlu", 50, "battery");
logger(patlu.callSign());



//static behaviours are accessed using claaName.whatever
logger(Pearson.eats);       
logger(Pearson.isAdult(patlu));


///////////INHERITACE//////////////////////////////
//a new/child class can inherit property of an parent/super class, 
// like a child inherits properties from it's parent

class Indain extends Pearson {
    country = "Indai";
    wantToSalute = true;
    singAnthem = true;
    changeSalute()  {
        this.wantToSalute = (this.wantToSalute? false: true);
    };
}

const feriWala = new Indain(); 
logger(feriWala.country);
//Indain feriwala has country property
logger(feriWala.indainTrue());   
//Indain feriwala inherited indainTrue method from Pearson class
feriWala.changeSalute();     
//feriwala accessing it's changeSalute method
logger(feriWala.wantToSalute);  
//now want to salute is set to false


//this enables custom/unique properties for child classes making code more usable
//and easeier to model real world objects
//like indains can choose to salute while North Kareans can't. 
class NorthKarea extends Pearson {
    country = "North Karea";
    wantToSalute = true;
    singAnthem = true;
    changeSalute(salute)  {
        logger("Who will want to not SALUTE?");
        this.wantToSalute = true;                          
//change salute always sets want to salute property to true
    };
}

//of course both of them have to sing national anthems whenever demanded as a token of patriotism...
//Let's understand how Indains will register their name, age and YOB by passing values to superclass Pearson


class registeredIndain extends Pearson {
    //constructor of registered calls constructor of its super/parent class Pearson
    constructor (name, age, sign) {             //and passes name, age and sign info
        logger("in registered indian.");
        super(name, age, sign);
        this.country = "Indai";
        this.wantToSalute = true;
        this.singAnthem = true;
    }
    changeSalute()  {
        this.wantToSalute = (this.wantToSalute? false: true);
    };
    parichay() {
        return this.callSign() + `  from ${this.country}  SINGS ANTHEM: ${this.singAnthem} and SALUTES: ${this.wantToSalute}`;
    };
}

//parichay function can be used by any country men as long as they have identical 
//properties like country, salute and anthem and have a parent class Pearson

//Here aamwani passes name, age and sign as registration details for pearson class
const Aamwani = new registeredIndain("Malda Aamwani", 66, "green petrol");
logger(Aamwani.parichay());



//////////////////////////////////////////////////////////////////////////
//Getters ->    special method used to property read  of the object 
//Setters ->    special method used to property write of the object
//getters are setters are called without using ()
class Paarson {
    constructor(name, lS) {
        this.name = name;
        this.loveSupreme = lS;
    }

    // getter and property name can't be same otherwise they will
    //keep calling each other recursively, _ is naming convention,
    //we can use any naming convention we like
    set name( naam) {
        this.naamu = naam;              //name is saved in this.naamu instead of this._name
    }

    //sets lovesupreme, if value is invalid loveSupreme defaults to true
    set loveSupreme(lS) {
        if (typeof lS !== 'boolean') {
            logger("Invalid argument. Maybe you love supreme leader too much.")
            lS = true;
        }
        this._loveSupreme = lS;
    }

    //returns value of _loveSupreme
    get loveSupreme() {
        return this._loveSupreme;
    }

    get name() {
        return this.naamu;          //this.naamu is returned when name this.name is accessed
    }

    get canThink() {              
        logger("If you can think you most likely love Supreme leader");
        return this._loveSupreme;
    }

}

const munnaBhai = new Paarson("munnaBhai", false);
logger(`Can ${munnaBhai.name} think?: ${munnaBhai.canThink}`);

