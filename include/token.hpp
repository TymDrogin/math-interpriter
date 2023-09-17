#pragma once

#include <string>
#include <iostream>
#include <cctype>

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

class Token
{
public:
	Token(TokenType t, const std::string& l);

	void print() const;

	TokenType getType() const;
	std::string getLexeme() const;

	static std::string tokenTypeToString(TokenType t);

private:
	TokenType type_;
	std::string lexeme_;
};