//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Defines the SubExpression object. Contains overloaded constructors to support 3 operand equations.
class SubExpression : public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    
    //Definition for overridden constructor to support 3 operands
    SubExpression(Expression* left, Expression* right, Expression* condition);
    static Expression* parse();
protected:
    Expression* left;
    Expression* right;
    Expression* condition; //Expression pointer for 3rd operand
};