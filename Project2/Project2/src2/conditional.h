//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 8, 2022.
//Defines the class used to process ternary operator operations. Based on the provided "Plus" class.
//Uses overriden constructors from SubExpression to create expression with 3 operands. 
class Conditional : public SubExpression
{
public:
    Conditional(Expression* left, Expression* right, Expression* condition) :
        SubExpression(left, right, condition)
    {
    }
    int evaluate()
    {
        return condition->evaluate() ? left->evaluate() : right->evaluate();
    }
};