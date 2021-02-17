<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// if (isset($_GET['incident'])) {
//     // file_put_contents('incidents.txt', $_GET['incident'], FILE_APPEND | LOCK_EX);
//     $incident_list = fopen('../data/incidents.txt', 'a');

//     fclose($incident_list);
// }

$server = 'lochnagar.abertay.ac.uk';
$database = 'sql0407435';
$password = 'PAnQq1jJKwkk';

if (isset($_GET['incident'])) {
    $connection = new mysqli($server, $database, $password, $database);
    if ($connection->connect_error) die('Connection failed: '.$connection->connect_error);

    $sql_command = 'INSERT INTO mf_incident (code) VALUES ('.$_GET['incident'].')';

    $connection->query($sql_command);

    $connection->close();
}
?>