#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
enum class InputType { EOI = 0, SEMI, PLUS, TIMES, LP, RP, NUM_OR_ID };

class Lexer {
private:
  std::string buffer;
  int column;
  int row;

public:
  Lexer();
  void analizeFile(std::string filename);
};

#endif
