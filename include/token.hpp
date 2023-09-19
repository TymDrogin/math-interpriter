#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <vector>

enum class TokenType {
	Error, EoF,
	Ident,

	Number,
	Plus, Minus,
	Star, Slash,
	Caret,
	OpenParenthesis, CloseParenthesis,
	Comma,

	TokenType_MAX,
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