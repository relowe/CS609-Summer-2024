TARGETS=regex_test regex lib/libreglex.a lib/reglex.h
REGEX_LIB=regex_node.o\
          character_node.o\
					group_node.o\
					zero_node.o\
					one_node.o\
					or_node.o\
					range_node.o\
					optional_node.o\
					inverse_node.o\
					wildcard_node.o\
					lexer.o\
					regex_lexer.o\
					regex_parser.o\
					lib.o
LD=g++
CC=g++
CXX=g++
CXXFLAGS=

all: $(TARGETS)
regex_test: regex_test.o $(REGEX_LIB)
regex: regex.o $(REGEX_LIB)
lib:
	mkdir lib

lib/reglex.h: lib regex_node.h lexer.h lib.h
	cat regex_node.h lexer.h lib.h > $@

lib/libreglex.a: lib $(REGEX_LIB)
	ar r $@ $(REGEX_LIB)

clean:
	rm -f *.o $(TARGETS)
	rm -rf lib