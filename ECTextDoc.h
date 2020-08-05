//
//  ECTextDoc.h
//  project3150
//
//  Created by Reuben Kelechi Ukah on 4/10/20.
//  Copyright © 2020 Reuben Kelechi Ukah. All rights reserved.
//

#ifndef ECTextDoc_h
#define ECTextDoc_h


#include <stdio.h>
#include "ECTextViewImp.h"
#include "ECTextDocument.h"
#include "ECObserver.h"

class ECTextDoc: public ECTextViewImp {
public:
    ECTextDoc(ECTextDocument& document, ECTextDocumentCtrl documentCtrl ) : documentInstance(document), documentInstanceController(documentCtrl)
    {

    }
    ~ECTextDoc(){}
    void InsertCharacter(char charsToAdd ,int yDirection, int xDirection);

    bool returnRow();
    void Initization(std::string &str);


private:
       ECTextDocument& documentInstance;
       ECTextDocumentCtrl documentInstanceController;


};
class ECPositionObserver : public ECObserver{
public:
    ECPositionObserver(ECTextDoc&_window) : _win(_window)
    {


        _win.Attach(this);
        _win.AddStatusRow("This is a status", "True", true);
        _win.Show();
    }

    ~ECPositionObserver()
    {

    }


 void Update(){
    //-Type one character.

    //Getting the pressed Key
    ch = _win.GetPressedKey();
    //Getting cursor key position from last update
    col = _win.GetCursorX();
    row = _win.GetCursorY();
    //Changing the key pressed into alphanumeric character
    char textch = static_cast<char>(ch);
    //Might need switch cases to see the button that were pushed.
    //ARROW_LEFT = 1000
    //ARROW_RIGHT = 1000
    //ARROW_UP = 1000
    //ARROW_DOWN = 100
    //ENTER = 13
    //CTRL-Q = 17
    //UNDO = 21
    //REDO = 18
    //BACKSPACE = 127


    switch (ch) {
        //Quit
        case 17:
        //cout << "Quitting" << endl;
        break;
        //ENTER = 13
        //Adding a new row and continuing on
        case 13:
            cerr << "ENTERED KEY: " << endl;
            _win.SetCursorY(row++);

             col = 0;
            row++;
            //_win.SetCursorX(cx);
            //_win.setRow(row);
            //_win.AddRow();
            _win.SetCursorX(0);
            listText1ofText.clear();

            //text.clear();

            break;
        //UNDO = 21
        //Will have to implement the ECCommand for UNDO
        case 21:
            //cout << "Undoing" << endl;
            break;
        //REDO = 18
        //Will have to implement the ECCommand for REDO
        case 18:
            //cout << "Redoing" << endl;
            break;
        //BACKSPACE = 127
        //ECommand for removal (I believe)
        //Have to figure out how the position
        //And how to implement the updating
        case 127:
           // cout << "Backspace" << endl;
            break;
        //KEY-UP = 72
        //Will have to make cursor move up
        //Will have to get the position
        //Increase the Y++
        //Have to be within the boundaries
        case 72:
            //cout << "Key-Up" << endl;
            break;
        //KEY-DOWN = 80
        //Will have to make the cursor move down
        //Will have to make cursor move up
         //Will have to get the position
         //Increase the Y++
         //Have to be within the boundaries
        case 80:
            //cout << "Key-down" << endl;
            break;
        //KEY-RIGHT = 77
            //key left is moving the cursor to the right.
            //Same as pressing a key and moving the cursor the opposite direction.
            //Sign change
        case 77:
            //cout << "Key-right" << endl;
            break;
        //KEY-LEFT = 75
        //key left is moving the cursor to the left.
        //Same as pressing a key and moving the cursor
        //Will implement the same keys for when the cursor is the same
        case 75:

            //cout << "Key-left" << endl;
            break;
        default:

          if(_win.returnRow()){
            _win.InsertCharacter(textch, row, col);
            string text;
            _win.Initization(text);
            _win.SetCursorY(row);
            _win.InitRows();
            _win.AddRow(text);
            _win.SetCursorY(row);;
            _win.SetCursorX(col+1);
            col++;
            break;
          }else{
            //cerr << "Got here3" << endl;
            cerr << "Got here2" << endl;
            _win.SetCursorY(row);
            _win.InsertCharacter(textch, row, col);

/* Testing to see how Add row works

            _win.AddRow("hihihi");
            _win.AddRow("test3");
            _win.AddRow("test4");
            vector<string> listofStringsTemp;
            for(int i = 0; i < _win.GetRowNumInView(); i++){
              listofStringsTemp.push_back(_win.GetList()[i]);
            }
             listofStringsTemp[0] = "testobj";
             _win.InitRows();
             for(int i = 0; i < listofStringsTemp.size(); i++){
               _win.AddRow(listofStringsTemp[i]);
             }
*/
            _win.SetCursorX(col+1);
            _win.Refresh();
          }
            col++;
            break;
    }

}

private:
    //Just in Case.
    //ECWrapper& _win;
    vector<char>listText1ofText;
    ECTextDoc & _win;
    int x = 0;
    int row;
    int ch;
    int col;
    string text;

};




#endif /* ECTextDoc_h */
