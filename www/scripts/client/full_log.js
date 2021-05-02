var next_row = 0;
var last_position = 0;

function drawMore()
{
    console.log('Draw More...')
}

window.onscroll = function () 
{
    // console.log('Scrolling...');
    let bottom = document.body.clientHeight - window.innerHeight
    // console.log(window.scrollY + ' => ' + bottom);
    // console.log()
    let position = window.scrollY;

    if (position > last_position && position >= bottom) drawMore()
    last_position = position;
}