#include "token.hpp"

/*Constructor*/
Token::Token(TokenType t, const std::string& l) : type_(t), lexeme_(l) {};

/*Public*/
void Token::print() const{
    std::cout << "Type: " << tokenTypeToString(type_);
    std::cout << ", Value: " << lexeme_ << std::endl;
}
TokenType Token::getType() const {return type_;}
std::string Token::getLexeme() const {return lexeme_;}
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

/*Functions*/
void printTokens(std::vector<Token> tokens) {
    for (Token t : tokens) {
        t.print();
    }
}