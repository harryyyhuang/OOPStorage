/**********************************************************
 *  FileName    [ util.cpp ]
 *  PackageName [ manager ]
 *  Synopsis    [ extern utility function ]
 *  Author      [ Harry Huang ]
***********************************************************/


#include "util.h"
#include <sstream>
#include <string>

using namespace std;

//----------------------------------------------------------
//  Global util functions
//----------------------------------------------------------


int getNum(string s){
    int number;
    stringstream ss;
    ss << s;
    ss >> number;
    return number;
}

void getStringAndNum(string& s, int& number){
    stringstream ss;
    ss << s;
    ss >> s;
    ss >> number;
}


string getString(string s){
    stringstream ss;
    ss << s;
    ss >> s;
    return s;
}

void getStringAndString(string& s1, string& s2){
    stringstream ss;
    ss << s1;
    ss >> s1;
    ss >> s2;
}