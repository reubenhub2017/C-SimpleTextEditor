//
//  mainWin.cpp
//  project3150
//
//  Created by Reuben Kelechi Ukah on 4/10/20.
//  Copyright © 2020 Reuben Kelechi Ukah. All rights reserved.
//

#include <stdio.h>


#include "ECObserver.h"
#include "ECTextViewImp.h"
#include "ECTextDocument.h"
#include "ECCommand.h"
#include "ECTextDoc.h"


#include <vector>
using namespace std;


int main(int argc, char *argv[])
{

    ECTextDocument doc;
    ECTextDocumentCtrl docCtrl = doc.GetCtrl();
    ECTextDoc wndTest(doc, docCtrl);
    ECPositionObserver obtest(wndTest);
    //obtest.Update();
    wndTest.Show();





    return 0;
}
