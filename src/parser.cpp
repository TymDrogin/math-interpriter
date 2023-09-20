#include "parser.hpp"
/* Constructor */
Parser::Parser(std::vector<Token>& tokens) : _tokens(tokens), _current(0) {};

/* Public*/
std::unique_ptr<ASTNode> Parser::toAST() {
	//filterErrorTokens();
	//isValidTokenSequence();
	std::unique_ptr<ASTNode> result = expression();

	if (peek().getType() != TokenType::EoF) {
		throw std::runtime_error("Invalid expression, can't evaluate");
	}
    setCurrent(0);
	return result;
}
std::vector<Token> Parser::toRPN() {
	//filterErrorTokens();
	//isValidTokenSequence();

	std::vector<Token> outputQueue;
	std::stack<Token> operatorStack;

	for (const auto& t : _tokens) {
		if (t.getType() == TokenType::Number) {
			outputQueue.push_back(t);
		}
		else {
			operatorStack.push(t);
		}
	}
	return outputQueue;
}

/* Private */
void Parser::advance() { _current++;}
Token Parser::peek(){return _tokens[_current];}
Token Parser::previous() {
	if (_current - 1 != 0) {
		return _tokens[_current - 1];
	} else {
		throw std::invalid_argument("Trying to peek token on the index less then 0");
	}
}
void Parser::setCurrent(int current) {
    _current = current;
}
bool Parser::match(TokenType type) {
    if (peek().getType() == TokenType::EoF) {
        return false;
    }
    else {
        return peek().getType() == type;
    }
}

std::unique_ptr<ASTNode> Parser::expression() {
	std::unique_ptr<ASTNode> left = term();

	while (match(TokenType::Plus) || match(TokenType::Minus)) {
		Token oper = peek(); //get the operator token
		advance(); //get to the next token
		std::unique_ptr<ASTNode> right = term(); //parse right side 
		left = std::make_unique<BinaryOpNode>(oper, std::move(left), std::move(right));
	}
	return left;
}
std::unique_ptr<ASTNode> Parser::term() {
	std::unique_ptr<ASTNode> left = factor();

	while (match(TokenType::Star) || match(TokenType::Slash)) {
		Token oper = peek(); //get the operator token
		advance(); //get to the next token
		std::unique_ptr<ASTNode> right = factor(); //parse right side 
		left = std::make_unique<BinaryOpNode>(oper, std::move(left), std::move(right));
	}
	return left;	
}
std::unique_ptr<ASTNode> Parser::factor() {
	Token current_token = peek();

    // if current node is terminal(number) return
	if (match(TokenType::Number)) {
		advance();
		return std::make_unique<NumberNode>(current_token);

    // else if LPAREN recursively parse expression
	} else if(match(TokenType::OpenParenthesis)) {
        advance();
        std::unique_ptr<ASTNode> innerExpression = expression();
        //if no closing parenthesis rise an error
        if (!match(TokenType::CloseParenthesis)) {
            throw std::runtime_error("Expected ')' after expression.");
        }
        advance();
        return innerExpression;
    }
	throw std::invalid_argument("Can't factor");
}


//bool Parser::isValidTokenSequence()
//{
//	return false;
//}
//void Parser::filterErrorTokens(){
//	// Iterate through the tokens and remove any tokens that are considered errors
//	auto it = std::remove_if(_tokens.begin(), _tokens.end(), [](const Token& token) {
//		return token.getType() == TokenType::Error;
//		});
//
//	// Erase the removed tokens
//	_tokens.erase(it, _tokens.end());
//}