#pragma once

#include "token.hpp"
#include "lexer.hpp"

#include <string>
#include <vector>
#include <iostream>


class Parser {
public:
    Parser(const std::vector<Token>& tokens) : tokens_(tokens), current_(0) {}

    ASTNode* parse() {
        //return parseExpression();
    }

    double Evaluate();

private:
    std::vector<Token> tokens_;
    int current_;
};

class ASTNode {
public:
    virtual ~ASTNode() {}
};


