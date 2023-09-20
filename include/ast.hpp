#pragma once 

#include "token.hpp"
#include <memory>
#include <stdexcept>
#include <cmath>
#include <utility>

enum class NumberNodeType {
    Int,    Dec,
};
enum class UnaryOpNodeType {
    Pos,    Neg,
};
enum class BinaryOpNodeType {
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
    explicit NumberNode(const Token &token);
    double evaluate() override;
    

private:
    const Token _token;
    NumberNodeType _type;
    double _value;
};

class UnaryOpNode : public ASTNode {
public:
    UnaryOpNode(const Token &token, std::unique_ptr<ASTNode> operand);
    double evaluate() override;
   
private:
    const Token _token;
    UnaryOpNodeType _type;
    std::unique_ptr<ASTNode> _operand;
};

class BinaryOpNode : public ASTNode {
public:
    BinaryOpNode(const Token &token, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right);
    double evaluate() override;

private:
    const Token _token;
    BinaryOpNodeType _type;
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