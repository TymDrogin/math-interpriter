#pragma once

#include <vector>
#include "token.hpp"

class Lexer
{
public:
	Lexer(const std::string& input);

	std::vector<Token> tokenize();

	int getPosition() const;
	std::string getInput() const;


private:

	const std::string& input_; // input string in format "2+3*(4-2)"
	int position_; //current lexing position

	void advance(); //increment position by 1
	void skipWhitespace();



	Token nextToken(); //gets next token 
	Token parseNumber();
	Token parseIdentyfier();
	
};

