// useRef()
// store and access value without triggering render when value changes
// Used in -> accessing/interacting with DOM elements
//            handling focus, animations, transitions
//            handling timers and intervals

import { useState, useRef, useEffect } from "react";

function Component(){
    const [ num, setNum ] = useState(0);
    const numr = useRef(0);
    const inputRef = useRef(null);

    useEffect(() => {
        console.log("COMPONENET RENDERED");
    });

    // handleClick causes num to change and page is rendered again
    function handleClick(){
        setNum(n => n +1);
        console.log(num);
    }

    // handleClickRef changes numr value but the page is not re-rendered
    function handleClickRef(){
        numr.current++;
        console.log(numr.current);
        inputRef.current.focus();
        inputRef.current.style.backgroundColor = "yellow";
    }

    return(<>
        <button onClick={handleClick}>Click</button>
        <br />
        <button onClick={handleClickRef}>ClickRef</button>
        <br />
        <input type="text" ref={inputRef}/>
        <br />
        <input type="text" ref={inputRef}/>

    </>);
}
function L8_UseRef(){
    return(<Component/>);

}

export default L8_UseRef;