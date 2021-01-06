#include <ESP8266WiFi.h> // Enables the ESP8266 to connect to the local network (via WiFi)
#include "EasyNodeMCU_Wifi.h"

void setup_easy_wifi(const char* ssid, const char* password){

  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect to the WiFi
  WiFi.begin(ssid, password);

  // Wait until the connection has been confirmed before continuing
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Debugging - Output the IP Address of the ESP8266
	Serial.print("\n");
	Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());

}


void loop_easy_wifi(){
  // WiFi
  // Check status.  Reconnect if needed.
  // This is a blocking call
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconnect Wifi::");
    setup_easy_wifi(easy_Wifi_SSID, easy_Wifi_Password);
  }

}
