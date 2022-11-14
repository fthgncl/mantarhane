bool nem_cihazi_calisma_durumu = false;
void nem_sensor_setup() {
  dht.begin();
}
void nem_control_loop() {
  dht11_nemIslemleri(dht.readHumidity());
  dht11_isiIslemleri(dht.readTemperature());
}
void dht11_nemIslemleri(float nem) {
  if ( isnan(nem) ) {
    Serial.println("DHT Nem Sensoru okuma hatası !");
    return;
  }
  nem_cihazi_calisma_durumu = nem < calismaPlani[nem_cihazi_calisma_durumu?NEM_UST_DEGER:NEM_ALT_DEGER];
  digitalWrite(PIN_NEM_MAKINESI,nem_cihazi_calisma_durumu?HIGH:LOW);
}
void dht11_isiIslemleri(float sicaklik) {
  if ( isnan(sicaklik) ) {
    Serial.println("DHT Isı Sensoru okuma hatası !");
    return;
  }
}
