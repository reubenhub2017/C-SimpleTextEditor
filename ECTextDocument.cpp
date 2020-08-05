//
//  ECTextDocument.cpp
//
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECTextDocument.h"
#include <iostream>
#include <vector>
#include <iterator>

#include <cctype>

using namespace std;

// **********************************************************
// Commands
// your code goes here
//Cap Command

ECCommandCap :: ECCommandCap(ECTextDocument &docIn, int pos, int lenToCap) : doc(docIn), lenToCapitalize(lenToCap), position(pos)
{

}
ECCommandCap::~ECCommandCap() {

}
void ECCommandCap::Execute(){
  int currCharacter = 0;
  while(currCharacter < lenToCapitalize){
    doc.CapCharAt(position + currCharacter);
    currCharacter++;
  }
}

void ECCommandCap::UnExecute(){
  
}
//Low Command

ECCommandLow::ECCommandLow(ECTextDocument &docIn, int posInIns, int lenToLow) : doc(docIn),pos(posInIns), lenToLower(lenToLower)
{
}
ECCommandLow::~ECCommandLow() {

}
void ECCommandLow::Execute(){
  int currCharacter = 0;
  while(currCharacter < lenToLower){
    doc.LowerCharAt(pos + currCharacter);
    currCharacter++;

}
}

void ECCommandLow::UnExecute(){
  return;
}
//insert Commands
ECCommandInsert::ECCommandInsert(ECTextDocument &docIn, int pos, const std::vector<char> &listCharsToIns):doc(docIn),position(pos), listChars(listCharsToIns)
{
}
ECCommandInsert::~ECCommandInsert() {

}
void ECCommandInsert::Execute(){
  vector<char>temp;
  int counter = 0;
  for(int c = listChars.size()-1; c >= 0; c--){
    temp.push_back(listChars[c]);
  }

  for(int i = 0; i < temp.size(); i++){
    doc.InsertCharAt(position, temp[i]);
  }
}

void ECCommandInsert::UnExecute(){
  return;
}

//Remove Commands

ECCommandRemove::ECCommandRemove(ECTextDocument &docIn, int pos, int lenToRemove):doc(docIn), pos(pos), lenToRemove(lenToRemove)
{
}
ECCommandRemove::~ECCommandRemove() {

}
void ECCommandRemove::Execute(){
  if(pos > doc.GetDocLen()){
    return;
  }else{
      for(int i = 0; i < lenToRemove; i++){
        doc.RemoveCharAt(pos);
      }
  }
}

void ECCommandRemove::UnExecute(){
  return;
}

// **********************************************************
// Controller for text document

ECTextDocumentCtrl::ECTextDocumentCtrl(ECTextDocument &docIn): doc(docIn)
{

}

ECTextDocumentCtrl::~ECTextDocumentCtrl()
{
}
ECTextDocument ECTextDocumentCtrl::Getdoc() {
  return doc;
}
void ECTextDocumentCtrl::InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  // your code
  ECCommandInsert *pCmdInsert = new ECCommandInsert(this->doc, pos, listCharsToIns);
}

void ECTextDocumentCtrl::RemoveTextAt(int pos, int lenToRemove)
{
  // your code
  ECCommandRemove *pCmdRemove = new ECCommandRemove(this->doc, pos,lenToRemove);
  histCmds.ExecuteCmd(pCmdRemove);

}

void ECTextDocumentCtrl::CapTextAt(int pos, int lenToCap)
{

      ECCommandCap *pCmdCap= new ECCommandCap(this->doc, pos, lenToCap);
      histCmds.ExecuteCmd(pCmdCap);
}
void ECTextDocumentCtrl::LowerTextAt(int pos, int lenToLower)
{
    ECCommandLow *pCmdLow = new ECCommandLow(this->doc, pos,lenToLower);
    histCmds.ExecuteCmd(pCmdLow);
  }


bool ECTextDocumentCtrl::Undo()
{
  // your code
  
  return histCmds.Undo();

}

bool ECTextDocumentCtrl::Redo()
{
  // your code
  return histCmds.Redo();

}

// **********************************************************
// Document for text document


ECTextDocument::ECTextDocument():docCtrl(*this)
{
}

ECTextDocument::~ECTextDocument()
{
}

ECTextDocumentCtrl&ECTextDocument::GetCtrl()
{
    return docCtrl;
}

char ECTextDocument::GetCharAt(int pos) const
{
    return listChars[pos];
}
std::vector<char> ECTextDocument:: Getlist(){
  return listChars;
}

void ECTextDocument::InsertCharAt(int pos, char ch)
{
  // your code here
      listChars.insert(listChars.begin() + pos, ch);

}

void ECTextDocument::RemoveCharAt(int pos)
{

  // your code here
  //listChars.erase(listChars.begin()+pos, listChars[pos]);
  listChars.erase(listChars.begin() + pos);


}

void ECTextDocument::CapCharAt(int pos)
{
  // your code here
    listChars[pos] = toupper(listChars[pos]);

  }


void ECTextDocument::LowerCharAt(int pos)
{
  // your code here
    cout << tolower(listChars[pos]) << endl;
    listChars[pos] = tolower(listChars[pos]);
}
