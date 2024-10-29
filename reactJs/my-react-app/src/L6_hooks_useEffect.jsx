// useEffect => run code when:
                // component mounts/created in dom  : mandatory
                // component re-renders             : optional
                // state of value changes           : optional
                // useEffect(function, [dependencies])
// useEffect(() => {})                  runs after every render
// useEffect(() => {}, [])              runs only on mount
// useEffect(() => {}, [values])        runs on mount + when value changes

// Used in:-
// Event Listeners, DOM manipulation, real-time updates
// Fetch data, clean up code for component unmount

import { useEffect, useState } from "react";

function My_Component(){
    const [count, setCount] = useState(0);

    useEffect(() => {
        document.title = `Counter: ${count}`;

        return () => {
            //CLEAN UP CODE
            //runs when component unmounts / re-renders
        }
    });

    return(<>
        <p>Count: {count}</p>
        <button onClick={() => setCount(c => c+1)}>Add</button>
    </>);
}

function Dimensions() {
    const [width, setWidth] = useState(window.innerWidth);
    const [height, setHeight] = useState(window.innerHeight);
    const [color, setColor] = useState({color: "green"});

    function handleResize(){
        setHeight(window.innerHeight);
        setWidth(window.innerWidth);
    }

    // only runs on mount since empty array passed as dependency
    useEffect(() => {
        window.addEventListener("resize", handleResize);
        console.log("Component mounted.");
        
        // returns function executes on unmounting of component
        return() => {
            window.removeEventListener("resize", handleResize);
            console.log("Component unmounted.");
        };

    }, []);

    // only runs if width or height changes
    useEffect(() => {
        document.title = `Size: ${width} x ${height}`;
        setColor({color: "green"});
        console.log("Width or height changed");

        // clean up runs when width height change process is complete
        return() => {
            setColor({color: "red"});
            console.log("Width or height cleanUP");
        }
    }, [width, height]);
    
    // runs every time component renders
    useEffect(() => {
        console.log("Component mounted or rendered.");

        // clean up runs on every render
        return() => {
            console.log("Always CleanUp");
        }
    });

    return (<>
        <p style={color}>Window width: {width}</p>
        <p style={color}>Window height: {height}</p>
    </>);
}

function L6_UseEffect(){
    return (<>
        <Dimensions/>
    </>);
}

export default L6_UseEffect 