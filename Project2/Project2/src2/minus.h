//CMSC 330 Section 7381 Project 2
//Basis was taken from Module 3 "An Expression Interpreter"
//Modified by Patric Centorbi on May 10, 2022
//Defines the class used to process subtraction operations. Based on the provided "Plus" class.
class Minus : public SubExpression
{
public:
	Minus(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() - right->evaluate();
	}
};