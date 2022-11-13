bool ilkBaglanti = true;
void connectWifi() {
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED && ilkBaglanti ) {
    delay(500);
    Serial.print(".");
  }
  if ( WiFi.status() == WL_CONNECTED ) {
    ilkBaglanti = false;
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("");
  }
}
void WifiControl() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWifi();
  }
}
