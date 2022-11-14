unsigned long sonVeriGondermeZamani;
void sensor_verilerini_gonder() {
  String url = ServerDomain + "/veri.php?";
  for ( byte i = 0 ; i < ARRAY_SIZE(sicaklikDegerleri) ; i++) {
    url += "sensor" + String(i + 1) + "=" + String(sicaklikDegerleri[i], 4) + "&";
  }
  url += "toprakisisi=" + String(dht11_sicaklik,4);
  Serial.println(url);

  bool islemBasarilimi = sensor_verisi_http_request(url);
  if ( islemBasarilimi ) {
    Serial.print(ServerDomain);
    Serial.println(" adresine sensor verileri gonderildi.");
  }
  else
  {
    Serial.print(ServerDomain);
    Serial.println(" bağlantısı başarısız.");
  }
}
bool sensor_verisi_http_request(const String serverName) {
  WiFiClient client;
  HTTPClient http;

  http.begin(client, serverName);

  int httpResponseCode = http.GET();

  if (httpResponseCode <= 0) {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();

  return httpResponseCode > 0;
}
bool sensorVerisiGondermeZamaniGeldiMi() {
  if ( !ilkDataAlindiMi ) {
    return false;
  }

  if ( nowTime >  sonVeriGondermeZamani + 60000 ) {
    sonVeriGondermeZamani  = nowTime;
    return true;
  }
  return false;
}
