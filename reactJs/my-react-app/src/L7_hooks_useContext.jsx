// useContext()
// React Hook to share values between multiple level of components
// without passing props 

// PROVIDER COMPONENT -> createContext and export it
// CONSUMER COMPONENT -> useContext    and import it

import { useState, createContext } from "react"
import {Component2} from "./L7_hooks_useContext_compo.jsx"

export const userContext = createContext();

function Component1(){
    const [user, setUser] = useState("raccess21");

    return(
        <div className="box">
        <h1>Component1</h1>
        <h2>Hello: {user}</h2>
        <userContext.Provider value={user}>
            <Component2 user={user}/>
        </userContext.Provider>
        </div>    
    );
}


function L7_UseContext(){
    return(<Component1/>);
}

export default L7_UseContext;