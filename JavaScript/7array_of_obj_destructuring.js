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

//fischer yates algo
function shuffle(cards) {
    for (let i = cards.length-1; i > 0; i--) {
        const random = Math.floor(Math.random() * (i + 1));
        [cards[i], cards[random]] = [cards[random], cards[i]];
    }
    return cards;
}
logger(shuffle([1,2,3,4,5,6,7,8,9]));


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
    {name: "pen", job: "write", con: "in" , val: 5},
    {name: "ball", job: "play", con: "out", val: 2},
    {name: "shoe", job: "wear", con: "out", val: 1},
    {name: "shoes", job: "run", con: "out", val: 3},
]

//For each on object
tools.forEach((element, index, array) => {
    array[index].name = element.name.charAt(0).toUpperCase() + element.name.slice(1);
});
tools.forEach((tool) => {
        logger (`name: ${tool.name} | job: ${tool.name} | con: ${tool.con}`)
    });


//Map for objects
logger(tools.map(tool => `${tool.name}-${tool.job}`).join(" | "));

//filter for objects
logger("Outdoor tools: " + 
        tools.filter(tool => tool.con == "out")
        .map(tool => `${tool.name}-${tool.job}/${tool.con}`)
    );

function reductor(accu, ele) {
    // logger(accu.name +  ele.name);
    if (accu.con == "out") {
        return accu;
    }
}

//reduce for objects reduces array of objects to single object
logger("Most valuable tool: " + tools.reduce((accu, tool) => 
            accu.val > tool.val ? accu : tool).name
        );

//array of object sorting
tools.sort((a,b) => a.val - b.val);       //based on values
logger(tools.map(tool => `${tool.name}-${tool.job}/${tool.con}`));
tools.sort((a,b) => a.name.localeCompare(b.name));       //based on names
logger(tools.map(tool => `${tool.name}-${tool.job}/${tool.con}`));