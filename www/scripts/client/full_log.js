var next_row = 0;
var last_position = 0;
const GULP_SIZE = 20
var awaiting = false;

function drawMore()
{
    console.log('Draw More...')
    awaiting = true;
    let xhttp = new XMLHttpRequest();
    
    xhttp.onreadystatechange = function ()
    {
        if (this.readyState == 4 && this.status == 200) {
            console.log(this.responseText);
            awaiting = false;
        }
    };

    xhttp.open('GET', 'http://139.59.173.54/mesh-fire/scripts/server/get-some-incidents.php?start=' + next_row + '&number=' + 20);
    xhttp.send();
}

window.onscroll = function () 
{
    // console.log('Scrolling...');
    let bottom = document.body.clientHeight - window.innerHeight
    // console.log(window.scrollY + ' => ' + bottom);
    // console.log()
    let position = window.scrollY;

    if (position > last_position && position >= bottom & !awaiting) drawMore()
    last_position = position;
}