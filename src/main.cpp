#include "main.hpp"


int main()
{
	std::string input = "2+3-(4+7) * 4";

	Lexer myLexer(input);

	std::vector<Token> tokens = myLexer.tokenize();
	


	printTokens(tokens);


}