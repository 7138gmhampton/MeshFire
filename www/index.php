<!DOCTYPE html>
<html>
    <body>
        <h1>MeshFire Reporting Portal</h1>
        <div>
            <!-- <ul>
                <?php
                // ini_set('display_errors', 1);
                // ini_set('display_startup_errors', 1);
                // error_reporting(E_ALL);
                
                // include_once('scripts/server/view/incident_view.php');

                // $incident_codes = IncidentView::all();

                // foreach ($incident_codes as $incident_code)
                //     echo '<li>'.$incident_code.'</li>';
                ?>
            </ul> -->
            <table>
                <thead>
                    <th>Incident Code</th>
                    <th>Source MAC Address</th>
                    <th>Time of Recording</th>
                </thead>
                <?php
                ini_set('display_errors', 1);
                ini_set('display_startup_errors', 1);
                error_reporting(E_ALL);

                include_once('scripts/server/view/incident_view.php');

                $incidents = IncidentView::all();

                foreach ($incidents as $incident) $incident->printTableRow();
                ?>
            </table>
        </div>
    </body>
</html>