/*****************************************
 *  FileName    [ user.h ]
 *  PackageName [ manager ]
 *  Synopsis    [ Define the user class ]
 *  Author      [ Harry Huang ]
*****************************************/

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>



using namespace std;

class User;
class object;

//-----------------------------------------
//  Define classes
//-----------------------------------------
class User
{
public:
    User(){}
    void setID(string userID){ _userID = userID; }
    void setPass(string passWord){ _passWord = passWord; }
    void addBorrow(object* tmpobject){ _borrowing.push_back(tmpobject) ;}
    bool checkPassWord(string Password);
    object* returnObjectByID(string id);
    object* returnObjectByName(string objName);
    string getUserID(){ return _userID; }
    string getUserPassWord(){ return _passWord; }
    vector<object*> getBorrowing(){ return _borrowing; }



private:
    string _userID;
    string _passWord;
    vector<object *> _borrowing;
};


#endif