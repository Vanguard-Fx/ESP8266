/*********************************************************************************
Controller RGB via WiFi con PubNub
posta@maurizioconti.com - FabLab Romagna 2016
*********************************************************************************/
#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>

// Sulla rete WiFi Locale...
const char* g_ssid      = "D-Link";
const char* g_password  = "kJWF9xB+";


// Sul NeoPixel
#define PIN 2

// Ring
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

// WS2811
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_RGB + NEO_KHZ800);

int R,G,B;

void flashLed( uint32_t  c )
{
  strip.setPixelColor(0, c);
  strip.show(); 
  delay(100);
  strip.setPixelColor(0, strip.Color(0,0,0));
  strip.show(); 
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
  delay(2000);
  Serial.print(".");
  Serial.print(".");
  Serial.print(".");

  Serial.println("Sistema partito!");

  strip.begin();
  Serial.println("NeoPixel inizializzato...");


}

void loop() {
  // put your main code here, to run repeatedly:
  R = random(50);
  G = random(50);
  B = random(50);
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
  strip.setPixelColor(random(16), strip.Color(R, G, B));
  strip.show();
  delay(50);
}
