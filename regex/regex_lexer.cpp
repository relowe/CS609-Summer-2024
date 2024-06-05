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
  return new CharacterNode('(');
} 

// Rparen: \)
static RegexNode *construct_rparen_node() { 
  return new CharacterNode(')');
}

// Pipe: \|
static RegexNode *construct_pipe_node() { 
  return new CharacterNode('|');
}

// Wildcard: \.
static RegexNode *construct_wildcard_node() { 
  return new CharacterNode('.');
} 

// Quantifier: \* | \+ | \?
static RegexNode *construct_quantifier_node() {
  OrNode *result = new OrNode();
  result->add_node(new CharacterNode('*'));
  result->add_node(new CharacterNode('+'));
  result->add_node(new CharacterNode('?'));
  return result;
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
  result.tok = RegexLexer::REGEX_NODE;
  switch(result.lexeme[0]) {
    case '*':
      result.tok = RegexLexer::ZERO_QUANT;
      break;
    case '+':
      result.tok = RegexLexer::ONE_QUANT;
      break;
    case '?':
      result.tok = RegexLexer::OPTION_QUANT;
      break;
  }
}

//////////////////////////////////////////
// RegexLexer Methods
//////////////////////////////////////////

// construct a regular expression lexer
RegexLexer::RegexLexer() {
  // blank input
  input("");

  _lexer.add_token(LPAREN_TOK, construct_lparen_node());
  _lexer.add_token(RPAREN_TOK, construct_rparen_node());
  _lexer.add_token(PIPE_TOK, construct_pipe_node());
  _lexer.add_token(WILDCARD_TOK, construct_wildcard_node());
  _lexer.add_token(QUANT_TOK, construct_quantifier_node());

  //TODO: Add the other tokens
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
  Lexer::Token lt = _lexer.next();

  //copy the basic fields
  result.lexeme = lt.lexeme;
  result.pos = lt.pos;

  // process our token
  switch(lt.tok) {
    case INVALID:
      result.tok = INVALID;
      break;
    case END_OF_INPUT:
      result.tok = END_OF_INPUT;
      break;
    case LPAREN_TOK:
      result.tok = LPAREN;
      break;
    case RPAREN_TOK:
      result.tok = RPAREN;
      break;
    case PIPE_TOK:
      result.tok = OR;
      break;
    case WILDCARD_TOK:
      result.tok = REGEX_NODE;
      result.node = new WildcardNode();
      break;
    case QUANT_TOK:
      handle_quantifier(result);
      break;
    // TODO: Add the other tokens
  }

  return result;
}