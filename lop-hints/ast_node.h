// File: ast_node.h
// Purpose: This file contains the definition of a pure virtual class for
//          nodes in an AST. It also contains the definition of an 
//          abstract result type.
// Author: Robert Lowe
#ifndef AST_NODE_H
#define AST_NODE_H
#include "ref_env.h"
class RefEnv;
class FunctionNode;

struct ASTResult {
  enum { VOID=0, INT, REAL, FUNCTION} type;
  union {
    int i;
    double r;
    FunctionNode *f;
  } value;

  bool is_true() const;
};

class ASTNode {
public:
  // virtual destructor
  virtual ~ASTNode();

  // evaluate the node
  virtual ASTResult eval(RefEnv *env) = 0;
};
#endif