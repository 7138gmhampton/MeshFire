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
            $statement = self::prepareStatement($command);

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
        $command = 'INSERT INTO incident (code) VALUES (:code)';
        $incident_array = json_decode($incident);

        try {
            $statement = self::prepareStatement($command);
            $statement->bindParam(':code', $incident_array['code']);

            $statement->execute();
        }
        catch (PDOException $err) {
            echo 'Error: ' . $err->getMessage();
            return null;
        }
    }
}
?>