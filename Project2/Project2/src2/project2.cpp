//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Contains main class and function to parse variable assignments
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments();

int main()
{
    Expression* expression;
    char paren, comma;
    cout << "Enter expression: ";
    cin >> paren;
    expression = SubExpression::parse();
    cin >> comma;
    parseAssignments();
    cout << "Value = " << expression->evaluate() << endl;
    return 0;
}

void parseAssignments()
{
    char assignop, delimiter;
    string variable;
    int value;
    do
    {
        variable = parseName();
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    } while (delimiter == ',');
}