#include "ast.hpp"

/* Constructors */

//TODO: Can be added support for complex numbers
NumberNode::NumberNode(const Token& token) : _token(token), _type(NumberNodeType::Dec) {
    if (token.getType() != TokenType::Number) {
        throw std::invalid_argument("Token is not of type Number");
    }

    try {
        // Convert the lexeme from the Token to a double
        _value = std::stod(token.getLexeme());
    }
    catch (const std::invalid_argument& e) {
        // Handle conversion error, e.g., if the lexeme is not a valid number
        throw std::invalid_argument("Invalid number format in token");
    }
}
UnaryOperationNode::UnaryOperationNode(const Token& token, ASTNode* operand) : _operand(std::move(operand)), _token(token) {
    //TODO: ABS 
    switch (_token.getType()) {
        case TokenType::Plus: _type = UnaryOperatorNodeType::Pos;
        case TokenType::Minus: _type = UnaryOperatorNodeType::Pos;
        default:
            throw std::invalid_argument("Token is not for Unary Operation");

    }
}
BinaryOperationNode::BinaryOperationNode(const Token& token, ASTNode* left, ASTNode* right) 
        : _token(token), _left(std::move(left)), _right(std::move(right)) {

    switch (_token.getType()) {
        case TokenType::Plus: _type = BinaryOperatorNodeType::Add;
        case TokenType::Minus: _type = BinaryOperatorNodeType::Sub;
        case TokenType::Star: _type = BinaryOperatorNodeType::Mul;
        case TokenType::Slash: _type = BinaryOperatorNodeType::Div;
        case TokenType::Caret: _type = BinaryOperatorNodeType::Pow;
        default:
            throw std::invalid_argument("Token is not for Binary Operation");
    }
};

/* Destructors */
/* Public*/
/* Private */