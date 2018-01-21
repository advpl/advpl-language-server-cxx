#define BOOST_TEST_MAIN teste1
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include "AdvplLSPCallbacks.hpp"
#include "AdvplLexer.h"
#include "AdvplParser.h"
#include "antlr4-runtime.h"

BOOST_AUTO_TEST_CASE(la) {
  antlr4::ANTLRInputStream input("#LINE 1 \"TEST\"\n");
  advplParser::AdvplLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  advplParser::AdvplParser parser(&tokens);
  antlr4::tree::ParseTree *tree;
  tree = parser.sources();

  std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";

  BOOST_CHECK_EQUAL(1, 1);
}
