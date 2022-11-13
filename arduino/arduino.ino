#include "includes.h"


void setup() {
  Serial.begin(9600);
  delay(1000);
  
  pin_control_setup();
  connectWifi();
  web_server_setup();

}

void loop() {
  nowTime = millis();
  loop_data_control();
}
