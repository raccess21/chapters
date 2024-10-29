import { useContext } from "react";
import { userContext } from "./L7_hooks_useContext.jsx";

export function Component2(){
    return(
        <div className="box">
        <h1>Component2</h1>
        <Component3/>
        </div>    
    );
}

export function Component3(){
    return(
        <div className="box">
        <h1>Component3</h1>
        <Component4/>
        </div>    
    );
}

export function Component4(){
    const user = useContext(userContext);
    
    return(
        <div className="box">
        <h1>Component4</h1>
        <h2>Hi {user}.</h2>
        </div>    
    );
}
