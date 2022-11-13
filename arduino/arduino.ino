#include "includes.h"
bool baglanti = false;

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  set_pins();
  connectWifi();
  web_server_setup();

}

void loop() {
  nowTime = millis();
  loop_data_control();

  if ( devicesControlTime() ){
    isik_loop();
    fan_loop();
  }
  
}
bool devicesControlTime() {
  if ( !ilkDataAlindiMi ){
    return false;
  }
  
  if ( nowTime >  lastDevicesControlTime + 1000 ) {
    lastDevicesControlTime  = nowTime;
    return true;
  }
  return false;
}
