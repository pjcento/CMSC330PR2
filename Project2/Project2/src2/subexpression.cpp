#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greater.h"
#include "less.h"
#include "equals.h"
#include "and.h"
#include "or.h"
#include "not.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse()
{
    Expression* left;
    Expression* right;
    char operation, paren;

    left = Operand::parse();
    cin >> operation;
    right = Operand::parse();
    cin >> paren;
    switch (operation)
    {
    case '+':
        return new Plus(left, right);
    case '-':
        return new Minus(left, right);
    case '*':
        return new Times(left, right);
    case '/':
        return new Divide(left, right);
    case '>':
        return new Greater(left, right); //Added support for greater than operator
    case '<':
        return new Less(left, right); //Added support for less than operator
    case '=':
        return new Equals(left, right); //Added support for equality operator
    case '&':
        return new And(left, right); //Added support for and operator
    case '|':
        return new Or(left, right); //Added support for or operator
    case '!':
        return new Not(left, right); //Added support for logical not operator
    }
    return 0;
}