#include "parser.hpp"
/* Constructor */
Parser::Parser(std::vector<Token>& tokens) : _tokens(tokens), _position(0) {};

/* Public*/

std::unique_ptr<ASTNode> Parser::toAST(std::vector<Token> tokens) {
	return std::unique_ptr<ASTNode>();
}
std::vector<Token> Parser::toRPN(std::vector<Token> tokens) {
	filterErrorTokens();
	isValidTokenSequence();
	
	std::vector<Token> outputQueue;
	std::stack<Token> operatorStack;
	
	for (auto t : tokens) {
		if (t.getType() == TokenType::Number) {
			outputQueue.push_back(t);
		}
		else {
			operatorStack.push(t);
		}
	}

}

void Parser::setTokensToParse(std::vector<Token> tokens) { _tokens = tokens; _position = 0;};


/* Privat*/

bool Parser::isValidTokenSequence()
{
	return false;
}
void Parser::filterErrorTokens(){
	// Iterate through the tokens and remove any tokens that are considered errors
	auto it = std::remove_if(_tokens.begin(), _tokens.end(), [](const Token& token) {
		return token.getType() == TokenType::Error;
		});

	// Erase the removed tokens
	_tokens.erase(it, _tokens.end());
}