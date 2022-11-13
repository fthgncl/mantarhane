void loop_data_control() {
  if ( dataUpdateTime() ) {
    WifiControl();
    const String data = SQL_get_data();
    baglanti = data != "";
    if ( baglanti ) {
      DynamicJsonDocument doc(2048);
      deserializeJson(doc, data);
      JsonObject json_calismaPlani = doc.as<JsonObject>();
      calismaPlani[ISIK_CALISMA_SURESI] = int(json_calismaPlani["isik_calisma_suresi"]);
      calismaPlani[ISIK_BEKLEME_SURESI] = int(json_calismaPlani["isik_bekleme_suresi"]);
      calismaPlani[FAN_CALISMA_SURESI] = int(json_calismaPlani["fan_calisma_suresi"]);
      calismaPlani[FAN_BEKLEME_SURESI] = int(json_calismaPlani["fan_bekleme_suresi"]);
      calismaPlani[NEM_ALT_DEGER] = int(json_calismaPlani["nem_alt_deger"]);
      calismaPlani[NEM_UST_DEGER] = int(json_calismaPlani["nem_ust_deger"]);
      calismaPlani[SICAKLIK_ALT_DEGER] = int(json_calismaPlani["sicaklik_alt_deger"]);
      calismaPlani[SICAKLIK_UST_DEGER] = int(json_calismaPlani["sicaklik_ust_deger"]);
      ilkDataAlindiMi = true;
    }
  }
}
bool dataUpdateTime() {
  if ( nowTime >  lastDataUpdateTime + updatePeriotMillis ) {
    lastDataUpdateTime  = nowTime;
    return true;
  }
  return false;
}
