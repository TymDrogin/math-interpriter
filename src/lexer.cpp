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

	tokens.push_back(token); //push Eof token 
	setPosition(0); //reset position to allow multiple tokenize() calls
	return tokens;
};

/*Private*/
void Lexer::advance() {
	position_++;
}
void Lexer::skipWhitespace() {
	while (position_ < input_.length() && isspace(input_[position_])) {
		advance();
	}
}

void Lexer::setPosition(int p) {position_ = p;}
char Lexer::getCurrentChar() const {
	return input_[position_];
};

Token Lexer::nextToken() {
	skipWhitespace();
	char c = getCurrentChar();

	if (c == '\0') {
		return Token(TokenType::EoF, "\0"); // Return an EoF token
	}

	switch(c) {
		case '+':
			advance();
			return Token(TokenType::Plus, "+");
		case '-':
			advance();
			return Token(TokenType::Minus, "-");
		case '*':
			advance();
			return Token(TokenType::Star, "*");
		case '/':
			advance();
			return Token(TokenType::Slash, "/");
		case '^':
			advance();
			return Token(TokenType::Caret, "^");
		case '(':
			advance();
			return Token(TokenType::OpenParenthesis, "(");
		case ')':
			advance();
			return Token(TokenType::CloseParenthesis, ")");
		default:
			if (isdigit(c)) {
				return parseNumber();
			}
			else if (isalpha(c)) {
				return parseIdentyfier();
			}
	}
	return Token(TokenType::Error, "Unexpected character");
}
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