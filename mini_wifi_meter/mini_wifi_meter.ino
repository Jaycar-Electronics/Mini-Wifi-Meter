
//these files are needed for the latest version of the 8266 library toolset.
// they removed a macro from ESP8266WiFi.h and placed it in another library.
// if you get a library not found error, remove the below libaries

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>

// ===============================================================================
// below is all that's needed
// in the old version of the libraries:

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>

#define MAX_SSIDS 10

Adafruit_SSD1306 display(0);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //start the display
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.println("Mini WiFi Scanner");
  display.display();						//must call display after every set of operations.
}

void loop() {
  // put your main code here, to run repeatedly:

  int num_networks = WiFi.scanNetworks();
  display.clearDisplay();
  for(int i = 0; i < num_networks && i < MAX_SSIDS; i++)
  {
    display.setCursor(0,8*i);					//each line is 8 pixels high, so each loop drops 8,16,etc.
    display.print(WiFi.SSID(i));				//Service Set IDentifier
    display.setCursor(display.width()-20,8*i);	//right align the RSSI
    display.print(WiFi.RSSI(i));				//Received Signal Strength Indicator
  }
  display.display();
  delay(2000);
}
