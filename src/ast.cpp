#include "ast.hpp"

/* Constructors */
NumberNode::NumberNode(const Token& token) {}
NumberNode::NumberNode(const double value)
{
}
;
UnaryOperationNode::UnaryOperationNode(const Token& token) {}
UnaryOperationNode::UnaryOperationNode(BinaryOperatorNodeType type, ASTNode* operand)
{
}
;
BinaryOperationNode::BinaryOperationNode(const Token& token, ASTNode* left, ASTNode* right) {}
BinaryOperationNode::BinaryOperationNode(const BinaryOperatorNodeType type, ASTNode* left, ASTNode* right)
{
}
;

/* Destructors */

/* Public*/



/* Private */