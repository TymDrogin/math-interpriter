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
    Parser(std::vector<Token>& tokens);

    std::unique_ptr<ASTNode> toAST(); //use to construct AST 

    //std::vector<Token> toRPN(std::vector<Token> tokens); //use to convert vector to the RPN - reverce polish notation 

private:
    std::vector<Token> _tokens;
    int _current;

    void advance();
    Token peek();
    Token previous();
    bool match(TokenType type);

    //bool isValidTokenSequence(); //return true if token sequence is a valid and there is no error tokens
    //void filterErrorTokens(); //deletes all error tokens from _tokens

    std::unique_ptr<ASTNode> expression();
    std::unique_ptr<ASTNode> term();
    std::unique_ptr<ASTNode> factor();

};