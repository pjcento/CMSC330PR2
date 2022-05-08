//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter" class
//Modified by Patric Centorbi on May 10, 2022
//Class that implements operand objects
#include <cctype>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream& s)
{
    char paren;
    int value;

    s >> ws;
    if (isdigit(s.peek()))
    {
        s >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (s.peek() == '(')
    {
        s >> paren;
        return SubExpression::parse(s);
    }
    else
        return new Variable(parseName(s));
    return 0;
}