/ *
 * Mini Wifi Meter project http://jaycar.com.au/mini-wifi-meter
 
 * XC3802 esp8266
 * XC4384 OLED display
 * XC3850 protoshield
 
 * Jaycar Electronics
 * Author: D.West
 */
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
  delay(1000);
}
