//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Defines the variable class
class Variable : public Operand
{
public:
    Variable(string name)
    {
        this->name = name;
    }
    int evaluate();
private:
    string name;
};