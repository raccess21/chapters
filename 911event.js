// eventlisteners react to events to create more interactive webpages
//  .addEvevntListener(event, callback);
//  event object is passed automatically to the callback function


////////////////MOUSE EVENTS////////////////////////////
// like click, mouseover, mouseout
let tem = 1000;

document.getElementById('lbl').addEventListener('mouseover', changeColor);
document.getElementById('lbl').addEventListener('mouseout', event => {
    event.target.textContent = 'Leela';
    event.target.style.color = 'red';
});

document.getElementById('lbl').addEventListener('click', event => {
    event.target.style.fontWeight = 'bold';
    setTimeout(() => {
        event.target.style.fontWeight = 'normal';
    }, tem);
});

function changeColor(event){
    event.target.style.color = 'grey';
    event.target.textContent = 'Oii !!';
}


//////////////////KEY EVENTS//////////////////////////////
//like keydown, keyup, keypress(compatibility issues)

document.addEventListener('keydown', event => {
    const p = document.createElement('p');
    p.className = 'bolo';
    p.textContent = 'Nono';
    document.body.append(p);
});

document.addEventListener('keyup', event => {
    document.querySelectorAll('.bolo').forEach(ele => {
        ele.remove();
    });
});