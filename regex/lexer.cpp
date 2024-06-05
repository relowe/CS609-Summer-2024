// File: lexer.cpp
// Purpose: Lexer implementation
// Author: Robert Lowe
#include "lexer.h"

// construct a lexer with an empty string to scan
Lexer::Lexer() : Lexer("") {
  // this space left intentionally blank
}

// construct a lexer to scan the given input string
Lexer::Lexer(const std::string &_input) { input(_input); }

// destroy the lexer and deallocate all the RegexNodes
Lexer::~Lexer() {
  // delete all the regex nodes
  for (auto &token : _tokens) {
    delete token.second;
  }
}

// set the input string to scan
void Lexer::input(const std::string &_input) {
  this->_input = _input; // read the input string
  this->_pos = 0;        // start at the beginning of the input string
}

// retrieve the input string to scan
std::string Lexer::input() const { return _input; }

// return true if the lexer is at the end of the input
bool Lexer::at_end() const { return _pos >= _input.length(); }

// return the current position of the lexer
int Lexer::position() const { return _pos; }

// Add a new token to the lexer
void Lexer::add_token(int tok, RegexNode *pattern) {
  this->_tokens.push_back(std::pair<int, RegexNode *>(tok, pattern));
}

// Get the next token from the input string
Lexer::Token Lexer::next() {
  Token token;          // the result of the lexing process
  size_t final_pos = 0; // the position of the first character beyond the token

  // set the token defaults
  token.tok = Lexer::INVALID;
  token.pos = _pos;

  // handle the end of input
  if(at_end()) {
    token.tok = Lexer::END_OF_INPUT;
    token.lexeme = "";
    return token;
  }

  // find the longest possible match
  for(auto pattern : this->_tokens) {
    size_t pos = this->_pos;
    if(pattern.second->match(_input, pos) && pos > final_pos) {
      final_pos = pos;
      token.tok = pattern.first;
    }
  }

  // update the _pos and the lexeme 
  if(token.tok != Lexer::INVALID) {
    token.lexeme = _input.substr(this->_pos, final_pos - this->_pos);
    _pos = final_pos;
  } else {
    token.lexeme = _input.substr(this->_pos, 1);
    _pos++;
  }
  
  return token;
}