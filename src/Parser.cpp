#include "Parser.hpp"

#include <iostream>

#include "Parser.hpp"

Parser::Parser(std::vector<data> tokenList) : tokenList(tokenList), current(0) {
}

bool Parser::match(InputType type) {
  return tokenList[current].type == type;
}

void Parser::advance() {
  if (!match(InputType::EOI))
    current++;
}

void Parser::parse() {
  statements();
}

void Parser::statements() {
  std::cout << "statements -> ";
  expression();

  if (match(InputType::SEMI)) {
    std::cout << ";\n";
    advance();
  } else
    std::cerr << "Error in line " << tokenList[current].row << ":"
              << tokenList[current].column << " Insert missing semicolon\n";

  if (!match(InputType::EOI))
    statements();
}

void Parser::expression() {
  std::cout << "expresion -> ";
  term();
  expr_prime();
}

void Parser::expr_prime() {
  std::cout << "expresion' -> ";
  if (match(InputType::PLUS) || match(InputType::SUB)) {
    std::cout << tokenList[current].token << "\n";
    advance();
    term();
    expr_prime();
  } else
    std::cout << "ε\n";
}

void Parser::term() {
  std::cout << "term -> ";
  factor();
  term_prime();
}

void Parser::term_prime() {
  std::cout << "term' -> ";
  if (match(InputType::TIMES) || match(InputType::DIV)) {
    std::cout << tokenList[current].token << "\n";
    advance();
    factor();
    term_prime();
  } else
    std::cout << "ε\n";
}

void Parser::factor() {
  std::cout << "factor -> ";
  if (match(InputType::NUM_OR_ID)) {
    std::cout << tokenList[current].token << "\n";
    advance();
  } else if (match(InputType::LP)) {
    std::cout << "( ->";
    advance();
    expression();

    if (match(InputType::RP)) {
      std::cout << " ) ->";
      advance();
    } else
      std::cerr << "Error in line " << tokenList[current].row << ":"
                << tokenList[current].column << " Mismatch parentesis\n";
  } else {
    std::cerr << "Error in line " << tokenList[current].row << ":"
              << tokenList[current].column
              << " Number or identifier expected, got: "
              << tokenList[current].token << "\n";
  }
}
