<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />

        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js"></script>
    </head>
    <body>
        <h1>MeshFire Reporting Portal</h1>
        <!-- <div>
            <table>
                <thead>
                    <th>Incident Code</th>
                    <th>Source MAC Address</th>
                    <th>Time of Recording</th>
                </thead>
                <?php
                // ini_set('display_errors', 1);
                // ini_set('display_startup_errors', 1);
                // error_reporting(E_ALL);

                // include_once('scripts/server/view/incident_view.php');

                // $incidents = IncidentView::all();

                // foreach ($incidents as $incident) $incident->printTableRow();
                ?>
            </table>
        </div> -->
        <div class="container">
            <div class="row">
                <div class="col">
                    <table>
                        <thead>
                            <th>Incident Code</th>
                            <th>Source MAC Address</th>
                            <th>Time of Recording</th>
                        </thead>
                        <tbody>
                            <?php
                            ini_set('display_errors', 1);
                            ini_set('display_startup_errors', 1);
                            error_reporting(E_ALL);

                            include_once('scripts/server/view/incident_view.php');

                            $incidents = IncidentView::all();

                            foreach ($incidents as $incident) $incident->printTableRow();
                            ?>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>