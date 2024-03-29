<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <title>MeshFire Reporting Portal</title>

        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js"></script>
        <link rel="stylesheet" href="general.css" />
    </head>
    <body>
        <div class="container-fluid text-center mf-banner pb-3">
            <h1>MeshFire Reporting Portal</h1>
        </div>
        <div class="container">
            <table class="table caption-top">
                <caption class="text-center">Recent Detection Events</caption>
                <thead>
                    <tr>
                        <th scope="col">Incident Code</th>
                        <th scope="col">Source MAC Address</th>
                        <th scope="col">Time of Recording</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    ini_set('display_errors', 1);
                    ini_set('display_startup_errors', 1);
                    error_reporting(E_ALL);

                    include_once('scripts/server/view/incident_view.php');

                    $incidents = IncidentView::recentTen();

                    foreach ($incidents as $incident) $incident->printTableRow();
                    ?>
                </tbody>
            </table>
        </div>>
        <div class="container text-center">
            <a href="full_log.php" class="btn mf-button">Full Event Log</a>
        </div>
    </body>
</html>