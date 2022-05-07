//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Defines the class used to process addition operations. Has not been modified from provided example.
class Plus : public SubExpression
{
public:
    Plus(Expression* left, Expression* right) :
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return left->evaluate() + right->evaluate();
    }
};