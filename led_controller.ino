#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

uint16_t currentColor = matrix.Color(255,0,255);
uint16_t lastColor = matrix.Color(255,0,255);

const int ANIMATION_SPEED_HORIZONTAL = 50;

void ledSetup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);
}

int x    = 0;
int pass = 0;

void setPrintScreen(Coordinates* coor, DataStruct* mesg){
  setScreen(coor, mesg->str);
  printScreen();
}

void setPrintScreen(Coordinates* coor,const char* mesg){
  setScreen(coor, mesg);
  printScreen();
}

void setScreen(Coordinates* coor, DataStruct* mesg){
  setScreen(coor,mesg->str);
}

void setScreen(Coordinates* coor, const char * mesg){
  Serial.println(mesg);
  matrix.setCursor(coor->x, coor->y);
  matrix.print(mesg);
  matrix.setTextColor(currentColor);
}

void clearScreen(){
  matrix.fillScreen(0);
}

void printScreen(){
  noInterrupts();
  matrix.show();
  interrupts();
}
