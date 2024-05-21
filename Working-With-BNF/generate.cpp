#include <cstdlib>
#include <iostream>
#include <string>

// Function prototypes
std::string start();
std::string expression();
std::string term();
std::string factor();
std::string number();
std::string digit();

int main() {
  srand(time(0));
  std::cout << start() << std::endl;
}


// < Start >       ::= < Expression >
std::string start() {
  return expression();
}


// < Expression >  ::= < Expression > "+" < Term > 
//                    | < Expression > "-" < Term >
//                    | < Term >
std::string expression() {
  int rule = rand() % 3;

  switch(rule) { 
    case 0:
      return expression() + "+" + term();
    case 1:
      return expression() + "-" + term();
 }
  
 return term();
}

// < Term>         ::= < Term > "*" < Factor >
//                    | < Term > "/" < Factor >
//                    | < Factor >
std::string term() {
  int rule = rand() % 3;

  switch(rule) {
    case 0:
      return term() + "*" + factor();
    case 1:
      return term() + "/" + factor();
  }

  return factor();
}


// < Factor >      ::= < Number >
std::string factor() {
  return number();
}


// < Number >      ::= < Number > < Digit >
//                     | < Digit >
std::string number() {
  int rule = rand() % 2;
  if(rule == 0) {
    return number() + digit();
  }

  return digit();
}

// < Digit >       ::= "0"|"1"|"2"|...|"9"
std::string digit() {
  int d = rand() % 10 + 1;
  return std::to_string(d);
}