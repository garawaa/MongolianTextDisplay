#ifndef MONGOLIAN_TEXT_DISPLAY_H
#define MONGOLIAN_TEXT_DISPLAY_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "bitmaps.h"

class MongolianTextDisplay {
public:
  MongolianTextDisplay(Adafruit_ST7735* display);
  void drawText(int x, int y, const char* utf8Text, uint16_t color = ST77XX_YELLOW);

private:
  Adafruit_ST7735* tft;
  String getUtf8Char(const char*& ptr);
  void drawChar5x8(int x, int y, const byte* bitmap, uint16_t color);
};

#endif
