//
//  ECCommand.cpp
//
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"

// ******************************************************
// Implement command history


ECCommandHistory :: ECCommandHistory() : position(-1)
{
  // your code goes here

}

ECCommandHistory :: ~ECCommandHistory()
{
  // your code goes here
  for(int i = 0; i < listofcommands.size(); i++){
    delete listofcommands[i];
    position = -1;
  }
}

bool ECCommandHistory::Undo(){
  if(position < 0){
    return false;
  }
  listofcommands[position]->UnExecute();
  position--;
  return true;
}
bool ECCommandHistory::Redo(){
  if(position > 0){
    return false;
  }
  listofcommands[position]->Execute();
  position++;
  return true;


}
void ECCommandHistory::ExecuteCmd(ECCommand *pCmd){
    pCmd->Execute();
    listofcommands.push_back(pCmd);

}
