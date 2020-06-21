/*****************************************
 *  FileName    [ object.h ]
 *  PackageName [ manager ]
 *  Synopsis    [ Define the object class ]
 *  Author      [ Harry Huang ]
*****************************************/

#ifndef OBJECT_H
#define OBJECT_H


#include <string>
#include <vector>


using namespace std;


class object;
class User;

class object{
public:
    object(){}

    void setName(string objectName){ _objectName = objectName; }
    void setID(string objectID){ _objectId = objectID; }

    void borrow(User* borrower){ _borrower = borrower; }
    bool isAvailable();
    string getObjectID(){ return _objectId; }
    string getObjectName(){ return _objectName; }
    void objectFree(){ _borrower = 0; }

    

private:
    string _objectName;
    string _objectId;
    User*  _borrower;
};

#endif