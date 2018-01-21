
// Generated from /home/vlopes/dev/github/advpl-language-server-cxx/antlr/grammar/Advpl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AdvplListener.h"


namespace advplParser {

/**
 * This class provides an empty implementation of AdvplListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AdvplBaseListener : public AdvplListener {
public:

  virtual void enterSources(AdvplParser::SourcesContext * /*ctx*/) override { }
  virtual void exitSources(AdvplParser::SourcesContext * /*ctx*/) override { }

  virtual void enterLinePreProcessor(AdvplParser::LinePreProcessorContext * /*ctx*/) override { }
  virtual void exitLinePreProcessor(AdvplParser::LinePreProcessorContext * /*ctx*/) override { }

  virtual void enterCrlf(AdvplParser::CrlfContext * /*ctx*/) override { }
  virtual void exitCrlf(AdvplParser::CrlfContext * /*ctx*/) override { }

  virtual void enterCrlfEmpty(AdvplParser::CrlfEmptyContext * /*ctx*/) override { }
  virtual void exitCrlfEmpty(AdvplParser::CrlfEmptyContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace advplParser
