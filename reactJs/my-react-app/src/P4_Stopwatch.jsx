import { useEffect, useState, useRef } from "react";
import "./styles/P4_Stopwatch.css"

function Stopwatch(){
    const [isRunning, setIsRunning] = useState(false);
    const [ elapsedTime, setElapsedTime ] = useState(0);
    
    const intervalIdRef = useRef(null);
    const startTimeRef = useRef(0);

    useEffect(() => {
        if(isRunning){
            intervalIdRef.current = setInterval(() => {
                setElapsedTime(Date.now() - startTimeRef.current);
            }, 10);
        }

        return() => {
            clearInterval(intervalIdRef.current);
        }
    }, [isRunning]);
    
    function start(){
        setIsRunning(true);
        startTimeRef.current = Date.now() - elapsedTime;
    }
    function stop(){
        setIsRunning(false);
    }
    function reset(){
        setIsRunning(false);
        setElapsedTime(0);
    }
    function formatTime(){
        let hrs = String(Math.floor(elapsedTime / (1000 * 60 * 60))).padStart(2, '0');
        let min = String(Math.floor(elapsedTime / (1000 * 60) % 60)).padStart(2, '0');
        let sec = String(Math.floor(elapsedTime / (1000) % 60)).padStart(2, '0');
        let ms  = String(Math.floor((elapsedTime % 1000) / 10)).padStart(2, '0');
        
        return `${min}:${sec}:${ms}`
    }

    return(
        <div className="stopwatch">
            <div className="display">{formatTime()}</div>
            <div className="controls">
                <button onClick={start} className="start-button">Start</button>
                <button onClick={stop} className="stop-button">Stop</button>
                <button onClick={reset} className="reset-button">Reset</button>
            </div>
        </div>
    );
}

export default Stopwatch;