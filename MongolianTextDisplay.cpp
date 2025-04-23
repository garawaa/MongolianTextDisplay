#include "MongolianTextDisplay.h"

MongolianTextDisplay::MongolianTextDisplay(Adafruit_ST7735* display) {
  tft = display;
}

void MongolianTextDisplay::drawChar5x8(int x, int y, const byte* bitmap, uint16_t color) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 5; col++) {
      if (bitRead(bitmap[row], 4 - col)) {
        tft->drawPixel(x + col, y + row, color);
      }
    }
  }
}

String MongolianTextDisplay::getUtf8Char(const char*& ptr) {
  String ch;
  if ((uint8_t)*ptr < 0x80) {
    ch += *ptr++;
  } else if ((uint8_t)*ptr >= 0xC0 && (uint8_t)*ptr < 0xE0) {
    ch += *ptr++;
    ch += *ptr++;
  } else if ((uint8_t)*ptr >= 0xE0 && (uint8_t)*ptr < 0xF0) {
    ch += *ptr++;
    ch += *ptr++;
    ch += *ptr++;
  }
  return ch;
}

void MongolianTextDisplay::drawText(int x, int y, const char* utf8Text, uint16_t color) {
  const char* ptr = utf8Text;
  while (*ptr) {
    String ch = getUtf8Char(ptr);
    bool matched = false;
    for (int i = 0; i < 37; i++) {
      if (ch == mongolianLettersUtf8[i]) {
        drawChar5x8(x, y, mongolianBitmaps[i], color);
        matched = true;
        break;
      }
    }
    if (!matched) {
      // drawChar5x8(x, y, mongolianBitmaps[0], ST77XX_RED);
      tft->setCursor(x, y);
      tft->setTextColor(color);
      tft->print(ch.c_str());
    }
    x += 6;
  }
}
