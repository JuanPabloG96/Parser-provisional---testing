#pragma once

#include "Lexer.hpp"

class Parser {
 private:
  std::vector<data> tokenList;
  int current;

  bool match(InputType type);
  void advance();

  void statements();
  void expression();
  void expr_prime();
  void term();
  void term_prime();
  void factor();

 public:
  Parser(std::vector<data> tokenList);
  void parse();
};
