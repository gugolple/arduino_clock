time_t lastUpdate = now();
    


void input(IrCommand &command){
  lastUpdate = now();
  StateNode* sn = sm.getDirection(command);
  if(sn!=NULL){
    
    DataStruct ds1 = DataStruct();
    DataStruct ds2 = DataStruct();
    sm.getCurrent()->getArgsf()(&ds1);
    sn->getArgsf()(&ds2);
    
    if(command==IrCommand::Up){
      Serial.println(F("Up"));
      animationToTop(sm.getCurrent()->getPrintf(),&ds1,
        sn->getPrintf(),&ds2);
    }else if(command==IrCommand::Down){
      Serial.println(F("Down"));
      animationToBottom(sm.getCurrent()->getPrintf(),&ds1,
        sn->getPrintf(),&ds2);
    }else if(command==IrCommand::Left){
      Serial.println(F("Left"));
      animationToLeft(sm.getCurrent()->getPrintf(),&ds1,
        sn->getPrintf(),&ds2);
    }else if(command==IrCommand::Right){
      Serial.println(F("Right"));
      animationToRight(sm.getCurrent()->getPrintf(),&ds1,
        sn->getPrintf(),&ds2);
    }
    sm.moveDirection(command);
  }
}

void controllerLoop(){
  if(minute(now()-lastUpdate)==1 && !sm.isCurrentState(Status::Time)){
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
