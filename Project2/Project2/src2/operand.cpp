//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter" class
//Modified by Patric Centorbi on May 10, 2022
//Class that implements operand objects
#include <cctype>
#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse()
{
    char paren;
    int value;

    cin >> ws;
    if (isdigit(cin.peek()))
    {
        cin >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (cin.peek() == '(')
    {
        cin >> paren;
        return SubExpression::parse();
    }
    else
        return new Variable(parseName());
    return 0;
}