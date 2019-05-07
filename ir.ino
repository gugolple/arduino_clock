#include <IRremote.h>

const int RECV_PIN = 11;
const int CONFIG_PIN = 12;
const int MAX_SIZE = 5; //Amount of desired inputs
const char mesg[6][8] = {"Up","Down","Left","Right","Ok","INVLAID"};
int control_matrix[MAX_SIZE];
decode_results results;
long last;

IRrecv irrecv(RECV_PIN);
void irSetup(){
  pinMode(CONFIG_PIN, INPUT_PULLUP);
  irrecv.enableIRIn();
}

void irLoop(){
  IrCommand current = scanGetInput();
  if(digitalRead(CONFIG_PIN)==LOW){
    Serial.println("Configure");
    irConfigure();
  }
}

void irConfigure(){
  for(int i=0;i<MAX_SIZE;i++){
    //Send expected button
    setPrintScreen(mesg[i]);
    //Wait until a valid input
    while(!irRead() && last != results.value);
    control_matrix[i] = results.value;
    last = results.value;
  }
  setPrintScreen("Done!");
}

IrCommand scanGetInput(){
  if(irRead()){
    return getInput();
  }
  return IrCommand::Invalid;
}

IrCommand getInput(){
  for(int i=0;i<MAX_SIZE;i++){
    if(control_matrix[i] == results.value){
      return static_cast<IrCommand>(i);
    }
  }
  return IrCommand::Invalid;
}

bool irRead(){
  bool r = false;
  if (irrecv.decode(&results)) {
    //SANYO shows as invalid codes of 0 length
    //if(results.decode_type!=SANYO)
    {
      // Print Code
      Serial.println(results.value, HEX);
      irrecv.resume();              // Prepare for the next value
      r = true;
    }
  }
  return r;
}
