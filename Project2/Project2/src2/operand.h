//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Defines the Operand subclass of Expression. Has not been modified from original provided.
class Operand : public Expression
{
public:
    static Expression* parse();
};