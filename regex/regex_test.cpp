#include "character_node.h"
#include "group_node.h"
#include "inverse_node.h"
#include "one_node.h"
#include "optional_node.h"
#include "or_node.h"
#include "range_node.h"
#include "zero_node.h"
#include "wildcard_node.h"
#include <iostream>
#include <string>

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex);

// Construct regular expression .*
RegexNode *construct_regex1();

// Construct regular expression a*
RegexNode *construct_regex2();

// Construct regular expression (ab)*ac
RegexNode *construct_regex3();

// Construct regular expression (ab)+ac
RegexNode *construct_regex4();

// Construct regular expression (a|(aa))b
RegexNode *construct_regex5();

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex6();

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex7();

// Construct the regular expression "[^"]*"
RegexNode *construct_regex8();

// Construct the regular expression ...
RegexNode *construct_regex9();

int main() {
  std::string input_str;
  RegexNode *regex1 = construct_regex1();
  RegexNode *regex2 = construct_regex2();
  RegexNode *regex3 = construct_regex3();
  RegexNode *regex4 = construct_regex4();
  RegexNode *regex5 = construct_regex5();
  RegexNode *regex6 = construct_regex6();
  RegexNode *regex7 = construct_regex7();
  RegexNode *regex8 = construct_regex8();
  RegexNode *regex9 = construct_regex9();

  while (std::cin) {
    // get the user input
    std::cout << "Input> ";
    getline(std::cin, input_str);
    if (!std::cin)
      continue;

    // print the result
    print_match(".*", input_str, regex1);
    print_match("a*", input_str, regex2);
    print_match("(ab)*ac", input_str, regex3);
    print_match("(ab)+ac", input_str, regex4);
    print_match("(a|(aa))b", input_str, regex5);
    print_match("[0-9]+(\\.[0-9]+)?", input_str, regex6);
    print_match("[a-zA-Z]+", input_str, regex7);
    print_match("\"[^\"]*\"", input_str, regex8);
    print_match("...", input_str, regex9);
  }

  // cleanup
  delete regex1;
  delete regex2;
  delete regex3;
  delete regex4;
  delete regex5;
  delete regex6;
  delete regex7;
  delete regex8;
  delete regex9;
}

// Construct regular expression .*
RegexNode *construct_regex1() {
  // create the result
  GroupNode *regex = new GroupNode();

  /*  Design AST 
                 GROUP    regex
                 /
                *         zero
               /
              .           wildcard
   */
  // build in a bottom up sort of way
  WildcardNode *wildcard = new WildcardNode();
  ZeroNode *zero = new ZeroNode(wildcard);
  regex->add_node(zero);

  return regex;
}

// Construct regular expression a*
RegexNode *construct_regex2() {
  // create the result
  GroupNode *regex = new GroupNode();

  /*  Design AST
                 GROUP    regex  
                /
              *           wildcard
            /
           a              a
   */
  // build in a bottom up sort of way
  CharacterNode *a = new CharacterNode('a');
  ZeroNode *zero = new ZeroNode(a); 
  regex->add_node(zero);

  return regex;
}

// Construct regular expression (ab)*ac
RegexNode *construct_regex3() {
  // create the result
  GroupNode *regex = new GroupNode();

  // TODO: Impelemnt this function;
  /* Design AST
                 GROUP    regex  
                /     \
               *      GROUP
              /       /    \
            GROUP    a      c
            /    \
           a      b
   */

  return regex;
}

// Construct regular expression (ab)+ac
RegexNode *construct_regex4() {
  // create the result
  GroupNode *regex = new GroupNode();
  
  // TODO: Impelemnt this function;

  return regex;
}

// Construct regular expression (a|(aa))b
RegexNode *construct_regex5() {
  // create the result
  GroupNode *regex = new GroupNode();

  // TODO: Impelemnt this function;
  
  return regex;
}


// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex6() {
  GroupNode *regex = new GroupNode();

  // TODO: Impelemnt this function.

  return regex;
}

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex7() {
  GroupNode *regex = new GroupNode();

  // TODO: Impelemnt this function.

  return regex;
}

// Construct the regular expression "[^"]*"
RegexNode *construct_regex8() {
  GroupNode *regex = new GroupNode();

  // TODO: Impelemnt this function;
  
  return regex;
}

// Construct the regular expression ...
RegexNode *construct_regex9() {
  GroupNode *regex = new GroupNode();

  // TODO: Impelemnt this function;

  return regex;
}

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex) {
  size_t pos = 0;

  std::cout << label << ": ";
  if (regex->match(input, pos) && pos == input.length()) {
    std::cout << "Match!" << std::endl;
  } else {
    std::cout << "No match." << std::endl;
  }
}