// //////////////////////FETCH//////////////////////
// fetch -> HTTP request for fetching resources at a url
// GET, POST, PUT(replace), DELETE


////////////////////// JSON -> JavaScript Object Notation
// data format for storing and interchanging data(arrays and objects)
// resource_data.json 

let names = ['aam', 'bam', 'cham', 'dam'];
//convert json object/array in a single string
names = JSON.stringify(names)                    
console.log("names object as string: " + names);

let naams = '[{"naam": "cooler", "kaam":"cooling"}, {"naam": "cs50", "kaam": "educator"}]';
//convert string into json object/array
naams = JSON.parse(naams)                   
console.log(naams);

// fetch returns a PROMISE to get a file
let filePath = "resource_data.json";        //!!GLT FILEPATH TRY KRO
fetch(filePath)                             //filename (relative/absolute) le ke  aao
    .then(response => response.json())      //aagyi/resolved to json me convert kro
    .then(value => console.log(value))      //ho gya to console pe print kro
    .catch(error => console.error(error));  //koi error/rejected hua to error print



// ////////////////////API/////////////////
fetch("https://pokeapi.co/api/v2/pokemon/pikachu")
    .then(resp => {
        if(!resp.ok){
            throw new Error("Couldn't fetch data")
        }
        return resp.json()})
    .then(data => {
        console.log(`Name is ${data.name}`)
    })
    .catch(error => {console.error(error)});


async function fetchData(){
    try{
        const resp = await fetch("https://pokeapi.co/api/v2/pokemon/typhlosion");
        if(resp.ok){
            const data = await resp.json();
            return data;
        }
        else{
            throw new Error("Couldn't fetch data");
        }
    }
    catch(error){
        console.error(error);
    }
}

fetchData();