#include "ast.hpp"

/* Constructors */

//TODO: Rewrite constructor to support Const
NumberNode::NumberNode(const Token& token)
        : _value(std::stod(token.getLexeme())), _token(token), _type(NumberNodeType::Dec) {}

UnaryOperationNode::UnaryOperationNode(const Token& token, std::unique_ptr<ASTNode> operand)
        : _operand(std::move(operand)), _token(token) {
    //TODO: ABS 
    switch (_token.getType()) {
        case TokenType::Plus: _type  = UnaryOperatorNodeType::Pos; break;
        case TokenType::Minus: _type = UnaryOperatorNodeType::Pos; break;
        default:
            throw std::invalid_argument("Token is not for Unary Operation");

    }
}

BinaryOperationNode::BinaryOperationNode(const Token& token, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : _token(token), _left(std::move(left)), _right(std::move(right)) {

    switch (_token.getType()) {
        case TokenType::Plus: _type  = BinaryOperatorNodeType::Add; break;
        case TokenType::Minus: _type = BinaryOperatorNodeType::Sub; break;
        case TokenType::Star: _type  = BinaryOperatorNodeType::Mul; break;
        case TokenType::Slash: _type = BinaryOperatorNodeType::Div; break;
        case TokenType::Caret: _type = BinaryOperatorNodeType::Pow; break;
        default:
            throw std::invalid_argument("Token is not for Binary Operation");
            break;
    }
}

/* Destructors */
/* Public*/
double NumberNode::evaluate()
{
    return _value;
}
double UnaryOperationNode::evaluate()
{
    switch (_type) {
    case UnaryOperatorNodeType::Pos:
        return _operand->evaluate();
        break;
    case UnaryOperatorNodeType::Neg:
        return -_operand->evaluate();
        break;
    }
}
double BinaryOperationNode::evaluate()
{
    switch (_type) {
    case BinaryOperatorNodeType::Add:
        return _left->evaluate() + _right->evaluate();
        break;
    case BinaryOperatorNodeType::Sub:
        return _left->evaluate() - _right->evaluate();
        break;
    case BinaryOperatorNodeType::Mul:
        return _left->evaluate() * _right->evaluate();
        break;
    case BinaryOperatorNodeType::Div:
    //TODO: add rxception processing 
        return _left->evaluate() / _right->evaluate();
        break;
    case BinaryOperatorNodeType::Pow:
        return pow(_left->evaluate(), _right->evaluate());
        break;
    }
}


/* Private */