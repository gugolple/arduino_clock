//Enum for IR control
enum IrCommand{
  Up,Down,Left,Right,Ok,Invalid
};
enum Status{
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
  String str;
  int hours;
  int minutes;
  int seconds;
  DataStruct(int h, int m, int s){
    hours=h;
    minutes=m;
    seconds=s;
  }
  DataStruct(String c){
    str = c;
  }
};
