<?php
if ($_SERVER["REQUEST_METHOD"] != "POST"){
    break;
}

$data = json_decode(file_get_contents('php://input'), true);
$dataBase = veriTabaninaBaglan($data['username'], $data['password'], $data['databaseName']);
veriTabaniKomutGonder($dataBase, $data['command']);
mysqli_close($dataBase);

function veriTabaninaBaglan($username, $password, $databaseName)
{
    $servername = "localhost";

    $conn = new mysqli($servername, $username, $password, $databaseName);
    if ($conn->connect_error) {
        die("Veri tabanı bağlantısı başarısız oldu : " . $conn->connect_error);
    }
    $conn->set_charset("utf8");
    return $conn;
}

function veriTabaniKomutGonder($dataBase, $command)
{
    return $dataBase->query($command);
}

?>
