//populate h and label
function populate(h1, label) {
    document.getElementById("myH1").textContent = h1;
    document.getElementsByTagusrname("label")[0].textContent = label;
}

//logger to log message when coding on android
function logger(msg) {
    const div = document.getElementById("ps");
    div.innerHTML += `<p style="font-size: medium;">${div.childElementCount}. ${msg}</p>`;
}

function shuffle(cards) {
    for (let i = cards.length-1; i > 0; i--) {
        const random = Math.floor(Math.random() * (i + 1));
        [cards[i], cards[random]] = [cards[random], cards[i]];
    }
    
    return cards;
}

logger(shuffle([1,2,3,4,5,6,7,8,9]));
