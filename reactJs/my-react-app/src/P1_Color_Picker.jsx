import React, {useState} from "react";
import "styles/P1_Color_Picker.css"

function Color_Picker(){
    const [color, setColor] = useState("#FFFFFF");
    
    const handle = (event) => {
        setColor(event.target.value);
    }

    return(
        <>
            <div className="color-picker-container">
                <h1>Color Picker</h1>
                <div className="color-display" style={{backgroundColor: color}}>
                    <p>Selected Color: {color}</p>
                </div>
                <label htmlFor="">Select a color:</label>
                <input type="color" value={color} onChange={handle}/>
            </div>
        </>
    );
}

export default Color_Picker