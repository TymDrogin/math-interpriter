#pragma once

#include "token.hpp"
#include "lexer.hpp"
#include "ast.hpp"

#include <string>
#include <vector>
#include <stack>
#include <iostream>

//TODO: Error processing

enum class Precedece {
    Min,
    Term, 
    Factor, 
    Expression,
    Max
};



class Parser {
public:
    Parser(std::vector<Token>& tokens);

    std::unique_ptr<ASTNode> toAST(std::vector<Token> tokens); //use to construct AST 
    std::vector<Token> toRPN(std::vector<Token> tokens); //use to convert vector to the RPN - reverce polish notation
    
    void setTokensToParse(std::vector<Token> tokens);

private:
    std::vector<Token> _tokens;
    int _position;

    bool isValidTokenSequence(); //return true if token sequence is a valid and there is no error tokens
    void filterErrorTokens(); //deletes all error tokens from _tokens
    
};