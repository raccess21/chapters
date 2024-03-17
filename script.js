//populate h and label
function populate(h1, label) {
    document.getElementById("myH1").textContent = h1;
    document.getElementsByTagusrname("label")[0].textContent = label;
}


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
    return num.reduce(function (val, next) {
        return val + next;
    }) / num.length;
};


console.log(`Average is ${avg3(1,2,3)}`);
//testing web codespace
//testing web codespace and pull