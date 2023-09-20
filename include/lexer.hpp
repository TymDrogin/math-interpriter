#pragma once

#include "token.hpp"

#include <vector>
#include <cctype>
#include <memory>


// TODO: Lexing can be done with regex 
class Lexer {
public:
	Lexer(std::string& input);
	std::vector<Token> tokenize();

private:
	std::string _input; // input string in format "2+3*(4-2)"; // input string in format "2+3*(4-2)"
	int _position; //current lexing position

	void advance(); //increment position by 1
	void skipWhitespace();
	char getCurrentChar() const;
	void setPosition(int p);

	Token nextToken(); 
	Token parseStar();

	Token parseNumber();

	//TODO: add support For pi, e, g, and other constants 
	//TODO: add parsing of a functions like sin cos etc
	Token parseIdentyfier();
	Token parseError();
};

//class RegexLexer {

//};