#include <IRremote.h>

const int RECV_PIN = 11;
const int CONFIG_PIN = 12;
const int MAX_SIZE = 5; //Amount of desired inputs
const char mesg[6][8] = {"Up","Down","Left","Right","Ok","INVLAID"};
unsigned long control_matrix[MAX_SIZE];
decode_results results;


IRrecv irrecv(RECV_PIN);
void irSetup(){
  pinMode(CONFIG_PIN, INPUT_PULLUP);
  irrecv.enableIRIn();
}

void irLoop(){
  IrCommand current = scanGetInput();
  if(current!=IrCommand::Invalid){
    Serial.println(current);
    input(current);
  }
  if(digitalRead(CONFIG_PIN)==LOW){
    Serial.println("Configure");
    irConfigure();
  }
}


//Configure inputs of remote
void irConfigure(){
  unsigned long lastButton = 1;
  for(int i=0;i<MAX_SIZE;i++){
    Serial.println(mesg[i]);
    //Send expected button
    setPrintScreen(mesg[i]);

    //Current pair of values
    unsigned long lastValue = 0;
    unsigned long current = 0;
    //Wait until a valid input that is different from last pressed button
    //mitigating extreme repetition of remote
    while(lastValue == current || current==lastButton){
      while(!irRead());
      current = results.value;
      Serial.println(current);
    };
    control_matrix[i] = current;
    lastValue = current;
    lastButton = current;
  }
  Serial.println("Done!");
  setPrintScreen("Done!");
}

//Transform input into usable values
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
    //removing 0xFFFFFFFF, means repeat last action, universal
    if(results.value != 0xFFFFFFFF)
    {
      // Print Code
      Serial.println(results.value, HEX);
      r = true;
    }
    //Dont forget to resume if want to read next value
    irrecv.resume();              // Prepare for the next value
  }
  return r;
}
