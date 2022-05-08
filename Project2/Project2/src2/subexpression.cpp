//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Implements the SubExpression object. Added function overload to support 3 operand equations
//Also added additional classes for support for required operations
#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"

//Additional includes for added classes
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greater.h"
#include "less.h"
#include "equals.h"
#include "and.h"
#include "or.h"
#include "not.h"
#include "conditional.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

//Implementation of overridden constrructor to support 3 operands
SubExpression::SubExpression(Expression* left, Expression* right, Expression* condition)
{
    this->left = left;
    this->right = right;
    this->condition = condition;
}

Expression* SubExpression::parse(stringstream &s)
{
    Expression* left;
    Expression* right;

    //3rd Expression pointer to suipport ternary operator equations
    Expression* condition;
    char operation, op2, paren;

    left = Operand::parse(s);
    s >> operation;
    right = Operand::parse(s);
    
    //Moved assignment to paren into cases so that 3rd operand can be supported

    switch (operation)
    {
    case '+':
        s >> paren;
        return new Plus(left, right);
    case '-':
        s >> paren;
        return new Minus(left, right);
    case '*':
        s >> paren;
        return new Times(left, right);
    case '/':
        s >> paren;
        return new Divide(left, right);
    case '>':
        s >> paren;
        return new Greater(left, right); //Added support for greater than operator
    case '<':
        s >> paren;
        return new Less(left, right); //Added support for less than operator
    case '=':
        s >> paren;
        return new Equals(left, right); //Added support for equality operator
    case '&':
        s >> paren;
        return new And(left, right); //Added support for and operator
    case '|':
        s >> paren;
        return new Or(left, right); //Added support for or operator
    case '!':
        s >> paren;
        return new Not(left, right); //Added support for logical not operator
    case ':':
        s >> op2; //Get our second operator from input stream
        condition = Operand::parse(s); //Parse 3rd operand
        s >> paren;
        return new Conditional(left, right, condition); //Added support for conditional ternary operation
    }
    return 0;
}