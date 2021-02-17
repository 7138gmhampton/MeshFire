<!DOCTYPE html>
<html>
    <body>
        <h1>MeshFire Reporting Portal</h1>
        <div>
            <ul>
                <?php
                // $incidents = file('data/incidents.txt');

                // foreach ($incidents as $incident)
                //     echo '<li>'.$incident.'</li>';

                $server = 'lochnagar.abertay.ac.uk';
                $database = 'sql0407435';
                $password = 'PAnQq1jJKwkk';

                $connection = new mysqli($server, $database, $password, $database);
                if ($connection->connect_error) die('Connection failed: '.$connection->connect_error);

                // $sql_command = 'INSERT INTO mf_incident (code) VALUES ('.$_GET['incident'].')';
                $sql_command = 'SELECT code FROM mf_incident';

                $response = $connection->query($sql_command);
                
                while ($record = $response->fetch_assoc()) 
                    echo '<li>'.$record['code'].'</li>';

                $connection->close();
                ?>
            </ul>
        </div>
    </body>
</html>