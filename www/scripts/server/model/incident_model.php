<?php
require_once('database.php');

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
}
?>