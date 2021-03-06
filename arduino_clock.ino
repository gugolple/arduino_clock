#include "Types.h"
#include "StateMachine.h"
void setup(){
  Serial.begin(115200);
  setUpStateMachine();
  irSetup();
  ledSetup();
  irConfigure();
}
void loop(){
  irLoop();
  clockLoop();
  controllerLoop();
}
