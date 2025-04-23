#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <MongolianTextDisplay.h>

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
MongolianTextDisplay mongolText(&tft);

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  mongolText.drawText(10, 40, "ФЦУЖЭНГШҮЗКЪЕЩ", ST77XX_GREEN);
  mongolText.drawText(10, 60, "ЙЫБӨАХРОЛДП", ST77XX_BLUE);
  mongolText.drawText(10, 80, "ЯЧЁСМИТЬВЮ", ST77XX_RED);
}

void loop() {}
