<?php
require_once('/var/www/html/mesh-fire/scripts/server/model/incident_model.php');

class IncidentController
{
    public static function create(string $code, string $mac_address)
    {
        $incident = array('code' => $code, 'mac_address' => $mac_address);

        IncidentModel::createIncident(json_encode($incident));
    }
}
?>