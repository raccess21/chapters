//html page is represented as document object model DOM
console.dir(document);      

///////////////////DOM SELECTION/////////////////////////////////////////////
// document.getElementById('id');                      //returns element with id  or null
// document.getElementsByClassName('className');       //returns elements with cls array like html collection
// document.getElementsByTagName('tagName');           //returns elements with tag array like html collection

// document.querySelector();                           //returns first element or null based on css like selectors
// document.querySelectorAll();                        //returns all elements NodeList based on css like selectors                                 

//html collection doesn't have forEach, NodeList has forEach method
//NodeList is static i.e it doesn't update automatically with DOM change
const buttons = document.getElementsByTagName('button');

function caller(f1, f2){
    f1();
    setTimeout(() => {
        f2();
    }, 3000);
}

function apr1(){
    Array.from(buttons).forEach(btn => {                        //type cast collection to array
        btn.style.backgroundColor = 'yellow';
    })
}

function apr2(){
    for(btn of buttons){
        btn.style.backgroundColor = 'red';
    }
}

caller(apr1, apr2);


////////////////////////////////////////////////////////////////
// query selector   ->
//  . class
//  # id
//  tag name
document.title = document.querySelector('body > div#ps > h3#myP').textContent;


////////////////////DOM NAVIGATION??????????????????????????????
const ele = document.getElementsByTagName('body')[0];

console.log(ele.firstChild);                        //returns first child e.g node, tag, text etc or null
console.log(ele.firstElementChild);                  //returns first child that is an html element or null

console.log(ele.firstElementChild.previousElementSibling);           //returns null
ele.lastChild;    
ele.lastElementChild;    
ele.nextSibling;
ele.nextElementSibling;
ele.previousSibling;
ele.previousElementSibling;
ele.parentNode;
ele.parentElement;
ele.childNodes;
ele.children;


///////////////////////////DOM EDIT////////////////////////////////////
const looter = document.createElement('looter');        //1. creation
looter.textContent = 'Indexia Anorexia';                //2. addition of attributes
document.body.prepend(looter);                           //3. add it to document
document.body.append(looter);                           //3. add it to document
// document.body.insertBefore(looter, document.getElementById('myP')); //error myP is grandchild not child of body
document.body.removeChild(looter);                       //4. remove child


