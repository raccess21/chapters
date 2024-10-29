// event -> anything tha changes the state of page like click key press



//////////////////ONCLICK BEHAVIOUR/////////////////////////
export function Button(){
    let count = 0;
    const handleClick = (name) => {
        count++;
        console.log(`${name} clicked ${count} times!!!`);
    };
    return (<button className="styleButton" onClick={() => handleClick("Korra")}>Click</button>);
}


/////////////////////EVENT//////////////////////////////
export function ButtonEvent(){
    const name = "Borra";
    // onclick function is automatically passed event
    const handleClick = (event) => {
        event.target.textContent = "Clicked";
        console.log(`${name} clicked ${event} times!!!`);
    };
    return (
        <button className="styleButton" onClick={(event) => handleClick(event)}>
            Click
        </button>
    );
}

// import 
export function Profile_Picture(){
    const imgUrl = "./src/assets/triangle.jpeg";
    const handleClick = (e) => e.target.style.display = "none";
    return (<img src={imgUrl} onClick={(e) => handleClick(e)}></img>);
}

export function L4_Events(){
    return <>
            <Button/>
            <br />
            <ButtonEvent/>
            <Profile_Picture/>
    </>
}
export default L4_Events