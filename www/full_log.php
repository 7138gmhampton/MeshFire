<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <title>MeshFire Full Log</title>

        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js"></script>
        <link rel="stylesheet" href="general.css" />
        <script src="scripts/client/full_log.js"></script>
    </head>
    <body>
        <div class="container-fluid text-center mf-banner pb-3">
            <h1>MeshFire Reporting Portal</h1>
        </div>
        <div class="container text-center">
            <a href="#" class="btn mf-button m-3">Back to Main</a>
        </div>
        <div class="container">
            <table class="table">
                <thead>
                    <tr>
                        <th scope="col">Incident Code</th>
                        <th scope="col">Source MAC Address</th>
                        <th scope="col">Time of Recording</th>
                    </tr>
                </thead>
                <tbody id="eventLog">
                    <!-- AJAX drawn expanding table -->
                </tbody>
            </table>
        </div>
    </body>
</html>