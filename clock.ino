#include <Time.h>

int lastSeconds = second();
void clockLoop(){
  if(lastSeconds != second() && sm.isCurrentState(Status::Time)){
    //Serial.println("SecondPassed");
    lastSeconds = second();
    DataStruct t = DataStruct(hour(),minute(),second());
    Coordinates c = Coordinates(0,0);
    clockScreen(&c,&t);
  }
}

void getClockStruct(DataStruct* args){
  args->hours = hour();
  args->minutes = minute();
  args->seconds = second();
}

void getDayMonth(DataStruct* args){
  char c[7];
  sprintf(c,"%02d %s",day(),monthShortStr(now()));
  args->str = c;
}

void getYear(DataStruct* args){
  char c[7];
  sprintf(c,"%d",year());
  args->str = c;
}
