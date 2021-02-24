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
                
                include_once('scripts/server/view/incident_view.php');

                $incident_codes = IncidentView::all();

                foreach ($incident_codes as $incident_code)
                    echo '<li>'.$incident_code.'</li>';
                ?>
            </ul>
        </div>
    </body>
</html>