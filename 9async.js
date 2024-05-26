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
