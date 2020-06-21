/**********************************************************
 *  FileName    [ infoMgr.h ]
 *  PackageName [ manager ]
 *  Synopsis    [ Define the information management class ]
 *  Author      [ Harry Huang ]
***********************************************************/

#ifndef INFO_MGR_H
#define INFO_MGR_H


#include "user.h"
#include "object.h"
#include <map>
#include <vector>

using namespace std;

class infoMgr ;

class infoMgr{
public:

    infoMgr(){}
    ~infoMgr();

    //read the storage file
    void readUserTxt();
    void readObjectTxt();



    // write the storage file
    void writeUserTxt();
    void writeObjectTxt();

//--------------------------------------------------------------------------------------------------------
//  functions for system to call //

    // register functions
    bool setIDandPassword(string userID, string Password); // return false if same id exist

    // login functions
    bool login(string userID, string Password); // return false if id don't exist

    // logout functions
    bool logout();              // return false if no _currentUser has login

    // // borrow functions
    bool borrowByID(string id); // return false if object has been borrowed or not exist
                                // and if _currentUser hasn't set

    bool borrowByName(string objName);// return false if there's no available object or not exist
                                        // and if _currentUser hasn't set
    
    //return functions
    bool returnByID(string id); // return false if id not exist or haven't borrowed
                                // and if _currentUser hasn't set 

    bool returnByName(string objName); // return false if haven't borrowed or if _currentUser hasn't set
//---------------------------------------------------------------------------------------------------------
    
    

private:
    map<string, User*> _users;
    map<string, vector<object*> > _objectByName;
    map<string, object*>    _objectByID;
    User*              _currentUser;


};


#endif