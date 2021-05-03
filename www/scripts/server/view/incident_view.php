<?php
require_once('/var/www/html/mesh-fire/scripts/server/model/incident_model.php');

class Incident
{
    private $code;
    private $mac_address;
    private $time_stamp;

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
        echo '<td>'.$this->time_stamp->format('Y-m-d H:i:s').'</td>';

        echo '</tr>';
    }
}

class IncidentView
{
    private static function convertToObjects($assoc_incidents)
    {
        $incidents = array();
        foreach ($assoc_incidents as $incident)
            array_push($incidents, Incident::buildFromArray($incident));

        return $incidents;
    }
    
    public static function all()
    {
        $incidents = json_decode(IncidentModel::getAllIncidents(), true);

        return self::convertToObjects($incidents);
    }

    public static function some(int $start, int $number)
    {
        $incidents = json_decode(IncidentModel::getSome($start, $number));

        return self::convertToObjects($incidents);
    }

    public static function recentTen()
    {
        $incidents = json_decode(IncidentModel::getRecent(10), true);

        return self::convertToObjects($incidents);
    }
} 
?>