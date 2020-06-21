#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include <iostream>
#include <fstream>
#include <string>

#include "cmdCharDef.h"

using namespace std;

//-------------------------------------
//  Forward Declaration
//-------------------------------------

class CmdExec;
class CmdParser;

//-------------------------------------
//  External declaration
//-------------------------------------
extern CmdParser* cmdMgr;

//-------------------------------------
// command execution status
//-------------------------------------
