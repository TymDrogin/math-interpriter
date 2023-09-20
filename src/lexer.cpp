#include "lexer.hpp"

/*Constructor*/
Lexer::Lexer(std::string& input) : _input(input), _position(0) {};

/*Public*/
std::vector<Token> Lexer::tokenize() {
	std::vector<Token> tokens;
	Token token = nextToken();

	while (token.getType() != TokenType::EoF) {
		tokens.push_back(token);
		token = nextToken();
	}

	tokens.push_back(token); //push EoF token 
	setPosition(0); //reset position to allow multiple tokenize() calls
	return tokens;
};

/*Private*/
void Lexer::advance() {
	_position++;
}
void Lexer::skipWhitespace() {
	while (_position < _input.length() && isspace(_input[_position])) {
		advance();
	}
}
char Lexer::getCurrentChar() const {
	return _input[_position];
};
void Lexer::setPosition(int p) {_position = p;}

Token Lexer::nextToken() {
	skipWhitespace();
	char c = getCurrentChar();

	if (c == '\0') {
		return Token(TokenType::EoF, "EOF"); // Return an EoF token
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
			return parseStar();
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
				return parseIdentifier();
			}
	}
	return parseError();
}
Token Lexer::parseStar() {
	/*To support both^ and **notation for the pow we need to check
	if we have two stars in a row. If they are then we return a caret token*/
	if (getCurrentChar() != '*') {
		return Token(TokenType::Star, "*");
	}
	else {
		advance();
		return Token(TokenType::Caret, "^");
	}
}
Token Lexer::parseNumber() {
	std::string lexeme;

	auto readWhileIsDigit = [&]() {
		while (isdigit(getCurrentChar())) {
			lexeme += getCurrentChar();
			advance();
		}
	};

	// Read integer part
	readWhileIsDigit();

	// Check for a decimal point
	if (getCurrentChar() == '.') {
		lexeme += getCurrentChar();
		advance();

		// Read decimal part
		readWhileIsDigit();
	}
	// Scientyfic notation part: 12.4(e10), e-2, etc
	if (getCurrentChar() == 'e'|| getCurrentChar() == 'E') {
		lexeme += getCurrentChar();
		advance();

		// Read sign
		if (getCurrentChar() == '-' || getCurrentChar() == '+') {
			lexeme += getCurrentChar();
			advance();
		}
		// Read exponent 
		readWhileIsDigit();
	}
	Token token(TokenType::Number, lexeme);
	return token;
}
Token Lexer::parseIdentifier() {
	std::string lexeme;

	while (isalpha(getCurrentChar()) || isdigit(getCurrentChar())) {
		lexeme += getCurrentChar();
		advance();
		//if lexeme is in constants return Token constant with value 
	}

	Token token(TokenType::Ident, lexeme);
	return token;
}
Token Lexer::parseError() {
	Token error(TokenType::Error, std::string(1, getCurrentChar()));
	advance();
	return error;
}