<?php
require_once('/var/www/html/mesh-fire/scripts/server/model/incident_model.php');

class IncidentView
{
    public static function all()
    {
        $incident_table = IncidentModel::getAllIncidents();
        $incidents = json_decode($incident_table, true);

        $all_incidents = array();
        foreach ($incidents as $each_incident)
            array_push($all_incidents, $each_incident['code']);

        return $all_incidents;
    }
} 
?>