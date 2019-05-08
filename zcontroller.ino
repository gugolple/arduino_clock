time_t lastUpdate = now();


void input(IrCommand command){
  lastUpdate = now();
  StateNode* sn = sm.getDirection(command);
  if(sn!=NULL){
    DataStruct ds1 = DataStruct();
    sm.getCurrent()->getArgs(&ds1);
    DataStruct ds2 = DataStruct();
    sn->getArgs(&ds2);
    switch(command){
      Up:
        animationToTop(sm.getCurrent()->printFunct,&ds1,
          sn->printFunct,&ds2);
        break;
      Down:
        animationToBottom(sm.getCurrent()->printFunct,&ds1,
          sn->printFunct,&ds2);
        break;
      Left:
        animationToLeft(sm.getCurrent()->printFunct,&ds1,
          sn->printFunct,&ds2);
        break;
      Right:
        animationToRight(sm.getCurrent()->printFunct,&ds1,
          sn->printFunct,&ds2);
        break;
    }
  }
}

void controllerLoop(){
  if(minute(now()-lastUpdate)==1 && sm.getCurrent()->status!=Status::Time){
    sm.setDefault();
  }
}

void getColorString(DataStruct* args){
  sprintf((char*)args,"Color");
}

void getRedString(DataStruct* args){
  sprintf((char*)args,"Red");
}

void getGreenString(DataStruct* args){
  sprintf((char*)args,"Green");
}

void getBlueString(DataStruct* args){
  sprintf((char*)args,"Blue");
}

void getDateString(DataStruct* args){
  sprintf((char*)args,"Date");
}
