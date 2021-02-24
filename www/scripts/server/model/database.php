<?php

class Database
{
    private static $connection_string = 'mysql:host=localhost;dbname=mf';
    private static $user = 'beaumains';
    private static $password = '1`~.LmdSMfy&/A';

    protected static function makeConnection()
    {
        $connection = new PDO(self::$connection_string, self::$user, self::$password);
        $connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        return $connection;
    }

    protected static function prepareStatement($command)
    {
        $connection = self::makeConnection();
        $statement = $connection->prepare($command);

        return $statement;
    }
}

?>