void loop_data_control() {
  if ( dataUpdateTime() ) {
    const String data = SQL_get_data();
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, data);
    calismaPlani = doc.as<JsonObject>();
  }
}
bool dataUpdateTime() {
  if ( nowTime >  lastDataUpdateTime + updatePeriotMillis ) {
    lastDataUpdateTime  = nowTime;
    return true;
  }
  return false;
}
