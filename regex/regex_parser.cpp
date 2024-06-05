// File: regex_parser.h
// Purpose: Class definition for a recursive descen regex parser.
// Author: Robert Lowe
#include "regex_parser.h"
#include "regex.h"
#include <iostream>
  
// Constructor
RegexParser::RegexParser() {
  // nothing to do here
}

// Destructor
RegexParser::~RegexParser() {
  // nothing to do here
}

// Parse a regex string
RegexNode *RegexParser::parse(const std::string &str) {
  // start off the lexer
  _lexer.input(str);

  // get the first token
  next();

  // parse the regular expression
  return parse_regex();
}

////////////////////////////////////
// Utility Methods
////////////////////////////////////
// Display an error at the current token
void RegexParser::error(const std::string &msg) {
  std::cerr << msg << " at column " << (_cur.pos+1) << std::endl;
}

// Advance the lexer to the next token
void RegexParser::next() {
  // get the next token
  do {
    _cur = _lexer.next();
    if( _cur.tok == Lexer::INVALID ) {
      error("Invalid token");
    }
  } while (_cur.tok == Lexer::INVALID);
}

////////////////////////////////////
// Recursive Descent Methods
////////////////////////////////////

// < Regex >      ::= < Regex > < Match >
//                    | < Match >
RegexNode *RegexParser::parse_regex() {
  GroupNode *result = new GroupNode();
  while(_cur.tok != RegexLexer::END_OF_INPUT) {
    result->add_node(parse_match());
  }

  return result;
}

// < Match >      ::= < Match-Body > QUANTIFIER
//                    | < Match-Body > PIPE < Match >
//                    | < Match-Body >
RegexNode *RegexParser::parse_match() {
  RegexNode *body = parse_match_body();

  // handle quantifier
  if(_cur.tok == RegexLexer::ZERO_QUANT) {
    next();
    return new ZeroNode(body);
  } else if(_cur.tok == RegexLexer::ONE_QUANT) {
    next();
    return new OneNode(body);
  }
  
  // TODO: Implement the rest of this method.
  return body;
}

// < Match-Body > ::= LPAREN < Regex > RPAREN
//                    | REGEX_NODE
RegexNode *RegexParser::parse_match_body() {
  if(_cur.tok == RegexLexer::REGEX_NODE) {
    RegexNode *result = _cur.node;
    next();
    return result;
  }
  
  // TODO: Implement the rest of this method.
  return nullptr;
}