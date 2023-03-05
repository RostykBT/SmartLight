#include <Arduino.h>
//neopixel test code 
#include <Adafruit_NeoPixel.h>
#include "NeoFunctions.h"
// wifi library
#include <ESP8266WiFi.h>

//webserver library
#include <ESP8266WebServer.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define ssid "Embassy of Banderstadt"
#define password "$tr0ngP@$$w0rd"

ESP8266WebServer server(80);

//functuion to initialize wifi and conect to network
void initWifi(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//function to create webpage to control the lights 
void createWebpage(){
  server.on("/", [](){
    server.send(200, "text/html", "<!DOCTYPE HTML><html><head><title>ESP8266 Web Server</title></head><body><h1>ESP8266 Web Server</h1><form action=\"/RGB\"><label for=\"R\">R:</label><input type=\"range\" id=\"R\" name=\"R\" min=\"0\" max=\"255\"><br><label for=\"G\">G:</label><input type=\"range\" id=\"G\" name=\"G\" min=\"0\" max=\"255\"><br><label for=\"B\">B:</label><input type=\"range\" id=\"B\" name=\"B\" min=\"0\" max=\"255\"><br><input type=\"submit\" value=\"Submit\"></form></body></html>");
  });
  
  server.on("/RGB", [](){
    int R = server.arg("R").toInt();
    int G = server.arg("G").toInt();
    int B = server.arg("B").toInt();
    for(int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(R, G, B));
    }
    pixels.show();
    delay(10);
    server.send(200, "text/html", "<!DOCTYPE HTML><html><head><title>ESP8266 Web Server</title></head><body><h1>ESP8266 Web Server</h1><form action=\"/RGB\"><label for=\"R\">R:</label><input type=\"range\" id=\"R\" name=\"R\" min=\"0\" max=\"255\"><br><label for=\"G\">G:</label><input type=\"range\" id=\"G\" name=\"G\" min=\"0\" max=\"255\"><br><label for=\"B\">B:</label><input type=\"range\" id=\"B\" name=\"B\" min=\"0\" max=\"255\"><br><input type=\"submit\" value=\"Submit\"></form></body></html>");
  });
}



//function to start webserver
void startWebserver(){
  server.begin();
  Serial.println("HTTP server started");
  signalize();
}

//function to handle http requests
void handleRequests(){
  server.handleClient();
}





void setup() {
  pixels.begin();

  Serial.begin(115200);

  initWifi();

  createWebpage();

  startWebserver();



}

void loop() {
 handleRequests();
//turn all white
  // for(int i=0; i<NUMPIXELS; i++) {
  //   pixels.setPixelColor(i, pixels.Color(255, 255, 255));
  // }
  // pixels.show();
  delay(10);

}

