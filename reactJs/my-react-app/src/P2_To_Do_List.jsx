import React, {useState} from "react";
import "./styles/P2_To_Do_List.css"

function To_Do_List(){
    const [tasks, setTasks] = useState(["Eat", "Sleep"]);
    const [newTask, setNewTask] = useState("");

    function inpChange(event){
        setNewTask(event.target.value);
    }

    function addTask(){
        if(newTask.trim() !== ""){
            setTasks(t => [...t, newTask])
            setNewTask("")
        }
    }

    function deleteTask(index){
        setTasks(tasks.filter((_, i) => i != index));
    }

    function moveTask(index, i){
        if(index > 0 && i < 0 || index < tasks.length-1 && i > 0){
            const newTasks = [...tasks];
            [newTasks[index], newTasks[index+i]] = [newTasks[index+i], newTasks[index]]
            setTasks(newTasks);
        }
    }

    function moveTaskUp(index){
        if(index > 0){
            const newTasks = [...tasks];
            [newTasks[index], newTasks[index-1]] = [newTasks[index-1], newTasks[index]]
            setTasks(newTasks);
        }
    }

    function moveTaskDown(index){
        if(index < tasks.length-1){
            const newTasks = [...tasks];
            [newTasks[index], newTasks[index+1]] = [newTasks[index+1], newTasks[index]]
            setTasks(newTasks);
        }
    }

    return(
        <div className="to_do_list">
            <h1>To_Do List</h1>
            <div>
                <input 
                    type="text"
                    placeholder="Enter a task"
                    value={newTask}
                    onChange={inpChange}/>
                <button 
                    className="add_button"
                    onClick={addTask}>
                    Add
                </button>
            </div>

            <ol>
                {tasks.map((task, index) => 
                    <li key={index}>
                        <span className="text">{task}</span>
                        <button
                            className="delete_button"
                            onClick={() => deleteTask(index)}>
                            Delete
                        </button>
                        <button
                            className="move_button"
                            onClick={() => moveTask(index, -1)}>
                            Move ⬆️
                        </button>
                        <button
                            className="move_button"
                            onClick={() => moveTask(index, 1)}>
                            Move ⬇️
                        </button>
                    </li>
                )}
            </ol>
        </div>
    );
}

export default To_Do_List;