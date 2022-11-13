bool fan_mod;  // 0 : bekleme modunda , 1 : çalışma modunda
int fan_sureler[2]; // 0 : bekleme suresi , 1 : calışma süresi
void fan_loop() {
  fan_sureler[fan_mod]++;
  if ( fan_sureler[fan_mod] > calismaPlani[fan_mod ? FAN_CALISMA_SURESI : FAN_BEKLEME_SURESI]) {
    fan_sureler[fan_mod] = 0;
    fan_mod = !fan_mod;
    digitalWrite(PIN_FAN,fan_mod?HIGH:LOW);
  }
}
