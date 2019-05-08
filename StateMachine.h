#include "StateNode.h"
class StateMachine{
  private:
    StateNode* defaultState;
    StateNode* current;
  public:
    StateMachine(StateNode* def){
      defaultState = def;
      current = def;
    }
    StateNode* getDirection(IrCommand command){
      current->getDirection(command);
    }
    StateNode* getCurrent(){
      return current;
    }
    void moveDirection(IrCommand command){
      current = current->getDirection(command);
    }
    void setCurrent(StateNode* sn){
      current = sn;
    }
    void setDefault(){
      current = defaultState;
    }
};

/* The status tree goes like so
 * 
 *  Time >---
 *  <|>       |     --<> Date -----<>SetTime
 *  Day <-> Color---|            |    <|>
 *  <|>       |     --<> G       |---SetDay
 *  Year >---       |   <|>      |    <|>
 *                   ---<R       |---SetYear
 *                  |   <|>
 *                   ---<B
 */
