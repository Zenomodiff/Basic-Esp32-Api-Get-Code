#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "WIFI NAME";
const char* password =  "WIFI PASSWORD";

void apiCall(){
  
if ((WiFi.status() == WL_CONNECTED)) {
HTTPClient http;

http.begin("HTTP LINK");

int httpCode = http.GET();
if (httpCode == 200) {
String payload = http.getString();
Serial.print(payload);
}

 else 
 {
  
Serial.println("Error HTTP-Request");

 }
http.end();

 }}

void setup() {
 
Serial.begin(115200);
WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting To Network ...");
  }
  Serial.println("Connected !");

}
 
void loop()
{
 
apiCall();
delay(10000);

}
