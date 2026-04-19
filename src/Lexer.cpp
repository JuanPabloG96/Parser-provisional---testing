#include "Lexer.hpp"

#include <fstream>
#include <iostream>

Lexer::Lexer() : buffer(""), column(0), row(0) {
}

void Lexer::analizeFile(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file" << std::endl;
    return;
  }

  char c;

  while (file.get(c)) {
    if (c == '\n') {
      row++;
      column = 0;
    } else
      column++;

    tokenize(c);
  }

  tokenizeEnd();

  file.close();
}

void Lexer::tokenize(char c) {
  if (isspace(c)) {
    if (!buffer.empty()) {
      tokenList.push_back({buffer, InputType::NUM_OR_ID, row, column});
      buffer.clear();
    }
  }

  else if (isalnum(c)) {
    buffer += c;
  } else {
    if (!buffer.empty()) {
      tokenList.push_back({buffer, InputType::NUM_OR_ID, row, column});
      buffer.clear();
    }

    data dataInstance = {std::string(1, c), InputType::EOI, row, column};

    switch (c) {
      case ';':
        dataInstance.type = InputType::SEMI;
        break;
      case '+':
        dataInstance.type = InputType::PLUS;
        break;
      case '-':
        dataInstance.type = InputType::SUB;
        break;
      case '*':
        dataInstance.type = InputType::TIMES;
        break;
      case '/':
        dataInstance.type = InputType::DIV;
        break;
      case '(':
        dataInstance.type = InputType::LP;
        break;
      case ')':
        dataInstance.type = InputType::RP;
        break;
      default:
        break;
    }
    tokenList.push_back(dataInstance);
  }
}

void Lexer::tokenizeEnd() {
  if (!buffer.empty()) {
    tokenList.push_back({buffer, InputType::NUM_OR_ID, row, column});
    buffer.clear();
  }
  tokenList.push_back({"\0", InputType::EOI, row, column});
}

std::vector<data> Lexer::getTokenList() {
  return tokenList;
}
