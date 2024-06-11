import { useState, useEffect } from "react";
import "./styles/P3_Clock.css"

function Clock(){
    const [time, setTime] = useState(new Date());

    useEffect(() => {
        const intervalId = setInterval(() => {
            setTime(new Date());
        }, 1000);

        return() => {
            clearInterval(intervalId);
        }
    }, []);

    function formatTime() {
        let hrs = time.getHours();
        const min = time.getMinutes();
        const sec = time.getSeconds();
        const meri = hrs > 12 ? "PM" : "AM";

        hrs = hrs % 12 || 12;
        return `${pad(hrs)}:${pad(min)}:${pad(sec)}`;
    }

    function pad(num) {
        return (num < 10 ? "0" : "") + num; 
    }
    return (
        <div className="clockContainer">
            <div className="clock">
                <span>{formatTime()}</span>
            </div>
        </div>
    );
}

export default Clock;