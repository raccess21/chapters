function Test(props){
    return(
        <List/>
    );
}

export function List(){
    const gods = ["Rame", "Krashan", "Ginash"];
    const gods2 = gods.map(god => <li>{god.toUpperCase()}</li>);
    // gods.forEach((god, ind, arr) => arr[ind] = `<li>${god}</li>`);
    
    return (
        <>
            <ol>Bada God
                {gods2}
            </ol>
        </>
    );
}

export default Test