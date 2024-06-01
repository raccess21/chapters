import Test from "./Test.jsx"

import {
    Lesson_1_Components, 
    Food
} from "./L1_Components_styling.jsx"            //{} for multiple imports 
import * as bk from "./L2_props.jsx"            //from import all 



function App(){
    return (
    <>
        <Test/>
        <Lesson_1_Components/>
        <bk.Lesson_2_Props/>
    </> 
    );
}

export default App
