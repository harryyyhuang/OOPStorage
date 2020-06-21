#include "user.h"
#include "object.h"
#include "infoMgr.h"
#include <iostream>

using namespace std;

int main(){
    infoMgr* test = new infoMgr();
    test->readObjectTxt();
    test->readUserTxt();

    // if(!test->setIDandPassword("Peter", "Aa19860601")) cout << "already in database" << endl;
    // else                                               cout << "register success" << endl;

    // if(!test->login("Peter", "Aa19860601")) cout << "not in database" << endl;
    // if(test->borrowByName("Pen")) cout << "Borrow succeed" << endl;
    // else                            cout << "Borrow failed"  << endl;

    // if(test->borrowByName("Pen")) cout << "Borrow succeed" << endl;
    // else                            cout << "Borrow failed"  << endl;

    // if(test->borrowByName("Pen")) cout << "Borrow succeed" << endl;
    // else                            cout << "Borrow failed"  << endl;

    // if(test->borrowByName("Pen")) cout << "Borrow succeed" << endl;
    // else                            cout << "Borrow failed"  << endl;

    // if(test->returnByName("Pen")) cout << "Return succeed" << endl;
    // else                          cout << "Return failed"  << endl;

    // if(test->borrowByName("Pen")) cout << "Borrow succeed" << endl;
    // else                            cout << "Borrow failed"  << endl;

    test->writeObjectTxt();
    test->writeUserTxt();

    delete test;
    for(int i = 0; i < 10000; ++i){
        infoMgr* test = new infoMgr();
        delete test;
    }



 
    
    // test->login("Harry", "Aa1919");
    // test->login("Harry", "Aa1919");
}

