//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Defines the SymbolTable object that stores variable assignments
class SymbolTable
{
public:
    SymbolTable() {}
    void insert(string variable, int value);
    int lookUp(string variable) const;
private:
    struct Symbol
    {
        Symbol(string variable, int value)
        {
            this->variable = variable;
            this->value = value;
        }
        string variable;
        int value;
    };
    vector <Symbol> elements;
};