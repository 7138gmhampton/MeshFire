<?php
require_once('database.php');

/**
 * Models the notification of the flames sensors on the nodes against the 
 * database. Parameters and return values are all in JSON.
 */
class IncidentModel extends Database
{
    public static function getAllIncidents()
    {
        $command = 'SELECT code FROM incident;';
        $result = null;

        try {
            $statement = self::prepareStatement($command, self::$down_user, self::$down_password);

            $statement->execute();

            $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        }
        catch (PDOException $err) {
            echo 'Error: '.$err->getMessage();
            return null;
        }

        $response = json_encode($result);
        return $response;
    }

    public static function createIncident($incident)
    {
        $command = 'INSERT INTO incident (code, mac_address, time_stamp) '
            .'VALUES (:code, :mac_address, NOW())';
        $incident_array = json_decode($incident, true);

        try {
            $statement = self::prepareStatement($command, self::$up_user, self::$up_password);
            $statement->bindParam(':code', $incident_array['code']);
            $statement->bindParam(':mac_address', $incident_array['mac_address']);
            // $statement->bindParam(':time_stamp', $incident_array['time_stamp']);

            $statement->execute();
        }
        catch (PDOException $err) {
            echo 'Error: ' . $err->getMessage();
            return null;
        }
    }
}
?>