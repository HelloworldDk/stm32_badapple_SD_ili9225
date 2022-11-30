// Include application, user and local libraries
#include <SPI.h>
#include <SD.h>
#include "FreeStack.h"
#include <SPI.h>


#include "TFT_22_ILI9225.h"

#define TFT_RST PA1
#define TFT_RS  PA2
#define TFT_CS  PA0 // SS
#define TFT_SDI PA7 // MOSI
#define TFT_CLK PA5 // SCK
#define TFT_LED 0   // 0 if wired to +5V directly

#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);

#define maxn 4167
#define imgw 20
#define imgh 120

#define allpix (imgw*imgh)

static uint8_t BA[7000];

// Setup
uint64_t times;
char buf[120];
File myFile;
void setup() {
  SD.begin(PB6);
  tft.begin();
  tft.setOrientation(1);
  tft.setFont(Terminal6x8);
  times = micros();
}

// Loop
uint16_t aa;
uint8_t tt;
void loop() {
  myFile = SD.open("vb2.bin", FILE_READ);
  while (!myFile.available());


  for (int i = 1; i <= maxn; i += 1) {

    for (int fr = 0; fr < allpix ; fr++)
    {
      BA[fr] = ~myFile.read();
    }
    tft.drawBitmap(28, 30, BA, 160, 120, COLOR_WHITE, COLOR_BLACK);
    double fps = double(1000000) / (micros() - times); 
    if (fps > 19.0) {
      while ((double(1000000) / (micros() - times)) >19.749);
    }
    fps = double(1000000) / (micros() - times);
    
    sprintf(buf, "FPS: %.4lf", fps);
    tft.drawText(0, 0, buf, COLOR_WHITE);

    times = micros();

  }
  myFile.close();
delay(1);
}
