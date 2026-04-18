#pragma once
#include <string>
#include <vector>

enum class InputType {
  EOI = 0,
  SEMI,
  PLUS,
  SUB,
  TIMES,
  DIV,
  LP,
  RP,
  NUM_OR_ID
};
struct data {
  std::string token;
  InputType type;
};

class Lexer {
private:
  std::string buffer;
  int column;
  int row;
  std::vector<data> tokenList;

public:
  Lexer();
  void analizeFile(std::string filename);
  void tokenize(char c);
  void tokenizeEnd();

  std::vector<data> getTokenList();
};
