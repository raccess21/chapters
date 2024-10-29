import PropTypes from 'prop-types'

function L3_Lists(props){
    const gods = [
        {id: 1, name: "Rame", power: 95},
        {id: 2, name: "Krashan", power: 97},
        {id: 3, name: "Ginash", power: 90},
        {id: 4, name: "Ginash", power: 90}
    ];
    
    return(
        <ListProp gods={gods} categor={"ETA"}/>
    );
}

export function List(){
    // each item in a list should have unique key prop
    const gods = [
        {id: 1, name: "Rame", power: 95},
        {id: 2, name: "Krashan", power: 97},
        {id: 3, name: "Ginash", power: 90},
        {id: 4, name: "Ginash", power: 90}
    ];
    
    const naamSort = getLi(gods.sort((a, b) => a.name.localeCompare(b.name)));
    const powerSort = getLi(gods.sort((a,b) => a.power - b.power));
    const powerFilter = getLi(gods.filter(god => god.power > 95));

    return (
        <>
            <ol className="listItem">Bada God{naamSort}</ol>
            <ol className="listIttem">Power God{powerSort}</ol>
            <ol className="listIttem">PowerFull God{powerFilter}</ol>
        </>
    );
}

// getLi gods ke hr god ko li element me wrap kr deta hai
function getLi(gods){
    return gods.map(god => <li key={god.id}>
        {god.name.toUpperCase()}: &nbsp;
        <b>{god.power}</b>
    </li>);
}

//////////////////PROP TYPE FOR LISTER///////////////////////
function Lister(props){
    const godl = props.gods.map(god => <li key={god.id}>
        {god.name.toUpperCase()}: &nbsp;
        <b>{god.power}</b>
    </li>);
    return <>
            <h1 className="listCat">Jyada Gods</h1>
            <ol className="listItem">{godl}</ol>
        </>
}

Lister.propTypes = {
    gods: PropTypes.arrayOf(PropTypes.shape({
        id: PropTypes.number,
        name: PropTypes.string,
        power: PropTypes.number
    }))
}

export function ListProp(props){
    const gods = props.gods;
    return (
        <>
            <h1 className="listCat">Jyada Gods {props.categor}</h1>
            {gods.length > 0 ? <ol className="listItem">
                    {getLi([...gods, {id:5, name: "Porbti", power: 100}])}
            </ol> : null}
            {gods.length > 0 && <Lister gods={gods}/>}
        </>
    );
}

export default L3_Lists