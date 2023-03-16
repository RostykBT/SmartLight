#include "WifiFunctions.h"
#include "NeoFunctions.h"   // tmp delete by replacing with custom neofunctions

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

void startWebserver(){
  server.begin();
  Serial.println("HTTP server started");
  signalize();
}

void handleRequests(){
  server.handleClient();
}
