float sicaklikDegerleri[4];
uint8_t sensorAdresleri[][8] = {
  { 0x28, 0x3F, 0xD4, 0x56, 0xB5, 0x01, 0x3C, 0x17 },
  { 0x28, 0x79, 0x54, 0x94, 0x97, 0x03, 0x03, 0x90 },
  { 0x28, 0x88, 0x1A, 0x97, 0x94, 0x07, 0x03, 0xC9 },
  { 0x28, 0xB6, 0x3A, 0x97, 0x94, 0x04, 0x03, 0x9A }
};
void sicaklik_control_setup() {
  sensors.begin();
}

void sicaklik_control_loop() {
  if ( sicaklikOlcumuYap() ) {
    int OrtalamaSicaklik = ortalamaSicakligiHesapla();
    digitalWrite(PIN_KLIMA_SOGUTMA, OrtalamaSicaklik > calismaPlani[SICAKLIK_UST_DEGER] ? HIGH : LOW);
    digitalWrite(PIN_KLIMA_ISITMA,  OrtalamaSicaklik < calismaPlani[SICAKLIK_ALT_DEGER] ? HIGH : LOW);
  }
}
int ortalamaSicakligiHesapla() {
  int ortalamaSicaklik = 0;
  for ( byte i = 0 ; i < ARRAY_SIZE(sicaklikDegeleri) ; i++) {
    ortalamaSicaklik += sicaklikDegerleri[i];
  }
  ortalamaSicaklik /= ARRAY_SIZE(sicaklikDegerleri);
  return ortalamaSicaklik;
}
bool sicaklikOlcumuYap() {
  bool hataliOlcum = false;
  sensors.requestTemperatures();
  for ( byte i = 0 ; i < ARRAY_SIZE(sicaklikDegerleri) ; i++) {
    sicaklikDegerleri[i] = sensors.getTempC(sensorAdresleri[i]);
    Serial.println(sicaklikDegerleri[i]);

    if ( sicaklikDegerleri[i] < -20 || sicaklikDegerleri[i] > 70 ) {
      hataliOlcum = true;
    }

  }
  return hataliOlcum;
}
