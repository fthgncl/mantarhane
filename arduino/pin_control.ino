void pin_control_setup() {
  DynamicJsonDocument doc(2048);
  doc["isik"] = D3;
  doc["fan"] = D5;
  doc["nem_makinesi"] = D6;
  doc["klima_isitma"] = D7;
  doc["klima_sogutma"] = D8;
  
  PINS = doc.as<JsonObject>();
  set_pinModes();
}
void set_pinModes(){
  pinMode(int(PINS["isik"]), OUTPUT);
  pinMode(int(PINS["fan"]), OUTPUT);
  pinMode(int(PINS["nem_makinesi"]), OUTPUT);
  pinMode(int(PINS["klima_isitma"]), OUTPUT);
  pinMode(int(PINS["klima_sogutma"]), OUTPUT);
}
