#include "Lexer.hpp"
#include "Parser.hpp"

int main() {
  Lexer lexer;
  std::string filename = "../docs/errorsInput.txt";

  lexer.analizeFile(filename);
  std::vector<data> tokens = lexer.getTokenList();

  Parser parser(tokens);
  parser.parse();

  return 0;
}
