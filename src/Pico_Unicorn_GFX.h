#pragma once

#include "Adafruit_GFX.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include <time.h>

#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

// Color definitions
#define PICO_BLACK 0x0000       ///<   0,   0,   0
#define PICO_NAVY 0x000F        ///<   0,   0, 123
#define PICO_DARKGREEN 0x03E0   ///<   0, 125,   0
#define PICO_DARKCYAN 0x03EF    ///<   0, 125, 123
#define PICO_MAROON 0x7800      ///< 123,   0,   0
#define PICO_PURPLE 0x780F      ///< 123,   0, 123
#define PICO_OLIVE 0x7BE0       ///< 123, 125,   0
#define PICO_LIGHTGREY 0xC618   ///< 198, 195, 198
#define PICO_DARKGREY 0x7BEF    ///< 123, 125, 123
#define PICO_BLUE 0x001F        ///<   0,   0, 255
#define PICO_GREEN 0x07E0       ///<   0, 255,   0
#define PICO_CYAN 0x07FF        ///<   0, 255, 255
#define PICO_RED 0xF800         ///< 255,   0,   0
#define PICO_MAGENTA 0xF81F     ///< 255,   0, 255
#define PICO_YELLOW 0xFFE0      ///< 255, 255,   0
#define PICO_WHITE 0xFFFF       ///< 255, 255, 255
#define PICO_ORANGE 0xFD20      ///< 255, 165,   0
#define PICO_GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define PICO_PINK 0xFC18        ///< 255, 130, 198

//namespace pimoroni {

  class PicoUnicorn : public Adafruit_GFX {
  public:
    static const int WIDTH = 16;
    static const int HEIGHT = 7;
    static const uint8_t A = 12;
    static const uint8_t B = 13;
    static const uint8_t X = 14;
    static const uint8_t Y = 15;
  private:
    PIO bitstream_pio = pio0;
    uint bitstream_sm = 0;
    uint sm_offset = 0;
  public:
    PicoUnicorn();
    ~PicoUnicorn();

    void init();

    void clear();

    void set_pixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
    void set_pixel(uint8_t x, uint8_t y, uint8_t v);

    bool is_pressed(uint8_t button);

    void from_hsv(float h, float s, float v, uint8_t &r, uint8_t &g, uint8_t &b);

    // The Adafruit_GFX library will use this fn for all graphics operations
    void drawPixel(int16_t x, int16_t y, uint16_t color);

    // Compatibility functions
    void begin(void);
    uint16_t color565(uint8_t r, uint8_t g, uint8_t b);
  };

//}
