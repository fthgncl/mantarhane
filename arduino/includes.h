#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))
#define ISIK D5
#define FAN D6
#define NEM_MAKINESI D7
#define KLIMA_ISITMA D8
#define KLIMA_SOGUTMA D1
enum { ISIK_CALISMA_SURESI, ISIK_BEKLEME_SURESI, FAN_CALISMA_SURESI, FAN_BEKLEME_SURESI, NEM_ALT_DEGER, NEM_UST_DEGER, SICAKLIK_ALT_DEGER, SICAKLIK_UST_DEGER };
int calismaPlani[8];

/* AsyncJson includes */
#include <AsyncJson.h>
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
unsigned long updatePeriotMillis = 10000;
unsigned long lastDataUpdateTime = updatePeriotMillis;
unsigned long lastDevicesControlTime;
bool ilkDataAlindiMi = false;
/***********************/

/* Sicaklik Sensorleri includes */
#include <OneWire.h>
#include <DallasTemperature.h>
/***********************/
