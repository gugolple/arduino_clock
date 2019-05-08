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

//Animations of transitions //////////////////////////////////////

void animationToLeft(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(matrix.width() ,0);
    
    for(int i=0;i<matrix.width();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x-=i;
      c2.x-=i;
    }
}

void animationToRight(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(-matrix.width() ,0);
    
    for(int i=0;i<matrix.width();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x+=i;
      c2.x+=i;
    }
}

void animationToTop(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(0,-matrix.height());
    
    for(int i=0;i<matrix.height();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x+=i;
      c2.x+=i;
    }
}

void animationToBottom(void (*f1)(Coordinates*,DataStruct*),DataStruct* arg1,
    void (*f2)(Coordinates*,DataStruct*),DataStruct* arg2){
      
    Coordinates c1 = Coordinates(0,0);
    Coordinates c2 = Coordinates(0,matrix.height());
    
    for(int i=0;i<matrix.height();i++){
      f1(&c1,arg1);
      f2(&c2,arg2);
      delay(ANIMATION_SPEED_HORIZONTAL);
      c1.x-=i;
      c2.x-=i;
    }
}
