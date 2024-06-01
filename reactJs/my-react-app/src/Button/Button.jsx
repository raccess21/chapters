import styles from './Button.module.css'

function Button(){
    return (
        <div>
            <button className={styles.button}>Click Me</button>
        </div>
    );
}

export default Button