/**********************************************************
 *  FileName    [ infoMgr.cpp ]
 *  PackageName [ manager ]
 *  Synopsis    [ Define the information management class ]
 *  Author      [ Harry Huang ]
***********************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "infoMgr.h"
#include "user.h"
#include "object.h"
#include "util.h"


using namespace std;

/**********************************/
/*  Global variable and enum      */
/**********************************/
// infoMgr* infoMgr = 0;


/**********************************/
/*  class infoMgr member function */
/**********************************/
void infoMgr::readObjectTxt(){
    ifstream fin("objects.txt");
    string s;

    // make sure it's objects.txt
    getline(fin, s);
    assert(s == "Item");

    // get the number of objects
    getline(fin, s);
    int itemNumber ;
    itemNumber = getNum(s);

    // get the info 
    for(int i = 0; i < itemNumber; ++i){
        int objectNumber;
        string objectName;
        vector<object*> tmpobjects;

        getline(fin, objectName);
        getStringAndNum(objectName, objectNumber);

        for(int j = 0; j < objectNumber; ++j){
            string objectID;
            getline(fin, s);
            objectID = getString(s);
            object* tmpobject = new object();
            tmpobject->setName(objectName);
            tmpobject->setID(objectID);
            _objectByID.insert(pair<string, object*>(objectID, tmpobject));
            tmpobjects.push_back(tmpobject);
        }
        
        _objectByName.insert(pair<string, vector<object*> >(objectName, tmpobjects));
        
    }

    fin.close();

}

void infoMgr::readUserTxt(){
    ifstream fin("storage.txt");
    string s;
    stringstream ss;

    // make sure it's users.txt
    getline(fin, s);
    assert(s == "Users");

    // get the number of user
    getline(fin, s);
    int userNumber;
    getStringAndNum(s, userNumber);
    assert(s == "Number");
   
    // get the info 
    for(int i = 0; i < userNumber; ++i){
        string userTitle;
        string userID;
        string passWordTitle;
        string passWord;
        int borrowNum;
        User* tmpuser = new User();

        getline(fin, s);
        ss << s;
        ss >> userTitle;
        ss >> userID;
        assert(userTitle == "UserID");

        ss.str("");
        ss.clear();

        getline(fin, s);
        ss << s;
        ss >> passWordTitle;
        ss >> passWord;
        assert(passWordTitle == "Password");

        ss.str("");
        ss.clear();
        
        tmpuser->setID(userID);
        tmpuser->setPass(passWord);

        getline(fin, s);
        getStringAndNum(s, borrowNum);
        assert(s == "BorrowNumber");

        for(int i = 0; i < borrowNum; ++i){
            string objectName;
            string objectID;
            getline(fin, objectName);
            getStringAndString(objectName, objectID);
            map<string, object*>::iterator iter = _objectByID.find(objectID);
            object* tmpobj = iter->second;
            tmpobj->borrow(tmpuser);
            tmpuser->addBorrow(tmpobj);
        }

        _users.insert(pair<string, User*>(userID, tmpuser));

        getline(fin, s);
    }

    fin.close();


}


bool
infoMgr::setIDandPassword(string userID, string Password){
    map<string, User*>::iterator iter;
    iter = _users.find(userID);
    if(iter != _users.end()) return false;
    User* tmpuser = new User();
    tmpuser -> setID(userID);
    tmpuser -> setPass(Password);
    _users.insert(pair<string, User*>(userID, tmpuser));
    return true;
}


bool
infoMgr::login(string userID, string Password){
    map<string, User*>::iterator iter;
    iter = _users.find(userID);
    if(iter == _users.end()) return false;
    User* tmpuser = iter->second;
    if(!tmpuser->checkPassWord(Password)) return false;
    _currentUser = tmpuser;
    return true;
}

bool
infoMgr::logout(){
    if(!_currentUser) return false;
    _currentUser = 0;
    return true;
}

bool
infoMgr::borrowByID(string id){
    if(!_currentUser) return false;
    map<string, object*>::iterator iter;
    iter = _objectByID.find(id);
    if(iter == _objectByID.end()) return false;
    object* tmpobj = iter->second;
    if(!tmpobj->isAvailable()) return false;
    _currentUser->addBorrow(tmpobj);
    tmpobj->borrow(_currentUser);
    return true;
}

bool
infoMgr::borrowByName(string objName){
    if(!_currentUser) return false;
    map<string, vector<object*> >::iterator iter;
    iter = _objectByName.find(objName);
    vector<object*> tmpobjs = iter->second;
    object* tmpobj ;
    for(int i = 0; i < tmpobjs.size(); ++i){
        if(tmpobjs[i]->isAvailable()){
            tmpobj = tmpobjs[i];
            _currentUser->addBorrow(tmpobj);
            tmpobj->borrow(_currentUser);
            return true;
        }
    }
    return false;
}

bool
infoMgr::returnByID(string id){
    if(!_currentUser) return false;
    object* tmpobj = _currentUser->returnObjectByID(id);
    if(!tmpobj) return false;
    tmpobj->objectFree();
    return true;
}

bool
infoMgr::returnByName(string objName){
    if(!_currentUser) return false;
    object* tmpobj = _currentUser->returnObjectByName(objName);
    if(!tmpobj) return false;
    tmpobj->objectFree();
    return true;
}
