#include "Types.h"
Status currentStatus = Status::Clock;
void setup(){
  Serial.begin(115200);
  irSetup();
  ledSetup();
  clockSetup();
  //irConfigure(); temporarily disabled
}
void loop(){
  irLoop();
  clockLoop();
}
