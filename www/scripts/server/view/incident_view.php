<?php
require_once('/var/www/html/mesh-fire/scripts/server/model/incident_model.php');

class Incident
{
    private $code;
    private $mac_address;
    private $time_stamp;

    // function __construct(string $code, string $mac_address, string $time_stamp)
    // {
    //     $this->code = $code;
    //     $this->mac_address = $mac_address;
    //     $this->time_stamp = date_create($time_stamp);
    // }

    private function __construct() { }

    public static function buildFromArray($assoc_array)
    {
        $incident = new Incident();

        $incident->code = $assoc_array['code'];
        $incident->mac_address = $assoc_array['mac_address'];
        $incident->time_stamp = date_create($assoc_array['time_stamp']);

        return $incident;
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
            // $next_incident = new Incident(
            //     $each_incident['code'], 
            //     $each_incident['mac_address'], 
            //     $each_incident['time_stamp']);
            // array_push($all_incidents, $next_incident);
            array_push($all_incidents, Incident::buildFromArray($each_incident));
        }

        return $all_incidents;
    }

    public static function some(int $start, int $number)
    {
        $incidents = json_decode(IncidentModel::getSome($start, $number));

        $these_incidents = array();
        foreach ($incidents as $incident) {
            // $next_incident = new Incident(
            //     $incident['code'], 
            //     $incident['mac_address'], 
            //     $incident['time_stamp']);
            // array_push($these_incidents, $next_incident);
            array_push($these_incidents, Incident::buildFromArray($incident));
        }

        return $these_incidents;
    }

    public static function recentTen()
    {
        $incidents = json_decode(IncidentModel::getRecent(10), true);

        $recent_incidents = array();
        foreach ($incidents as $each_incident) {
            // $next_incident = new Incident(
            //     $each_incident['code'], 
            //     $each_incident['mac_address'], 
            //     $each_incident['time_stamp']);
            // array_push($recent_incidents, $next_incident);
            array_push($recent_incidents, Incident::buildFromArray($each_incident));
        }

        return $recent_incidents;
    }
} 
?>