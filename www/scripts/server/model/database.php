<?php

class Database
{
    private static $connection_string = 'mysql:host=localhost;dbname=mf';
    // private static $user = 'beaumains';
    // private static $password = '1`~.LmdSMfy&/A';
    protected static $down_user = 'downstream';
    protected static $down_password = 'rIs68o2JJb!Z';
    protected static $up_user = 'upstream';
    protected static $up_password = 'nu|pLec!B2ff';

    protected static function makeConnection(string $user, string $password)
    {
        $connection = new PDO(self::$connection_string, $user, $password);
        $connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        return $connection;
    }

    protected static function prepareStatement(string $command, string $user, string $password)
    {
        $connection = self::makeConnection($user, $password);
        $statement = $connection->prepare($command);

        return $statement;
    }
}
?>