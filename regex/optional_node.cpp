// File: optional_node.h
// Purpose: The optional node quantifier
// Author: Robert Lowe
#include "optional_node.h"

OptionalNode::OptionalNode(RegexNode *_node) { this->_node = _node; }

OptionalNode::~OptionalNode() {
  delete this->_node;
}

// attempt to match the string at position pos
bool OptionalNode::match(const std::string &str, size_t &pos) {
  // TODO: Implement this method.
  return false;
}