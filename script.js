//populate h and label
function populate(h1, label) {
    document.getElementById("myH1").textContent = h1;
    document.getElementsByTagusrname("label")[0].textContent = label;
}

/////////////CALLBACK//////////////////////////
//callback -> when functions are passed as parameter to ensure flow of control in a desired manner
function isPrime(callback, num) {
    let factors = [1];

    if (num >= 2) {
        for (let i = 2; i < num/2; i++) {
            if (num % i == 0) {
                factors.push(i);
            }
        }
    }
    callback(num, factors);
}

function primeStatus(num, factors) {
    let res = factors.length < 2;
    console.log(`${num} is Prime? : ${res}`);
    console.log(`Factors other than ${num}: `);
    factors.forEach(displayArray);
}
isPrime(primeStatus, 27);

//////////////////ARRAY METHODS////////////////////////////////

//FOREACH
//array.forEach method passes callback function, element index and array 
//passed in order -> element, index, array
//under the hood automatically
function displayArray(elemental, array, index) {
    console.log(`** ${elemental} ** array: ${index} -- index: ${array}`);
}

//original array is manipulated using forEach callback
function capitalize(element, index, array) {
    array[index] = element.charAt(0).toUpperCase() + element.slice(1);
}
names = ["ram", "rawan", "lakshman"]
console.log(names.forEach(capitalize));                 //original names is changed 


//MAP
//map method creates new resulting array from original array
//a new array is mapped in terms of the change defined in callback and original array
function capitalize2(element) {
    return element.charAt(0) + element.charAt(1).toUpperCase() + element.slice(1);
} 
console.log(names.map(capitalize2));                    //names is unchanged after map process

//another example of map
function formatDate(element) {
    const dp = element.split("-");
    return `${dp[0]}/${dp[1]}/${dp[2]}`;
}
console.log(["23-01-24", "13-01-98"].map(formatDate));  //map

//FILTER
//filter creates new array by filtering out elements
//if function returns false for element, it is discarded
function isEven(element) {
    return element % 2 === 0;
}
console.log("Filter eg. is even: " + [1, 2, 3, 4, 5, 6].filter(isEven));         //filter


//REDUCE
//reduces the array to a single value using a callback function
//automatically iterated over every element of array
//accu initialises to first element and element is next element
//return value is put in accumulator, accu is returned at the end
function sum(accumulator, element) {
    console.log(accumulator, element)
    return accumulator + element;
}
console.log("Reduce example sum: " + [5,2,3].reduce(sum));

function ajeebAverage(val, next) {
    return (val + next)/2;
}
console.log("Ajeeb Average: " + [1,2,3,4,5,6].reduce(ajeebAverage));

setTimeout(function () {
    console.log(`Timeout!!`);
}, 2000);