#ifndef WIFI_FUNCTIONS_H
#define WIFI_FUNCTIONS_H
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define ssid "Embassy of Banderstadt"
#define password "$tr0ngP@$$w0rd"

ESP8266WebServer server(80);


void initWifi();
void createWebpage();
void startWebserver();
void handleRequests();



#endif