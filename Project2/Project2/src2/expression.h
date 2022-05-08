//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 8, 2022.
//Abstract class that defines Expressions, inherited by SubExpression. Has not been modified from provided example.
class Expression
{
public:
    virtual int evaluate() = 0;
};