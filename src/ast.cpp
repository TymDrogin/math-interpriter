#include "ast.hpp"

/* Constructors */

//TODO: Rewrite constructor and parse identifier to support Const
NumberNode::NumberNode(const Token &token)
        : _value(std::stod(token.getLexeme())), _token(token), _type(NumberNodeType::Dec) {}

UnaryOpNode::UnaryOpNode(const Token &token, std::unique_ptr<ASTNode> operand)
        : _token(token), _operand(std::move(operand))  {
    //TODO: ABS 
    switch (_token.getType()) {
        case TokenType::Plus: _type  = UnaryOpNodeType::Pos; break;
        case TokenType::Minus: _type = UnaryOpNodeType::Neg; break;
        default:
            throw std::invalid_argument("Token is not for Unary Operation");
    }
}
BinaryOpNode::BinaryOpNode(const Token &token, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : _token(token), _left(std::move(left)), _right(std::move(right)) {

    switch (_token.getType()) {
        case TokenType::Plus:  _type = BinaryOpNodeType::Add; break;
        case TokenType::Minus: _type = BinaryOpNodeType::Sub; break;
        case TokenType::Star:  _type = BinaryOpNodeType::Mul; break;
        case TokenType::Slash: _type = BinaryOpNodeType::Div; break;
        case TokenType::Caret: _type = BinaryOpNodeType::Pow; break;
        default:
            throw std::invalid_argument("Token is not for Binary Operation");
    }
}

/* Public*/
double NumberNode::evaluate() {
    return _value;
}
double UnaryOpNode::evaluate() {
/* Destructors */
    switch (_type) {
    case UnaryOpNodeType::Pos:
        return _operand->evaluate();
    case UnaryOpNodeType::Neg:
        return -_operand->evaluate();
    }
}
double BinaryOpNode::evaluate() {
    switch (_type) {
    case BinaryOpNodeType::Add:
        return _left->evaluate() + _right->evaluate();
    case BinaryOpNodeType::Sub:
        return _left->evaluate() - _right->evaluate();
    case BinaryOpNodeType::Mul:
        return _left->evaluate() * _right->evaluate();
    case BinaryOpNodeType::Div: {
        double result = _left->evaluate() / _right->evaluate();
        if (std::isinf(result)) { throw std::runtime_error("Math error: Attempted to divide by Zero\n");}
        return result;
    }
    case BinaryOpNodeType::Pow:
        return pow(_left->evaluate(), _right->evaluate());
    }
}
/* Private */