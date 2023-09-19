#pragma once

#include "token.hpp"

#include <vector>
#include <cctype>
#include <memory>

class Lexer {
public:
	Lexer(std::string& input);
	std::vector<Token> tokenize();

	void setInput(const std::string& input); //sets new string to tokenize

private:
	std::string input_; // input string in format "2+3*(4-2)"; // input string in format "2+3*(4-2)"
	int position_; //current lexing position

	void advance(); //increment position by 1
	void skipWhitespace();
	char getCurrentChar() const;
	void setPosition(int p);

	Token nextToken(); 
	Token parseStar();
	Token parseNumber();
	Token parseIdentyfier();
	Token parseError();
};