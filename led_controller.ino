#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void ledSetup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
}

int x    = 0;
int pass = 0;

//placeholder to check correct working without needing serial input
void ledLoop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("Howdy"));
  if(--x < -36) {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  printScreen();
}

void setPrintScreen(const char * mesg){
  setScreen(mesg);
  printScreen();
}

void setScreen(const char * mesg){
  matrix.fillScreen(0);
  matrix.setCursor(0, 0);
  matrix.print(mesg);
  matrix.setTextColor(colors[0]);
}

void printScreen(){
  noInterrupts();
  matrix.show();
  interrupts();
}
