//
//  ECTextDoc.cpp
//  debuggercommandconsole
//
//  Created by Reuben Kelechi Ukah on 4/10/20.
//  Copyright © 2020 Reuben Kelechi Ukah. All rights reserved.
//

#include "ECTextDoc.h"
#include "ECTextViewImp.h"
#include "ECTextDocument.h"


void ECTextDoc::InsertCharacter(char charsToAdd,int yDirection, int xDirection) {

    documentInstance.InsertCharAt(yDirection, charsToAdd);
    cerr << "Checking if it's in the array" << endl;
    for(char i: documentInstance.Getlist()){
      cerr << i << endl;
    }
    //InitRows();

    cerr << "Inserted:" << charsToAdd << endl;
    //ECTextViewImp::Refresh();

}
bool ECTextDoc::returnRow(){
  if(documentInstance.Getlist().empty()){
    cerr << "Got here for the listing of emptiness." << endl;
      return true;
  }else{
    return false;
  }

}
void ECTextDoc::Initization(std::string &str){
  for(char i : documentInstance.Getlist()){
    str.push_back(i);
  }
}
