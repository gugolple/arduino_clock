#include <Time.h>

int lastSeconds = second();
void clockLoop(){
  if(lastSeconds != second() && sm.isCurrentState(Status::Time)){
    //Serial.println("SecondPassed");
    lastSeconds = second();
    clearScreen();
    DataStruct ds = DataStruct();
    timeState.getArgsf()(&ds);
    timeState.getPrintf()(&Coordinates(0,0),&ds);
    printScreen();
  }
}

void getClockStruct(DataStruct* args){
  args->hours = hour();
  args->minutes = minute();
  args->seconds = second();
}

void getDayMonth(DataStruct* args){
  sprintf(args->str,"%02d%s",day(),monthShortStr(month()));
}

void getYear(DataStruct* args){
  sprintf(args->str,"%d",year());
}
