<?php

if ($_SERVER["REQUEST_METHOD"] != "POST"){
    break;
}

$data = json_decode(file_get_contents('php://input'), true);
$dataBase = veriTabaninaBaglan($data['username'], $data['password'], $data['databaseName']);

switch($data['command']){
    default:{
        veriTabaniKomutGonder($dataBase, $data['command']);
        break;
    }
    case "get_all_data":{
        $arr = array();
        $sonuc = veriTabaniKomutGonder($dataBase, 'SELECT * FROM `calisma_plani` WHERE 1;');
        if ($sonuc->num_rows > 0) {
            while($row = $sonuc->fetch_assoc()) {
                $arr = array_merge($arr, array($row['kosul']=>$row['deger']));
            }
            echo json_encode($arr);
        }
        break;
    }
}

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
