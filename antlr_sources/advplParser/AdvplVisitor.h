
// Generated from /home/vlopes/dev/github/advpl-language-server-cxx/antlr/grammar/Advpl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AdvplParser.h"


namespace advplParser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by AdvplParser.
 */
class  AdvplVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AdvplParser.
   */
    virtual antlrcpp::Any visitSources(AdvplParser::SourcesContext *context) = 0;

    virtual antlrcpp::Any visitLinePreProcessor(AdvplParser::LinePreProcessorContext *context) = 0;

    virtual antlrcpp::Any visitCrlf(AdvplParser::CrlfContext *context) = 0;

    virtual antlrcpp::Any visitCrlfEmpty(AdvplParser::CrlfEmptyContext *context) = 0;


};

}  // namespace advplParser
