bool isik_mod;  // 0 : bekleme modunda , 1 : çalışma modunda
int isik_sureler[2]; // 0 : bekleme suresi , 1 : calışma süresi
void isik_loop() {
  isik_sureler[isik_mod]++;
  if ( isik_sureler[isik_mod] > calismaPlani[isik_mod ? ISIK_BEKLEME_SURESI : ISIK_CALISMA_SURESI]) {
    isik_sureler[isik_mod] = 0;
    isik_mod = !isik_mod;
    digitalWrite(ISIK,isik_mod?HIGH:LOW);
  }
}
