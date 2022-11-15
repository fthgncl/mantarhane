<?php

$GLOBALS['dataBase'] = veriTabaninaBaglan('localhost', 'mantarhane_Mantar', 'Harun.14', 'mantarhane_mantar');

function veriTabaninaBaglan($servername, $username, $password, $databaseName)
{
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

function fan_calisma_plani($calismaSuresi,$beklemeSuresi){
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$calismaSuresi.' WHERE  `kosul`="fan_calisma_suresi"');
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$beklemeSuresi.' WHERE  `kosul`="fan_bekleme_suresi"');
}
function isik_calisma_plani($calismaSuresi,$beklemeSuresi){
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$calismaSuresi.' WHERE  `kosul`="isik_calisma_suresi"');
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$beklemeSuresi.' WHERE  `kosul`="isik_bekleme_suresi"');
}
function nem_calisma_plani($altDeger,$ustDeger){
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$altDeger.' WHERE  `kosul`="nem_alt_deger"');
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$ustDeger.' WHERE  `kosul`="nem_ust_deger"');
}
function sicaklik_calisma_plani($altDeger,$ustDeger){
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$altDeger.' WHERE  `kosul`="sicaklik_alt_deger"');
    veriTabaniKomutGonder($GLOBALS['dataBase'],'UPDATE `calisma_plani` SET `deger`='.$ustDeger.' WHERE  `kosul`="sicaklik_ust_deger"');
}

?>
