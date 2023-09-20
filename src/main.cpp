#include "main.hpp"


int main()
{
	std::string input = "2+3*4-1";

	Lexer myLexer(input);

	auto tokens = myLexer.tokenize();
	printTokens(tokens);

	Parser myParser(tokens);

	auto tree = myParser.toAST();
	
	double result = tree->evaluate();
	
	std::cout << result;

}