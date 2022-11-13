/* AsyncJson includes */
#include <AsyncJson.h>
JsonObject PINS;
JsonObject calismaPlani;
/***********************/

/* Wifi includes */
#include <ESP8266WiFi.h>
IPAddress local_IP(192, 168, 1, 199);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);
const char* ssid = "deneme-bile";
const char* password = "wifibizeozel";
/***********************/

/* Async WebServer includes */
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#define webServerPort 80
AsyncWebServer server(webServerPort);
/***********************/

/* HTTPClient - SQL includes */
#include <ESP8266HTTPClient.h>
const String ServerDomain = "http://mantarhane.tk";
const String ServerPHPpage = "sql_komut.php";
const String SQL_username = "mantarhane_Mantar";
const String SQL_password = "Harun.14";
const String SQL_dataBaseName = "mantarhane_mantar";
/***********************/

/* Data Control includes */
unsigned long nowTime;
unsigned long lastDataUpdateTime;
const int updatePeriotMillis = 10000;
/***********************/

/* Sicaklik Sensorleri includes */
#include <OneWire.h>
#include <DallasTemperature.h>
/***********************/
