<!DOCTYPE html>
<html>
    <body>
        <h1>MeshFire Reporting Portal</h1>
        <div>
            <ul>
                <?php
                ini_set('display_errors', 1);
                ini_set('display_startup_errors', 1);
                error_reporting(E_ALL);
                // $incidents = file('data/incidents.txt');

                // foreach ($incidents as $incident)
                //     echo '<li>'.$incident.'</li>';

                // $server = 'lochnagar.abertay.ac.uk';
                // $database = 'sql0407435';
                // $password = 'PAnQq1jJKwkk';
                $server = 'localhost';
                $user = 'beaumains';
                $database = 'mf';
                $password = '1`~.LmdSMfy&/A';

                $connection = new mysqli($server, $user, $password, $database);
                if ($connection->connect_error) die('Connection failed: '.$connection->connect_error);

                // $sql_command = 'INSERT INTO mf_incident (code) VALUES ('.$_GET['incident'].')';
                $sql_command = 'SELECT code FROM incident';

                $response = $connection->query($sql_command);
                
                while ($record = $response->fetch_assoc()) 
                    echo '<li>'.$record['code'].'</li>';

                $connection->close();
                ?>
            </ul>
        </div>
    </body>
</html>