
StateNode timeState = StateNode(Status::Time, &clockScreen, &getClockStruct);
StateNode dayMonthState = StateNode(Status::DayMonth, &setPrintScreen, &getDayMonth);
StateNode yearState = StateNode(Status::Year, &setPrintScreen, &getYear);
StateNode configColorState = StateNode(Status::ConfigColor, &setPrintScreen, &getColorString);
StateNode configDateState = StateNode(Status::ConfigDate, &setPrintScreen, &getDateString);
StateNode setColorRState = StateNode(Status::SetColorR, &setPrintScreen, &getRedString);
StateNode setColorGState = StateNode(Status::SetColorG, &setPrintScreen, &getGreenString);
StateNode setColorBState = StateNode(Status::SetColorB, &setPrintScreen, &getBlueString);

//TODO
StateNode setTimeState = StateNode(Status::SetTime, &clockScreen, &getClockStruct);
StateNode setDayMonthState = StateNode(Status::SetDayMonth, &setPrintScreen, &getDayMonth);
StateNode setYearState = StateNode(Status::SetYear, &setPrintScreen, &getYear);


StateMachine sm(&timeState);

//Only linking where it should move
void setUpStateMachine(){
  timeState.up = &yearState;
  timeState.down = &dayMonthState;
  timeState.right = &configColorState;

  dayMonthState.up = &timeState;
  dayMonthState.down = &yearState;
  dayMonthState.right = &configColorState;
  
  yearState.up = &dayMonthState;
  yearState.down = &timeState;
  yearState.right = &configColorState;
  
  configColorState.up = &configDateState;
  configColorState.down = &configDateState;
  configColorState.left = &timeState;
  configColorState.right = &setColorGState;
  
  setColorGState.up = &setColorRState;
  setColorGState.down = &setColorBState;
  setColorGState.left = &configColorState;
  
  setColorRState.up = &setColorBState;
  setColorRState.down = &setColorGState;
  setColorRState.left = &configColorState;
  
  setColorBState.up = &setColorGState;
  setColorBState.down = &setColorRState;
  setColorBState.left = &configColorState;
  
  configDateState.up = &configColorState;
  configDateState.down = &configColorState;
  configDateState.left = &timeState;
  configDateState.right = &setTimeState;
  
  setTimeState.up = &setDayMonthState;
  setTimeState.down = &setYearState;
  setTimeState.left = &configDateState;
  
  setDayMonthState.up = &setYearState;
  setDayMonthState.down = &setTimeState;
  setDayMonthState.left = &configDateState;
  
  setYearState.up = &setTimeState;
  setYearState.down = &setDayMonthState;
  setYearState.left = &configDateState;
}
