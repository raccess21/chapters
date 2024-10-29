// async allows multiple operations to be performed concurrently
// improves functionality of blocks that take indefinite amount of time to execute
// I/O, requests, fetch
// handled by -> callbacks, promises, async/await

function jenpai(callback){
    setTimeout(() => {              //setTimeout is an async function
        console.log("Task 1");
        callback();
    }, 3000);
    console.log("Task 4");          //task 4 executed before timeout
}

function senpai(){
    console.log("Task 2");
    console.log("Task 3");
}

jenpai(senpai);
console.log("Task 5");              //task 5 executed before jenpai


// callback hell is when in order to mandate flow of control in an async code
// callbacks used get exceedingly complex.

function noteCheck(callback){
    setTimeout(() => {
        console.log("Governor note check kr liye hain.");
        callback();
    }, 3000);
}

function noteBdli(callback){
    setTimeout(() => {
        console.log("Note bdl diya gya.");
        callback();
    }, 1500);
}

function blackMoneyAaya(callback){
    console.log("Tijori me wapis aaye black money ki report bn rhi hai.");
    setTimeout(() => {
        callback();
    }, 100000000);
}

noteCheck(() => {
    noteBdli(() => {
        blackMoneyAaya(() => {
            console.log("Tijori me  black money aa gya hai SAARA.");
        });
    });
});

/////////////////////////PROMISE////////////////////////////////////////
// promise object handles async operations that need to follow a certain flow of control
// wrap promise object around async code that will eventually return a value
// PENDING -> RESOLVED or REJECTED

function noteCheckPromise(){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("Promise! Governor note check kr liye hain.");
        }, 3000);
    });
}

function noteBdliPromise(){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("Promise! Note bdl diya gya.");
        }, 10000);
    });
}

function blackMoneyAayaPromise(){
    console.log("Promise! Tijori me wapis aaye black money ki report bn rhi hai.");
    let t1 = Date.now();
    return new Promise((resolve, reject) => {
        const timer = setTimeout(() => {
            reject("Popa nahi ho pa ra. Sorry!");
        }, 100000);

        setTimeout(() => {
            clearTimeout(timer);
            resolve("Promise! Tijori me  black money aa gya hai SAARA.");
        }, 100000000);
    });
}

// promise and method chaining
noteCheckPromise().then(value => {console.log(value); return noteBdliPromise(); })
                .then(value => {console.log(value); return blackMoneyAayaPromise(); })
                .then(value => {console.log(value);})
                .catch(error => {console.log(error);});


/////////////////////////////ASYNC/AWAIT//////////////////////////////////////////
// ASYNC - make function return a promise
// AWAIT - make async function wait for a promise
// async/await doesn't have resolve-reject model !! write async code in sync manner
// everything after await is placed in event queue

// callback hell is when in order to mandate flow of control in an async code
// callbacks used get exceedingly complex.

async function deMonetisation(){
    try{
        const noteCheckResult = await noteCheckPromise();
        console.log(noteCheckResult);
        
        const noteBdliResult = await noteBdliPromise();
        console.log(noteBdliResult);
        
        const blackMoneyAayaResult = await blackMoneyAayaPromise();
        console.log(blackMoneyAayaResult);
    }
    catch(error){
        console.error(error);
    }
}

deMonetisation();
