//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 8, 2022.
//Contains main class and function to parse variable assignments
//Modified all instances of cin from project to be stringstream, passing as reference to outside classes.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream &s);

int main()
{
    Expression* expression;
    char paren, comma;
    string fname = "", line = "";              //Strings to hold filename and lines from file
    cout << "Enter path to file: ";            //Prompt user to enter path to file
    cin >> fname;                              //Put filename into string
    ifstream infile(fname);                    //Open file
    cout << "\nOpened file " << fname << endl; //Give user feedback of successful file open
    while (getline(infile, line))              //While there are lines in the file
    {
        stringstream expr(line);
        expr >> paren;
        expression = SubExpression::parse(expr);
        expr >> comma;
        parseAssignments(expr);
        cout << "Expression: " << line << "\nValue = " << expression->evaluate() << endl;
        symbolTable.clear();
    }
    infile.close();
    return 0;
}

void parseAssignments(stringstream &s)
{
    char assignop, delimiter;
    string variable;
    int value;
    do
    {
        variable = parseName(s);
        s >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    } while (delimiter == ',');
}