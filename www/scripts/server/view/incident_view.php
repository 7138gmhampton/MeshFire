<?php
require_once('/var/www/html/mesh-fire/scripts/server/model/incident_model.php');

class Incident
{
    private $code;
    private $mac_address;
    private $time_stamp;

    function __construct(string $code, string $mac_address, string $time_stamp)
    {
        $this->code = $code;
        $this->mac_address = $mac_address;
        $this->time_stamp = date_create($time_stamp);
    }

    function printTableRow()
    {
        echo '<tr>';

        echo '<td>'.$this->code.'</td>';
        echo '<td>'.$this->mac_address.'</td>';
        echo '<td>'.$this->time_stamp->format(DateTime::ISO8601).'</td>';

        echo '</tr>';
    }
}

class IncidentView
{
    public static function all()
    {
        $incident_table = IncidentModel::getAllIncidents();
        $incidents = json_decode($incident_table, true);

        $all_incidents = array();
        foreach ($incidents as $each_incident) {
            $next_incident = new Incident(
                $each_incident['code'], 
                $each_incident['mac_address'], 
                $each_incident['time_stamp']);
            array_push($all_incidents, $next_incident);
        }

        return $all_incidents;
    }

    public static function recentTen()
    {
        // $incident_entries = IncidentModel::getRecent(10);
        $incidents = json_decode(IncidentModel::getRecent(10), true);

        $recent_incidents = array();
        foreach ($incidents as $each_incident) {
            $next_incident = new Incident(
                $each_incident['code'], 
                $each_incident['mac_address'], 
                $each_incident['time_stamp']);
            array_push($recent_incidents, $next_incident);
        }

        return $recent_incidents;
    }
} 
?>