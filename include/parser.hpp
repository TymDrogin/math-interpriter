#pragma once

#include "token.hpp"
#include "lexer.hpp"
#include "ast.hpp"

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>

//TODO: Error processing
class Parser {
public:
    explicit Parser(std::vector<Token>& tokens);

    std::unique_ptr<ASTNode> toAST(); //use to construct AST 
    std::vector<Token> toRPN();

private:
    std::vector<Token> _tokens;
    int _current;

    void advance();
    Token peek();
    void setCurrent(int current);
    bool match(TokenType type);


    std::unique_ptr<ASTNode> expression();
    std::unique_ptr<ASTNode> term();
    std::unique_ptr<ASTNode> factor();

};

//bool isValidTokenSequence(); //return true if token sequence is a valid and there is no error tokens
//void filterErrorTokens(); //deletes all error tokens from _tokens