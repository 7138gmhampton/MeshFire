<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// if (isset($_GET['incident'])) {
//     // file_put_contents('incidents.txt', $_GET['incident'], FILE_APPEND | LOCK_EX);
//     $incident_list = fopen('../data/incidents.txt', 'a');

//     fclose($incident_list);
// }

// $server = 'lochnagar.abertay.ac.uk';
// $database = 'sql0407435';
// $password = 'PAnQq1jJKwkk';
$server = 'localhost';
$user = 'beaumains';
$database = 'mf';
$password = '1`~.LmdSMfy&/A';

if (isset($_GET['incident'])) {
    $connection = new mysqli($server, $user, $password, $database);
    if ($connection->connect_error) die('Connection failed: '.$connection->connect_error);

    $sql_command = 'INSERT INTO incident (code) VALUES ('.$_GET['incident'].')';

    $connection->query($sql_command);

    $connection->close();
}
?>