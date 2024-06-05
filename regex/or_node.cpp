//File: or_node.cpp
//Purpose: Implements a multi-way or operator.
//Author: Robert Lowe
#include <string>
#include <vector>
#include "or_node.h"

OrNode::~OrNode() {
  for (auto node : _nodes) {
    delete node;
  }
}


// perform a greedy or match on the given string starting at pos
bool OrNode::match(const std::string &str, size_t &pos) {
  size_t max_pos = pos;
  bool result = false;

  //match, but find the longest match
  for(RegexNode *node : _nodes) {
    size_t cur_pos = pos;
    if(node->match(str, cur_pos)) {
      result = true;
      if(cur_pos > max_pos) {
        max_pos = cur_pos;
      }
    }
  }

  pos = max_pos;
  return result;
}


// add a node to the or
void OrNode::add_node(RegexNode *node) {
  this->_nodes.push_back(node);
}