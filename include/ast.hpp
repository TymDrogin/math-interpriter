#pragma once 

#include "token.hpp"
#include <memory>

enum class NumberNodeType {
    Int,    Dec,
};
enum class UnaryOperatorNodeType {
    Pos,    Neg,
};
enum class BinaryOperatorNodeType {
    Add,    Sub,
    Mul,    Div,
    Pow,   
};
enum class FunctionNodeType {
    Sin, Cos,
    Sqrt, Ln, 

};

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class NumberNode : public ASTNode {
public:
    NumberNode(const Token &token);

    const Token token;
};

class UnaryOperationNode : public ASTNode {
public:
    UnaryOperationNode(const Token& token);

};

class BinaryOperationNode : public ASTNode {
public:
    BinaryOperationNode(const Token& token, ASTNode* left, ASTNode* right);
};

//class ErrorNode : public ASTNode {
//public:
//    ErrorNode(ErrorNodeType type);
//
//}
//enum class ErrorNodeType {
//    Unknown,
//};