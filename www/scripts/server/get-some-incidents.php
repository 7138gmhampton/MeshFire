<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

require_once('/var/www/html/mesh-fire/scripts/server/model/incident_model.php');

if (isset($_GET['start']) && isset($_GET['number']))
    echo IncidentModel::getSome($_GET['start'], $_GET['number']);
else http_response_code(400);
?>