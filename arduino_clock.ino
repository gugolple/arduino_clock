#include "Types.h"
void setup(){
  Serial.begin(115200);
  irSetup();
  ledSetup();
  clockSetup();
  ledLoop();
}
void loop(){
  irLoop();
}
