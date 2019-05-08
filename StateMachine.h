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
    StateNode* getDirection(const IrCommand &command){
      return current->getDirection(command);
    }
    StateNode* getCurrent(){
      return current;
    }
    void moveDirection(const IrCommand &command){
      current = current->getDirection(command);
    }
    void setCurrent(StateNode* sn){
      current = sn;
    }
    void setDefault(){
      current = defaultState;
    }
    bool isCurrentState(const Status &s){
      return getCurrent()->getStatus() == s;
    }
    Status getCurrentStatus(){
      return getCurrent()->getStatus();
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
