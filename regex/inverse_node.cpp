// File: inverse_node.cpp
// Purpose: The optional node quantifier
// Author: Robert Lowe
#include "inverse_node.h"

InverseNode::InverseNode(RegexNode* _node)
{
  this->_node = _node;  
}

InverseNode::~InverseNode() {
  delete this->_node;
}


// attempt to match the string at position pos
bool InverseNode::match(const std::string& str, size_t &pos)
{
  // TODO: Implement this method.
  return false;
}