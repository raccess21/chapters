// Hooks = special features to use class like react features 
//          in functions without writing classes
//          useState, useEffect, useContext, useReducer, useCallback etc. 


// useState() => create stateful variable and a setter function to update 
//               it's value in virtual DOM and render the change
//               {name, setName}

import React, {useState} from 'react'
function UseState(){
    const [name, setName] = useState("Paw Paw");      //intialisation
    let [age, setAge] = useState(0);                    //intialisation

    const updateName = () => {
        setName("Test");
    }
    
    // multiple update ke liye updater function use krte h
    // qki react variable change pe vdom ko baar baar update nhi krta
    // functions trigger state change in react 
    // updater functions are queued -> prev state se next state ki calculation
    const updateAge = () => {
        setAge(a => a + 1);
        setAge(a => a + 1);
        setAge(a => a + 1);
    } 
    return (
        <div>
            <p>Name: {name}</p>
            <button className="styleButton" onClick={updateName}>Set Name</button>
            <p>Age: {age}</p>
            <button className="styleButton" onClick={updateAge}>Set Age</button>
        </div>
    )
}


/////////////////////////ONCHANGE//////////////////////////////////////
// onchange of usually input values / form / select etc elements
function OnChange(){
    const [name, setName] = useState("");
    const [qt, setqt] = useState(0);

    const handleChange = (event) => {
        setName(event.target.value);
    }

    const handleQ = (event) => {
        setqt(event.target.value);
    }

    return(
        <div>
            <input value={name} type="text" onChange={handleChange}/>
            <p>Name: {name}</p>
            <input value={qt} type="number" onChange={handleQ}/>
            <p>Quantity: {qt}</p>
        </div>
    )
}

function Update_Object(){
    const hnam = (event, key) => {
        console.log(key);
        setPm(p => {return {...p, [key]: event.target.value}});
    }
    const hage = (event) => {
        setPm(p => ({...p, age: event.target.value}));
    }
    
    const [pm, setPm] = useState({
        nam: "Marendra Nodi",
        age: "bahut jyada",
        math: "kaafi weak",
        origin: "paida nhi hue bhagwaan ne bheja hai"
    })

    return(
        <div>
            <p>
                Hmare PM {pm.nam} hain.
                Unki umar {pm.age} hai.
                Unki math {pm.math} hai.
                Wo {pm.origin}.
            </p>
            <input type="text" value={pm.nam} onChange={(e) => hnam(e, "nam")}/><br />
            <input type="text" value={pm.age} onChange={(e) => hnam(e, "age")}/><br />
            <input type="text" value={pm.math} onChange={(e) => hnam(e, "math")}/><br />
            <input type="text" value={pm.origin} onChange={(e) => hnam(e, "origin")}/><br />
        </div>
    )
}

function Update_Array(){
    const addC = () => {
        const newC = document.getElementById("cInp").value;
        document.getElementById("cInp").value = "";
        setC(c => ([...c, newC]));
    }
    
    const remC = (index) => {
        // setC(c => [c.splice(index, 1)]);
        setC(c => c.filter((_, i) => i != index))
    }

    const [corruption, setC] = useState([
        "Chalti Range Rover ke gate pe ltk kr yatra krna",
        "Chalte protest pr gaadi chadha dena",
        "PM ho ke press conference na krna"
    ])

    return(
        <div>
            <h2>Examples of Corruption</h2>
            <ul>
                {corruption.map((c, index) => 
                    <li key={index} onClick={() => remC(index)}>
                        {c}
                    </li>
                )}
            </ul>
            <input type="text" id="cInp" placeholder='Enter another example'/>
            <button onClick={addC}>Add</button>
        </div>
    )
}


function Update_Array_Object(){
    const [cands, setCand] = useState([]);

    const [newCand, setNewCand] = useState({
        nam: "",
        age: "",
        math: "",
        origin: ""
    });

    const addCand = (_, newC) => {
        setCand(c => [...c, newC]);
        setNewCand({
            nam: "",
            age: "",
            math: "",
            origin: ""
        });
    }
    
    const remCand = (index) => {
        setCand(c => c.filter((_, i) => i != index));
    }

    const addProp = (event, key) => setNewCand(c => ({...newCand, [key]: event.target.value}));
    
    return(
        <div>
            <h2>List of Candidates</h2>
            <ul>
                {cands.length > 0 && cands.map((cand, index) => 
                    <li key={index} onClick={() => remCand(index)}>
                        {cand.nam} {cand.age} {cand.math} {cand.origin} 
                    </li>
                )}
            </ul>
            <input type="text" placeholder="Enter name" value={newCand.nam} onChange={(e) => addProp(e, "nam")}/><br />
            <input type="text" placeholder="Enter age" value={newCand.age} onChange={(e) => addProp(e, "age")}/><br />
            <input type="text" placeholder="Enter math" value={newCand.math} onChange={(e) => addProp(e, "math")}/><br />
            <input type="text" placeholder="Enter origin" value={newCand.origin} onChange={(e) => addProp(e, "origin")}/><br />
            <button onClick={(e) => addCand(e, newCand)}>Add Candidate</button>
        </div>
    )
}

function Update_Array_Object2(){
    const [cands, setCand] = useState([]);
    const [cnam, setNam] = useState("");
    const [corigin, setOrigin] = useState("");
    
    const addCand = () => {
        const newCand = {
            nam: cnam,
            origin: corigin
        };
        console.log(newCand);
        setCand(c => [...c, newCand]);
        setNam("");
        setOrigin("");
    }
    
    const remCand = (index) => {
        setCand(c => c.filter((_, i) => i != index));
    }

    function hnam(event){setNam(event.target.value)};
    function horigin(event){setOrigin(event.target.value);}

    return(
        <div>
            <h2>List of Candidates</h2>
            <ul>
                {cands.map((cand, index) => 
                    <li key={index} onClick={() => remCand(index)}>
                    {/* onclick=remCand(index) li ko instantly delete kr ra tha. Ispe aadha ghanta waste kiya*/}
                        {cand.nam} {cand.origin} 
                    </li>
                )}
            </ul>
            <input type="text" placeholder="Enter name" value={cnam} onChange={hnam}/><br />
            <input type="text" placeholder="Enter origin" value={corigin} onChange={horigin}/><br />
            <button onClick={addCand}>Add Candidate</button>
        </div>
    )
}

export function L5_UseState(){
    return (<>
        {/* <UseState/>
        <OnChange/>
        <Update_Object/>
        <Update_Array/> */}
        <Update_Array_Object/>
    </>);
}

export default L5_UseState;