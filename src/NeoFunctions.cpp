#include "NeoFunctions.h"
void signalize(){
  //light up the strip starting from the middle and going outwards during 500ms
  int duration = 500;
  int delayTime = duration/NUMPIXELS;
  int center = NUMPIXELS/2;
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(center + i, pixels.Color(255, 255, 255));
    pixels.setPixelColor(center - i, pixels.Color(255, 255, 255));
    pixels.show();
    delay(delayTime);
  }
  delay(1000);
  //turn off the strip
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}