void SQL_send_command(String command) {
  if ((WiFi.status() != WL_CONNECTED)) {
    Serial.println("SQL Komutu Gönderilemiyor. (Wifi Bağlantısı Yok)");
  }

  WiFiClient client;
  HTTPClient http;

  DynamicJsonDocument doc(2048);
  doc["username"] = SQL_username;
  doc["password"] = SQL_password;
  doc["databaseName"] = SQL_dataBaseName;
  doc["command"] = command;

  http.begin(client, ServerDomain + "/" + ServerPHPpage);
  http.addHeader("Content-Type", "application/json");

  Serial.print("[HTTP] POST...\n");
  int httpCode = http.POST(serializeJson(doc, Serial));

  // httpCode hata durumunda negatif olur
  if (httpCode > 0) {
    Serial.printf("[HTTP] POST... code: %d\n", httpCode);

    if (httpCode == HTTP_CODE_OK) {
      const String& payload = http.getString();
      Serial.println("received payload:\n<<");
      Serial.println(payload);
      Serial.println(">>");
    }
  } else {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
  delay(10000);
}
