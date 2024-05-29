//populate h and label
function populate(h1, label) {
    document.getElementById("myH1").textContent = h1;
    document.getElementsByTagusrname("label")[0].textContent = label;
}

function whileLoop() {
    let usrname = "";
    while(usrname === "" || usrname === null) {
        usrname = window.prompt("Enter usrname: ");
    }
    console.log(`You entered ${usrname}.`)
}

function doWhileLoop() {
    let usrname;
    do {
        usrname = window.prompt("Enter usrname: ");
    } while (usrname === "" || usrname === null)

    console.log(`You entered ${usrname}.`)
}

function forLoop() {
    let usrname;
    for (
            let i='initialise counter' ; 
            usrname === "" || usrname === null || usrname === undefined ; 
            'update command'
        ) {
        usrname = window.prompt("Enter username: ");
    }
    console.log(`You entered ${usrname}.`)

}

forLoop();