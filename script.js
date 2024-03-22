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

/////DESTRUCTURING///////////////////////////
function destructuringArray(bila, lila=10) {
    let a = 10;
    let b = 20;

    //destructuring of values and arrays using []
    [a, b] = [b, a];                //b and a destructured and restructured as a and b
    logger(`${a} , ${b}`);          //this results in swapping of values between a and b

    let fruits = ["apple", "banana", "chickoo", "dragonfruit"];
    
    const [ca, cb, ...etxra] = fruits;                      //multiple assignments
    logger(ca + " " + cb + " " + etxra.join(" "));          

    [fruits[1], fruits[3]] = [fruits[3], fruits[1]];        //destructuring for array element swap
    logger(fruits);

    if (lila===10) {
        lila = "ten";
    }
    logger(lila + bila);

}

//destructuring of objects uisng {}, values destructure based on keynames
function destructuringObject({age, name, job="none"}) {
    logger("Name: " + name + " Age: " + age + " Job: " + job);

    //job defaults to none
    const {agea, namea,  joba="none"} = {namea:"lala", agea:10, joba:"kala"};         
    logger("Name: " + namea + " Age: " + agea + " Job: " + joba);
}    

destructuringArray(90);
const person = {name: "naam", age: 20};
destructuringObject(person);


//NESTED OBJECTS -> object inside object
const fruito = {                            //object
    name: "banana",                         //string in object
    nutri: ["carb", "potas"],               //array in object
    color: {                                //object in object
        raw: "green",                       //string in object in object
        ripe: "yellow"
    }
}
logger(`${fruito.color.raw} ${fruito.nutri[1]}`);

const tools = [
    {name: "pen", job: "write"},
    {name: "ball", job: "play"},
    {name: "shoe", job: "wear"},
    {name: "shoes", job: "run"},
]
tools.forEach((element, array, index) => {array[index] = element.charAt(0).toUpperCase() + element.slice(1);});
logger(tools.map(tool => `${tool.name}-${tool.job}`).join(" | "));
