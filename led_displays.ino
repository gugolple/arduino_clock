void clockScreen(Coordinates* coor, DataStruct* arg){
  matrix.fillScreen(0);
  char buf[3];
  sprintf(buf,"%02d",arg->hours);
  matrix.setCursor(0+coor->x, 0+coor->y);
  matrix.print(buf[0]);
  matrix.setCursor(5+coor->x, 0+coor->y);
  matrix.print(buf[1]);
  sprintf(buf,"%02d",arg->minutes);
  matrix.setCursor(11+coor->x, 0+coor->y);
  matrix.print(buf[0]);
  matrix.setCursor(16+coor->x, 0+coor->y);
  matrix.print(buf[1]);
  sprintf(buf,"%02d",arg->seconds);
  matrix.setCursor(22+coor->x, 0+coor->y);
  matrix.print(buf[0]);
  matrix.setCursor(27+coor->x, 0+coor->y);
  matrix.print(buf[1]);
  matrix.setTextColor(currentColor);
}
