#include "main.hpp"


int main()
{
	TokenType type = TokenType::Number; // Replace with the appropriate TokenType
	std::string lexeme = "123"; // Replace with the lexeme you want

	Token token(type, lexeme);
	
	std::cout << "Token class size in bytes: " << sizeof(Token) << std::endl;
	std::cout << "Token size in bytes: " << sizeof(token) << std::endl;


}