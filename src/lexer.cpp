#include "lexer.hpp"

/*Constructor*/
Lexer::Lexer(const std::string& input) : input_(input), position_(0) {};

/*Public*/
std::vector<Token> Lexer::tokenize() {
	std::vector<Token> tokens;
	Token token = nextToken();

	while (token.getType() != TokenType::EoF) {
		tokens.push_back(token);
		token = nextToken();
	}

	setPosition(0); //set pos to 0 allows to call tokenize() more then once
	return tokens;
};

int Lexer::getPosition() const {	
	return position_;
}
std::string Lexer::getInput() const {	
	return input_;
}
char Lexer::getCurrentChar() const {
	return input_[position_];
};

/*Private*/
void Lexer::advance() {	position_++;}
void Lexer::skipWhitespace() {
	while (position_ < input_.length() && isspace(input_[position_])) {
		advance();
	}
}
void Lexer::setPosition(int p) {position_ = p;}

//Token Lexer::nextToken() {

//}
Token Lexer::parseNumber() {
	std::string lexeme;

	// Read integer part
	while (isdigit(getCurrentChar())) {
		lexeme += getCurrentChar();
		advance();
	}

	// Check for a decimal point
	if (getCurrentChar() == '.') {
		lexeme += getCurrentChar();
		advance();

		// Read decimal part
		while (isdigit(getCurrentChar())) {
			lexeme += getCurrentChar();
			advance();
		}
	}

	Token token(TokenType::Number, lexeme);
	return token;
}
Token Lexer::parseIdentyfier() {
	std::string lexeme;

	while (isalpha(getCurrentChar()) || isdigit(getCurrentChar())) {
		lexeme += getCurrentChar();
		advance();
	}
	Token token(TokenType::Ident, lexeme);
	return token;
}