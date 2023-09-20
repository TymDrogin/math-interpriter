#pragma once 

#include "token.hpp"
#include <memory>
#include <stdexcept>

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
    virtual double evaluate() = 0;
};

class NumberNode : public ASTNode {
public:
    NumberNode(const Token &token);
    double evaluate() override;
    

private:
    double _value;
    NumberNodeType _type;
    const Token _token;
};

class UnaryOperationNode : public ASTNode {
public:
    UnaryOperationNode(const Token& token, std::unique_ptr<ASTNode> operand);
    double evaluate() override;
   
private:
    const Token _token;
    UnaryOperatorNodeType _type;
    std::unique_ptr<ASTNode> _operand;
};

class BinaryOperationNode : public ASTNode {
public:
    BinaryOperationNode(const Token& token, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right);
    double evaluate() override;

private:
    const Token _token;
    BinaryOperatorNodeType _type;
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