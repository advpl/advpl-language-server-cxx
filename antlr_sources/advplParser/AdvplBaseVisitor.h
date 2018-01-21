
// Generated from /home/vlopes/dev/github/advpl-language-server-cxx/antlr/grammar/Advpl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AdvplVisitor.h"


namespace advplParser {

/**
 * This class provides an empty implementation of AdvplVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AdvplBaseVisitor : public AdvplVisitor {
public:

  virtual antlrcpp::Any visitSources(AdvplParser::SourcesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLinePreProcessor(AdvplParser::LinePreProcessorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCrlf(AdvplParser::CrlfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCrlfEmpty(AdvplParser::CrlfEmptyContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace advplParser
