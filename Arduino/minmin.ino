#include "Pixel.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif we suggest changing this to 1

#define PIN            6
#define NUMPIXELS      7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

float r = 0;
float g = 0;
float b = 0;

int delayval = 500; // delay for half a second

void setup() {
  Serial.begin(9600);

  pixels.begin(); // This initializes the NeoPixel library.
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  if (Serial.available() > 0) {
    if (Serial.read() == 1) {
      r = random(155) + 100;
      g = random(155) + 100;
      b = random(155) + 100;
    }
  }
if (r > 0) r-=0.2;
if (g > 0) g-=0.2;
if (b > 0) b-=0.2;
  
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.show();

}
