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
  matrix.setBrightness(10);
}

int x    = 0;
int pass = 0;

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

void clockScreen(int hours, int minutes, int seconds){
  matrix.fillScreen(0);
  char buf[3];
  sprintf(buf,"%02d",hours);
  matrix.setCursor(0, 0);
  matrix.print(buf[0]);
  matrix.setCursor(5, 0);
  matrix.print(buf[1]);
  sprintf(buf,"%02d",minutes);
  matrix.setCursor(11, 0);
  matrix.print(buf[0]);
  matrix.setCursor(16, 0);
  matrix.print(buf[1]);
  sprintf(buf,"%02d",seconds);
  matrix.setCursor(22, 0);
  matrix.print(buf[0]);
  matrix.setCursor(27, 0);
  matrix.print(buf[1]);
  matrix.setTextColor(matrix.Color(255, 0, 255));
  printScreen();
}

void printScreen(){
  noInterrupts();
  matrix.show();
  interrupts();
}
