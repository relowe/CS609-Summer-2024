// File: regex_lexer.cpp
// Purpose: A lexer for the regular expression language
// Author: Robert Lowe
#include "regex_lexer.h"
#include "regex.h"
#include <string>

// The tokens
enum Token {
  CHAR_TOK = 1,
  CLASS_TOK,
  INV_CLASS_TOK,
  LPAREN_TOK,
  RPAREN_TOK,
  PIPE_TOK,
  WILDCARD_TOK,
  QUANT_TOK,
  RANGE_TOK
};


//////////////////////////////////////////
// Static Helper Functions
//////////////////////////////////////////

// Construct a handler for escaped characters "\\."
static RegexNode *construct_escaped_node() {
  // TODO: Implement this function.
  return nullptr;
}

// Character Token: [^.()\[\]*+?|]|(\\n | \\t | \\.)
static RegexNode *construct_char_node() {
  // TODO: Implement this function.
  return nullptr;
}

// Construct class spec: ([^\]] | \\.)+
static RegexNode *construct_class_spec_node() {
  // TODO: Implement this function.
  return nullptr;
}

// Class Token \[([^\]]|(\\])|(\\n)|(\\t)|(\\.)|(.-.))+\]
static RegexNode *construct_class_node() {
  // TODO: Implement this function.
  return nullptr;
}

static RegexNode *construct_inv_class_node() {
  // TODO: Implement this function.
  return nullptr;
}

// Lparen: \(
static RegexNode *construct_lparen_node() { 
  // TODO: Implement this function.
  return nullptr;
} 

// Rparen: \)
static RegexNode *construct_rparen_node() { 
  // TODO: Implement this function.
  return nullptr;
}

// Pipe: \|
static RegexNode *construct_pipe_node() { 
  // TODO: Implement this function.
  return nullptr;
}

// Wildcard: \.
static RegexNode *construct_wildcard_node() { 
  // TODO: Implement this function.
  return nullptr;
} 

// Quantifier: \* | \+ | \?
static RegexNode *construct_quantifier_node() {
  // TODO: Implement this function.
  return nullptr;
}

// Range: .-.
static RegexNode *construct_range_node() {
  // TODO: Implement this function.
  return nullptr;
}

// Translate a character
//   \t -> tab
//   \n -> newline
//   \. -> character
//   .  -> character
static char translate_char(const std::string &str) {
  // TODO: Implement this function.
  return str[0];
}

// Handle the construction of the regex node
// for a character match.
static void handle_character(RegexLexer::LexerToken &result) {
  // TODO: Implement this function.
}

// Handle the class spec
static RegexNode *handle_class_spec(const std::string &spec, Lexer &lexer) {
  // TODO: Implement this function.
  return nullptr;
}

static void handle_class(RegexLexer::LexerToken &result, Lexer &lexer) {
  // TODO: Implement this function
}

static void handle_inv_class(RegexLexer::LexerToken &result, Lexer &lexer) {
  // TODO: Implement this function
}

static void handle_quantifier(RegexLexer::LexerToken &result) {
  // TODO: Implement this function
}

//////////////////////////////////////////
// RegexLexer Methods
//////////////////////////////////////////

// construct a regular expression lexer
RegexLexer::RegexLexer() {
  // TODO: Implement this method.
}

// set the input string
void RegexLexer::input(const std::string &_input) { _lexer.input(_input); }

// get the input string
std::string RegexLexer::input() const { return _lexer.input(); }

// get the current position
size_t RegexLexer::position() const { return _lexer.position(); }

// check to see if we are at the end of the input
bool RegexLexer::at_end() const { return _lexer.at_end(); }

// get the next RegexNode, null if there is none
RegexLexer::LexerToken RegexLexer::next() {
  LexerToken result;

  // TODO: Implement this method.
  result.tok = INVALID;

  return result;
}