#include "main.hpp"


int main()
{
	std::string input = "2 + 4*(5 - 3.5)";

	Lexer myLexer(input);

	std::vector<Token> tokens = myLexer.tokenize();

	printTokens(tokens);


}