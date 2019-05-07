#include <Time.h>

void clockSetup(){
}

void digitalClockDisplay(){
  // digital clock display of the time
  printDigits(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void stringDigits(int d, char* c){
  
}

int lastSeconds = second();
void clockLoop(){
  if(currentStatus == Status::Clock && lastSeconds != second()){
    char res[9];
    sprintf(res, "%02d:%02d:%02d", hour(),minute(),second());
    Serial.println(res);
    setPrintScreen(res);
  }
}
