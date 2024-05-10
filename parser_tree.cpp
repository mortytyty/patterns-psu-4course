/**
 * @file parser_tree.cpp
 * @author Fatih Küçükkarakurt (https://github.com/fkkarakurt)
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "parser_tree.h"
#include <stdexcept>

// ConstantNode implementation
ConstantNode::ConstantNode(double value) : value_(value) {}
double ConstantNode::evaluate() const
{
    return value_;
}

// AdditionNode implementation
AdditionNode::AdditionNode(NodePtr left, NodePtr right) : left_(left), right_(right) {}
double AdditionNode::evaluate() const
{
    return left_->evaluate() + right_->evaluate();
}

// SubtractionNode implementation
SubtractionNode::SubtractionNode(NodePtr left, NodePtr right) : left_(left), right_(right) {}
double SubtractionNode::evaluate() const
{
    return left_->evaluate() - right_->evaluate();
}

// MultiplicationNode implementation
MultiplicationNode::MultiplicationNode(NodePtr left, NodePtr right) : left_(left), right_(right) {}
double MultiplicationNode::evaluate() const
{
    return left_->evaluate() * right_->evaluate();
}

// DivisionNode implementation
DivisionNode::DivisionNode(NodePtr left, NodePtr right) : left_(left), right_(right) {}
double DivisionNode::evaluate() const
{
    double denominator = right_->evaluate();
    if (denominator == 0.0)
    {
        throw std::runtime_error("Error: division by 0.");
    }
    return left_->evaluate() / denominator;
}
SinNode::SinNode(NodePtr operand) : operand_(operand) {}
double SinNode::evaluate() const
{
    return std::sin(operand_->evaluate());
}
CosNode::CosNode(NodePtr operand) : operand_(operand) {}
double CosNode::evaluate() const
{
    return std::cos(operand_->evaluate());
}

TanNode::TanNode(NodePtr operand) : operand_(operand) {}
double TanNode::evaluate() const
{
    return std::tan(operand_->evaluate());
}

CotNode::CotNode(NodePtr operand) : operand_(operand) {}
double CotNode::evaluate() const
{
    double tanValue = std::tan(operand_->evaluate());
    if (tanValue == 0.0)
    {
        throw std::runtime_error("Error: Tan value is 0.");
    }
    return 1.0 / tanValue;
}

double LnNode::evaluate() const
{
    return std::log(operand_->evaluate());
}

double LogNode::evaluate() const
{
    return std::log10(operand_->evaluate());
}

double SqrtNode::evaluate() const
{
    double value = operand_->evaluate();
    if (value < 0.0)
    {
        throw std::runtime_error("Error: The square root of a negative number cannot be taken.");
    }
    return std::sqrt(value);
}
