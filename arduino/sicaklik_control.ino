float sicaklikDegeleri[4];
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
  sicaklikOlcumuYap();
  int OrtalamaSicaklik = ortalamaSicakligiHesapla();
  Serial.println(OrtalamaSicaklik);
  digitalWrite(PIN_KLIMA_SOGUTMA, OrtalamaSicaklik > calismaPlani[SICAKLIK_UST_DEGER] ?HIGH:LOW);
  digitalWrite(PIN_KLIMA_ISITMA,  OrtalamaSicaklik < calismaPlani[SICAKLIK_ALT_DEGER] ?HIGH:LOW);
  
}
int ortalamaSicakligiHesapla() {
  int ortalamaSicaklik = 0;
  for ( byte i = 0 ; i < ARRAY_SIZE(sicaklikDegeleri) ; i++) {
    ortalamaSicaklik += sicaklikDegeleri[i];
  }
  ortalamaSicaklik /= ARRAY_SIZE(sicaklikDegeleri);
  return ortalamaSicaklik;
}
void sicaklikOlcumuYap() {
  sensors.requestTemperatures();
  for ( byte i = 0 ; i < ARRAY_SIZE(sicaklikDegeleri) ; i++) {
    sicaklikDegeleri[i] = sensors.getTempC(sensorAdresleri[i]);
  }
}
