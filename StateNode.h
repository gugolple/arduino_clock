class StateNode{
  private:
    StateNode* left;
    StateNode* right;
    StateNode* up;
    StateNode* down;
    //Prints with arguments required
    void (*printFunct)(Coordinates*,DataStruct*);
    //Retrieves/generates arguments
    void (*getArgs)(DataStruct*);
    Status status;
  public:
    StateNode(){
      left=NULL;
      right=NULL;
      up=NULL;
      down=NULL;
      printFunct = NULL;
      getArgs = NULL;
      status = Status::Time;
    }
    StateNode(Status s,void (*p)(Coordinates*,DataStruct*), void (*a)(DataStruct*)){
      left=NULL;
      right=NULL;
      up=NULL;
      down=NULL;
      printFunct = p;
      getArgs = a;
      status = s;
    }
  
    StateNode* getDirection(const IrCommand &command){
      StateNode* res = NULL;
      //Serial.print("Switch: ");
      //Serial.print(command);
      
      if(command==IrCommand::Up){
        //Serial.println("up");
        res = up;
      }else if(command==IrCommand::Down){
        //Serial.println("down");
        res = down;
      }else if(command==IrCommand::Left){
        //Serial.println("left");
        res = left;
      }else if(command==IrCommand::Right){
        //Serial.println("right");
        res = right;
      }else{
        //Serial.println("sad");
      }
      return res;
    }
    void setNodeLeft(StateNode* sn){
      left = sn;
    }
    void setNodeRight(StateNode* sn){
      right = sn;
    }
    void setNodeUp(StateNode* sn){
      up = sn;
    }
    void setNodeDown(StateNode* sn){
      down = sn;
    }
    Status getStatus(){
      return status;
    }
    void (*getPrintf(void))(Coordinates*,DataStruct*){
      return printFunct;
    }
    void (*getArgsf(void))(DataStruct*){
      return getArgs;
    }

    void checkNulls(){
      Serial.print(F("Left "));
      Serial.println(left==NULL);
      Serial.print(F("Right" ));
      Serial.println(right==NULL);
      Serial.print(F("Up" ));
      Serial.println(up==NULL);
      Serial.print(F("Down"));
      Serial.println(down==NULL);
    }
};
