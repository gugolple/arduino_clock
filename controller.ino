time_t lastUpdate = now();


void input(IrCommand command){
  lastUpdate = now();
  StateNode* sn = sm.getDirection(command);
  if(sn!=NULL){
    switch(command){
      Up: 
        break;
      Down:
      Left:
      Right:
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
