// PROPS -> properties that can be shared between components
// parent -> child in format <COMPONENT key = value />

export function Student(props){
    return(
        <div className="student">
            <p>Name: {props.name}</p>
            <p>Age: {props.age}</p>
            <p>Student: {props.isStu ? "Yes" : "No"}</p>
        </div>
    );
}

// //////////////////PROP TYPES//////////////////////////////
// prop value ka data type check krne khatir
// react warning dega type mismatch ka 

import PropTypes from 'prop-types'
Student.propTypes = {
    name: PropTypes.string,
    age: PropTypes.number,
    isStu: PropTypes.bool
}

// DEFAULT PROPS -> default values
Student.defaultProps = {
    name: "Aafreen",
    age: 786,
    isStu: false 
}

///////////////////////////////////////////
// CONDITIONAL rendering -> show/hide based on props
export function UserGreeting(props){
    const welcome_mes = `Welcome! ${props.uName}`;
    const log_mes = <h2 className="login-prompt">
                        Please log in to Continue {props.uName}
                    </h2>;
    
    if(props.uName == "raccess21"){
        return (
            props.isLogged ? <h2 className="welcome-mes">{welcome_mes}</h2> :
            <>{log_mes} {log_mes}</>
        );
    }
    else{
        return;                                         //nothing rendered in this case
    }
}

UserGreeting.defaultProps = {
    isLogged: false,
    uName: "Guest"
}

export function Lesson_2_Props(){
    return (
    <>
        <Student name="@raccess21" age={1008} isStu={true}/>
        <Student name="brahmamama" age="infinity" isStu={false}/>
        <Student/>
        <UserGreeting isLogged={false} uName="raccess21"/>
    </> 
    );
}

export default Lesson_2_Props