#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments();
string removeSpaces(string s);

int main()
{
    Expression* expression;
    char paren, comma;
    string line; //needed for file read
    //cout << "Enter expression: ";
    
    //Adding file open line
    ifstream myfile("C:\\Users\\pjcen\\OneDrive\\Documents\\VS2022 Workspace\\testFile.txt");
    cout << "Opened file: C:\\Users\\pjcen\\OneDrive\\Documents\\VS2022 Workspace\\testFile.txt" << endl;
    while (getline(myfile, line))
    {
        line = removeSpaces(line);
        if (line[0] == '(')
        {
            line[0] >> paren;
            line.erase(0, 1);
            expression = SubExpression::parse();
            //cout << line << endl;
        }
    }
    
    //cin >> paren;
    expression = SubExpression::parse();
    cin >> comma;
    parseAssignments();
    cout << "Value = " << expression->evaluate() << endl;
    return 0;
}

void parseAssignments()
{
    char assignop, delimiter;
    string variable;
    int value;
    do
    {
        variable = parseName();
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    } while (delimiter == ',');
}

string removeSpaces(string s)
{
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    return s;
}