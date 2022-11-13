#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))
#define PIN_ISIK D5
#define PIN_FAN D6
#define PIN_NEM_MAKINESI D7
#define PIN_KLIMA_ISITMA D8
#define PIN_KLIMA_SOGUTMA D1
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
unsigned long updatePeriotMillis = 60000;
unsigned long lastDataUpdateTime = -1*updatePeriotMillis;
unsigned long lastDevicesControlTime;
bool ilkDataAlindiMi = false;
/***********************/

/* Sicaklik Sensorleri includes */
#include <OneWire.h>
#include <DallasTemperature.h>
#define PIN_SICAKLIK_SENSOR_TELI D2
OneWire oneWire(PIN_SICAKLIK_SENSOR_TELI);
DallasTemperature sensors(&oneWire);
/***********************/
