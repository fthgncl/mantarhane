String SQL_send_command(const String command) {

  DynamicJsonDocument doc(2048);
  doc["username"] = SQL_username;
  doc["password"] = SQL_password;
  doc["databaseName"] = SQL_dataBaseName;
  doc["command"] = command;
  
  String strJson;
  serializeJson(doc, strJson);
  return send_request(strJson);
}
String SQL_get_data(){
  return SQL_send_command("get_all_data");
}
String send_request(String strJson) {
  if ((WiFi.status() != WL_CONNECTED)) {
    Serial.println("SQL Komutu Gönderilemiyor. (Wifi Bağlantısı Yok)");
  }

  WiFiClient client;
  HTTPClient http;
  String payload;
  int httpCode;

  http.begin(client, ServerDomain + "/" + ServerPHPpage);
  http.addHeader("Content-Type", "application/json");

  httpCode = http.POST(strJson);

  // httpCode hata durumunda negatif olur
  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      payload = http.getString();
    }
  }
  else
  {
    Serial.printf("[HTTP] error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
  delay(500);
  return payload;
}
