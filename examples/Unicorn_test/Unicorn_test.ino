/*
  Pico Unicorn Example
  Written by Bodmer
  Hardware: Raspberry Pi Pico with Pimoroni Unicorn Pico Display

  Requires libraries:
  Adafruit_GFX - available via the Arduino IDE library manager
  https://github.com/Bodmer/Pico_Unicorn_GFX
*/

#include "Adafruit_GFX.h"
#include "Pico_Unicorn_GFX.h"

// By default this example uses the 7x5 GLCD font
// The following small fonts are also available within Adafruit_GFX library
#include <Fonts/Picopixel.h>
#include <Fonts/TomThumb.h>
#include <Fonts/Org_01.h>

PicoUnicorn unicorn = PicoUnicorn();

void setup()
{
  Serial.begin(115200);
  unicorn.init();
  unicorn.clear();
}

void loop() {
  static bool a_pressed = false;
  static bool b_pressed = false;
  static bool x_pressed = false;
  static bool y_pressed = false;

  if (unicorn.is_pressed(unicorn.A)) {
    a_pressed = true;
  }
  if (unicorn.is_pressed(unicorn.B)) {
    b_pressed = true;
  }
  if (unicorn.is_pressed(unicorn.X)) {
    x_pressed = true;
  }
  if (unicorn.is_pressed(unicorn.Y)) {
    y_pressed = true;
  }

  if (a_pressed) {
    unicorn.fillScreen(PICO_RED);
    a_pressed = false;
  }

  if (b_pressed) {
    b_pressed = false;
    unicorn.drawPixel(random(unicorn.WIDTH), random(unicorn.HEIGHT), random(0x10000));
  }

  if (x_pressed) {
    x_pressed = false;
    unicorn.setCursor(0, 0);
    unicorn.setTextColor(PICO_BLUE, PICO_BLACK);
    unicorn.print("Hi!");
  }

  if (y_pressed) {
    y_pressed = false;
    unicorn.clear();
    unicorn.drawLine(0, 0, 15, 6, PICO_GREEN);
  }
}
