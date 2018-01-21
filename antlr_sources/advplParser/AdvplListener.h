
// Generated from /home/vlopes/dev/github/advpl-language-server-cxx/antlr/grammar/Advpl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AdvplParser.h"


namespace advplParser {

/**
 * This interface defines an abstract listener for a parse tree produced by AdvplParser.
 */
class  AdvplListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSources(AdvplParser::SourcesContext *ctx) = 0;
  virtual void exitSources(AdvplParser::SourcesContext *ctx) = 0;

  virtual void enterLinePreProcessor(AdvplParser::LinePreProcessorContext *ctx) = 0;
  virtual void exitLinePreProcessor(AdvplParser::LinePreProcessorContext *ctx) = 0;

  virtual void enterCrlf(AdvplParser::CrlfContext *ctx) = 0;
  virtual void exitCrlf(AdvplParser::CrlfContext *ctx) = 0;

  virtual void enterCrlfEmpty(AdvplParser::CrlfEmptyContext *ctx) = 0;
  virtual void exitCrlfEmpty(AdvplParser::CrlfEmptyContext *ctx) = 0;


};

}  // namespace advplParser
