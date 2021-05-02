var next_row = 0;
var last_position = 0;
const GULP_SIZE = 20
var awaiting = false;

function attachIncident(incident)
{
    let event_log = document.getElementById('eventLog');
    let table_row = document.createElement('tr');

    let code = document.createElement('td');
    let code_text = document.createTextNode(incident.code);
    code.appendChild(code_text);
    table_row.appendChild(code);
    let mac_address = document.createElement('td');
    let mac_address_text = document.createTextNode(incident.mac_address);
    mac_address.appendChild(mac_address_text);
    table_row.appendChild(mac_address);
    let time_stamp = document.createElement('td');
    let time_stamp_text = document.createTextNode(incident.time_stamp);
    time_stamp.appendChild(time_stamp_text);
    table_row.appendChild(time_stamp);

    event_log.appendChild(table_row);
}

// function attachMore(new_incidents)
// {
//     let incidents = JSON.parse(new_incidents);

//     incidents.forEach(attachIncident);
// }

function drawMore()
{
    awaiting = true;
    let xhttp = new XMLHttpRequest();
    
    xhttp.onreadystatechange = function ()
    {
        if (this.readyState == 4 && this.status == 200) {
            // attachMore(this.responseText);
            JSON.parse(this.responseText).forEach(attachIncident);
            next_row += GULP_SIZE;
            awaiting = false;
        }
    };

    xhttp.open('GET', 'http://139.59.173.54/mesh-fire/scripts/server/get-some-incidents.php?start=' + next_row + '&number=' + 20);
    xhttp.send();
}

window.onscroll = function () 
{
    let bottom = document.body.clientHeight - window.innerHeight
    let position = window.scrollY;

    if (position > last_position && position >= bottom & !awaiting) drawMore()
    last_position = position;
}

window.onload = function () 
{
    drawMore();
}