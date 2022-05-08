//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Class to parse variables from input stream
#include <cctype> 
#include <iostream> 
#include <string> 
#include <sstream>
using namespace std;

#include "parse.h"

string parseName(stringstream &s)
{
    char alnum;
    string name = "";

    s >> ws;
    while (isalnum(s.peek()))
    {
        s >> alnum;
        name += alnum;
    }
    return name;
}