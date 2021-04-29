<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

require_once('/var/www/html/mesh-fire/scripts/server/controller/incident_controller.php');

if (isset($_POST['incident']) && isset($_POST['mac_address'])) {
    IncidentController::create($_POST['incident'], $_POST['mac_address']);
}
else http_response_code(400);
?>