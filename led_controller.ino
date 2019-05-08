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
  setScreen(coor, mesg->str.c_str());
  printScreen();
}

void setPrintScreen(Coordinates* coor,const char* mesg){
  setScreen(coor, mesg);
  printScreen();
}

void setScreen(Coordinates* coor, const char * mesg){
  matrix.fillScreen(0);
  matrix.setCursor(coor->x, coor->y);
  matrix.print(mesg);
  matrix.setTextColor(currentColor);
}

void printScreen(){
  noInterrupts();
  matrix.show();
  interrupts();
}

//Animations of transitions //////////////////////////////////////

void animationToLeft(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(matrix.width() ,0);
    
    for(int i=0;i<matrix.width();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x-=i;
      c2.x-=i;
    }
}

void animationToRight(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(-matrix.width() ,0);
    
    for(int i=0;i<matrix.width();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x+=i;
      c2.x+=i;
    }
}

void animationToTop(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(0,-matrix.height());
    
    for(int i=0;i<matrix.height();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x+=i;
      c2.x+=i;
    }
}

void animationToBottom(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(0,matrix.height());
    
    for(int i=0;i<matrix.height();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x-=i;
      c2.x-=i;
    }
}
