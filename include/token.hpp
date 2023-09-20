#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <map>

enum class TokenType {
	Error, EoF,
	Ident,

	Number, Constant,
	Plus, Minus,
	Star, Slash,
	Caret,
	OpenParenthesis, CloseParenthesis,

	Comma,
};

// For the logic go to Lexer::parseIdentyfier() or NumberNode
const std::map<std::string, double> constants = {
	   {"pi", 3.14159265359},
	   {"e", 2.71828182846},
	   {"phi", 1.61803398875}, // Golden Ratio
	   {"G", 6.67430e-11}       // Gravitational constant (m^3/kg/s^2)
};

class Token {
public:
	Token(TokenType t, const std::string& l);

	void print() const;

	TokenType getType() const;
	std::string getLexeme() const;

	static std::string tokenTypeToString(TokenType t);

private:
	TokenType _type;
	std::string _lexeme;
};

void printTokens(std::vector<Token> tokens);