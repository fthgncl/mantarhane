#include "includes.h"

void setup() {
  Serial.begin(9600);
  
  connectWifi();
  web_server_setup();

  SQL_send_command("komut");
}

void loop() {


}
