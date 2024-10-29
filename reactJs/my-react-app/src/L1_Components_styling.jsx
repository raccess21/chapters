import profile_pic from "./assets/triangle.jpeg"
import Button from "./Button/Button";

// components are standalone jsx functions that 
// translate(by returning) into a full html element

// food component
export function Food(){
    const food1 = "Parantha";
    const food2 = "Achaar";

    return(
        <ul>
            <li>Apple</li>
            <li>{food1}</li>
            <li>{food2.toUpperCase()}</li>
        </ul>
    );
}

// footer component
function Footer(){
    return(
        <footer>
            <p>&copy; {new Date().getFullYear()} My Website Name</p>
        </footer>
    );
}

function Header(){
    return(
        <header>
            <h1>My Website</h1>
            <nav>
                <ul>
                    <li><a href="#">Home</a></li>
                    <li><a href="#">About</a></li>
                    <li><a href="#">Services</a></li>
                    <li><a href="#">Contact</a></li>
                </ul>
            </nav>
            <hr />
        </header>
    );
}

// //////////////////////STYLING//////////////////////
// 1. EXTERNAL
// 2. MODULES
// 3. INLINE

// 1. external styling using external css stylesheets -> id/class/tages etc
function Card(){
    return(
        <div className="card">
            <img className="card-image" src={profile_pic} alt="Profile Picture" />
            <h2 className="card-title">@Raccess21</h2>
            <p className="card-text">Now I've become destroyer of Worlds!</p>
        </div>
    );
}

// 2. MODULES
// e.g Button in separate Button folder with custom css in it's directory
// unique classnames are dynamically created to avoid naming conflicts
// component_name.module.css -> naming convention for module styling

// 3. INLINE
function Button2(){
    const styles = {
        backgroundColor: "hsl(100, 100%, 50%)",
        color: "black",
        padding: "10px 20px",
        borderRadius: "5px",
        border: "none",
        cursor: "pointer"
    }
    return (
        <button style={styles}>Click Me</button>
    )
}

// components are reusable
export function Lesson_1_Components(){
    return (
        <>
            <Header/>
            <div className="card-container">
                <Card/>
                <Card/>
                <Card/>
                <Card/>
                <Card/>
            </div>
            <Food/>
            <Button/>
            <Button2/>
            <Footer/>
        </>
    );
}


// gets exported by default 
export default Lesson_1_Components