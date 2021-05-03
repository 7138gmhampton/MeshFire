var next_row = 0;
var last_position = 0;
const GULP_SIZE = 20
var awaiting = false;

function attachDataCell(row, content)
{
    let cell = document.createElement('td');
    let cell_text = document.createTextNode(content);

    cell.appendChild(cell_text);
    row.appendChild(cell);
}

function attachIncident(incident)
{
    let event_log = document.getElementById('eventLog');
    let table_row = document.createElement('tr');

    attachDataCell(table_row, incident.code);
    attachDataCell(table_row, incident.mac_address);
    attachDataCell(table_row, incident.time_stamp);

    event_log.appendChild(table_row);
}

function requestMore()
{
    awaiting = true;
    let xhttp = new XMLHttpRequest();
    
    xhttp.onreadystatechange = function ()
    {
        if (this.readyState == 4 && this.status == 200) {
            JSON.parse(this.responseText).forEach(attachIncident);
            next_row += GULP_SIZE;
            awaiting = false;
        }
    };
    
    const url = 'http://139.59.173.54/mesh-fire/scripts/server/get-some-incidents.php';
    xhttp.open('GET', `${url}?start=${next_row}&number=${GULP_SIZE}`);
    xhttp.send();
}

window.onscroll = function () 
{
    let bottom = document.body.clientHeight - window.innerHeight
    let position = window.scrollY;

    if (position > last_position && position >= bottom & !awaiting) requestMore()
    last_position = position;
}

window.onload = function () 
{
    requestMore();
}