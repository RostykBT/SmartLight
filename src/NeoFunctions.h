#ifndef NEOFUNCTIONS_H
#define NEOFUNCTIONS_H
#include <Adafruit_NeoPixel.h>
#define PIN            14
#define NUMPIXELS      15
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void signalize();


#endif