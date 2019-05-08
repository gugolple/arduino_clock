class StateNode{
  public:
    StateNode* left;
    StateNode* right;
    StateNode* up;
    StateNode* down;
    //Prints with arguments required
    void (*printFunct)(Coordinates*,DataStruct*);
    //Retrieves/generates arguments
    void (*getArgs)(DataStruct*);
    Status status;
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
  
    const StateNode* getDirection(IrCommand command){
      switch(command){
        Left: return left;
        Right: return right;
        Up: return up;
        Down: return down;
        default: return NULL;
      }
    }
    
};
