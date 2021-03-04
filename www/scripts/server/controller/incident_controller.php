<?php
require_once('/var/www/html/mesh-fire/scripts/server/model/incident_model.php');

class IncidentController
{
    public static function create(string $code)
    {
        $incident = array('code' => $code);

        IncidentModel::createIncident(json_encode($incident));
    }
}
?>