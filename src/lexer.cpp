#include "lexer.hpp"

Lexer::Lexer(const std::string& input) : input_(input), position_(0) {};

//std::vector<Token> Lexer::tokenize() {
	//TODO;
//};

int Lexer::getPosition() const {return position_;}
std::string Lexer::getInput() const {return input_;}

void Lexer::advance() {
	position_++;
}
void Lexer::skipWhitespace() {
	while (position_ < input_.length() && isspace(input_[position_])) {
		advance();
	}
}

//Token Lexer::nextToken() {

//}
//Token Lexer::parseNumber() {

//}
//Token Lexer::parseIdentyfier() {

//}
