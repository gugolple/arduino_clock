//Enum for IR control
enum IrCommand{
  Up,Down,Left,Right,Ok,Invalid
};
enum Status{
  ConfigIR,
  Time, DayMonth, Year,
  ConfigColor, ConfigDate,
  SetTime, SetDayMonth, SetYear,
  SetColorR, SetColorG, SetColorB
};

//Visual Structs
struct Coordinates{
  int x;
  int y;
  Coordinates(int xp, int yp){
    x=xp;
    y=yp;
  }
};

struct DataStruct{
  char str[8];
  int hours;
  int minutes;
  int seconds;
  DataStruct(){
    hours=0;
    minutes=0;
    seconds=0;
  }
  DataStruct(int h, int m, int s){
    hours=h;
    minutes=m;
    seconds=s;
  }
  DataStruct(char c){
    strcpy(c, str);
  }
};
