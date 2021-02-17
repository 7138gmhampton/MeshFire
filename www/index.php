<!DOCTYPE html>
<html>
    <body>
        <h1>MeshFire Reporting Portal</h1>
        <div>
            <ul>
                <?php
                $incidents = file('data/incidents.txt');

                foreach ($incidents as $incident)
                    echo '<li>'.$incident.'</li>';
                ?>
            </ul>
        </div>
    </body>
</html>