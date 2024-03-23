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

///CLOSURE///////////////////////
//function inside function for privatisation of variables while offering state maintenance

function createCounter() {
    let count = 0;

    function increment(val = 1) {
        count += val;
        logger(count);
    }
    return {in: increment};
}

let ncount = createCounter();
ncount.in();
ncount.in(3);
