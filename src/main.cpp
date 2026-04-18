#include "Lexer.hpp"

int main() {

  Lexer lexer;
  std::string filename = "../docs/input.txt";

  lexer.analizeFile(filename);
  std::vector<data> tokens = lexer.getTokenList();

  return 0;
}
