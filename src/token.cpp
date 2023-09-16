#include "token.hpp"

Token::Token(TokenType t, const std::string& l) : type(t), lexeme(l) {};

void Token::print() const{
    std::cout << "Token Type: " << tokenTypeToString(type) << std::endl;
    std::cout << "Lexeme: " << lexeme << std::endl;
}

void Token::setType(TokenType t) {
	this->type = t;
}
void Token::setLexeme(const std::string& l) {
	this->lexeme = l;
}

TokenType Token::getType() {
	return this->type;
}
std::string Token::getLexeme() {
	return this->lexeme;
}

std::string Token::tokenTypeToString(TokenType t) {
    switch (t) {
        case TokenType::Error: return "Error";
        case TokenType::EoF: return "End of File";
        case TokenType::Ident: return "Identifier";
        case TokenType::Number: return "Number";
        case TokenType::Plus: return "Plus";
        case TokenType::Minus: return "Minus";
        case TokenType::Star: return "Star";
        case TokenType::Slash: return "Slash";
        case TokenType::Caret: return "Caret";
        case TokenType::OpenParenthesis: return "Open Parenthesis";
        case TokenType::CloseParenthesis: return "Close Parenthesis";
        case TokenType::Comma: return "Comma";
        default: return "Unknown";
    }
}
