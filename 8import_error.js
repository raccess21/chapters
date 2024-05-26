// import {PI, getCircumference} from './8import_error.js';

export const PI = 3.14153

export function getCircumference(radius) {
    return 2 * PI * radius;
}

export function getArea(radius) {
    return PI * radius * radius ;
}

export function getVolume(radius) {
    return 4/3 * PI * radius * radius * radius;
}


//----------------Error handling
// try    -> try executing code
// catch -> except error is raised then handle it
// throw -> throw custom errors
// finally -> always executed code (cleanup code, close requests)
export function checkNumber(val) {
    try{
        if(isNaN(val)) {
            throw new Error(`${val} is not a number`);
        }
    }
    catch(error) {
        console.error(`${error}`);
    }
    finally{
        console.log("Closing function");
    }
}