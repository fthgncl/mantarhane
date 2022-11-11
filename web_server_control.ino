void web_server_setup() {

  AsyncElegantOTA.begin(&server);
  server.onNotFound(notFound);
  server.begin();
  Serial.println("HTTP server started");

}
void notFound(AsyncWebServerRequest *request) {
  request->send(404, "application/json", "{\"message\":\"Not found\"}");
}
