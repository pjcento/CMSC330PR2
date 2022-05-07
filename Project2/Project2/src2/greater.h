//Based off supplied Plus class, evaluates for greater than operator
class Greater : public SubExpression
{
public:
    Greater(Expression* left, Expression* right) :
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return left->evaluate() > right->evaluate();
    }
};