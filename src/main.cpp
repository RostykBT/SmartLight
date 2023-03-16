#include <Arduino.h>

#include "NeoFunctions.h"
#include "WifiFunctions.h"

void setup() {
  pixels.begin();

  Serial.begin(115200);

  initWifi();

  createWebpage();

  startWebserver();



}

void loop() {
 handleRequests();
delay(10);
}
