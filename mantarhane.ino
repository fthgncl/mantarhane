#include "includes.h"

void setup() {
  Serial.begin(9600);
  
  connectWifi();
  web_server_setup();

}

void loop() {


}
