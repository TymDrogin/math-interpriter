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
    NumberNode(const double value);

private:
    const double value_;
};

class UnaryOperationNode : public ASTNode {
public:
    UnaryOperationNode(const Token& token);
    UnaryOperationNode(const BinaryOperatorNodeType type, ASTNode *operand);


private:
    const BinaryOperatorNodeType _type;
    std::unique_ptr<ASTNode> _operand;
};

class BinaryOperationNode : public ASTNode {
public:
    BinaryOperationNode(const Token& token, ASTNode* left, ASTNode* right);
    BinaryOperationNode(const BinaryOperatorNodeType type, ASTNode* left, ASTNode* right);

private:
    const BinaryOperatorNodeType _type;
    std::unique_ptr<ASTNode> _left;
    std::unique_ptr<ASTNode> _right;
};

//class ErrorNode : public ASTNode {
//public:
//    ErrorNode(ErrorNodeType type);
//
//}
//enum class ErrorNodeType {
//    Unknown,
//};