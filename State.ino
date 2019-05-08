
StateNode timeState = StateNode(Status::Time, &clockScreen, &getClockStruct);
StateNode dayMonthState = StateNode(Status::DayMonth, &setScreen, &getDayMonth);
StateNode yearState = StateNode(Status::Year, &setScreen, &getYear);
StateNode configColorState = StateNode(Status::ConfigColor, &setScreen, &getColorString);
StateNode configDateState = StateNode(Status::ConfigDate, &setScreen, &getDateString);
StateNode setColorRState = StateNode(Status::SetColorR, &setScreen, &getRedString);
StateNode setColorGState = StateNode(Status::SetColorG, &setScreen, &getGreenString);
StateNode setColorBState = StateNode(Status::SetColorB, &setScreen, &getBlueString);

//Empty only when configuring IR
StateNode configureIRState = StateNode(Status::ConfigIR, NULL, NULL);

//TODO
StateNode setTimeState = StateNode(Status::SetTime, &clockScreen, &getClockStruct);
StateNode setDayMonthState = StateNode(Status::SetDayMonth, &setScreen, &getDayMonth);
StateNode setYearState = StateNode(Status::SetYear, &setScreen, &getYear);


StateMachine sm = NULL;

//Only linking where it should move
void setUpStateMachine(){
  timeState.setNodeUp(&yearState);
  timeState.setNodeDown(&dayMonthState);
  timeState.setNodeRight(&configColorState);

  dayMonthState.setNodeUp(&timeState);
  dayMonthState.setNodeDown(&yearState);
  dayMonthState.setNodeRight(&configColorState);
  
  yearState.setNodeUp(&dayMonthState);
  yearState.setNodeDown(&timeState);
  yearState.setNodeRight(&configColorState);
  
  configColorState.setNodeUp(&configDateState);
  configColorState.setNodeDown(&configDateState);
  configColorState.setNodeLeft(&timeState);
  configColorState.setNodeRight(&setColorGState);
  
  setColorGState.setNodeUp(&setColorRState);
  setColorGState.setNodeDown(&setColorBState);
  setColorGState.setNodeLeft(&configColorState);
  
  setColorRState.setNodeUp(&setColorBState);
  setColorRState.setNodeDown(&setColorGState);
  setColorRState.setNodeLeft(&configColorState);
  
  setColorBState.setNodeUp(&setColorGState);
  setColorBState.setNodeDown(&setColorRState);
  setColorBState.setNodeLeft(&configColorState);
  
  configDateState.setNodeUp(&configColorState);
  configDateState.setNodeDown(&configColorState);
  configDateState.setNodeLeft(&timeState);
  configDateState.setNodeRight(&setTimeState);
  
  setTimeState.setNodeUp(&setDayMonthState);
  setTimeState.setNodeDown(&setYearState);
  setTimeState.setNodeLeft(&configDateState);
  
  setDayMonthState.setNodeUp(&setYearState);
  setDayMonthState.setNodeDown(&setTimeState);
  setDayMonthState.setNodeLeft(&configDateState);
  
  setYearState.setNodeUp(&setTimeState);
  setYearState.setNodeDown(&setDayMonthState);
  setYearState.setNodeLeft(&configDateState);
  Serial.println("All ready!");
  timeState.checkNulls();
  sm = StateMachine(&timeState);
}
