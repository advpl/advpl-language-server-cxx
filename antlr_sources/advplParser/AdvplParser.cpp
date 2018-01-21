
// Generated from /home/vlopes/dev/github/advpl-language-server-cxx/antlr/grammar/Advpl.g4 by ANTLR 4.7.1


#include "AdvplListener.h"
#include "AdvplVisitor.h"

#include "AdvplParser.h"


using namespace antlrcpp;
using namespace advplParser;
using namespace antlr4;

AdvplParser::AdvplParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AdvplParser::~AdvplParser() {
  delete _interpreter;
}

std::string AdvplParser::getGrammarFileName() const {
  return "Advpl.g4";
}

const std::vector<std::string>& AdvplParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AdvplParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SourcesContext ------------------------------------------------------------------

AdvplParser::SourcesContext::SourcesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AdvplParser::LinePreProcessorContext* AdvplParser::SourcesContext::linePreProcessor() {
  return getRuleContext<AdvplParser::LinePreProcessorContext>(0);
}


size_t AdvplParser::SourcesContext::getRuleIndex() const {
  return AdvplParser::RuleSources;
}

void AdvplParser::SourcesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSources(this);
}

void AdvplParser::SourcesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSources(this);
}


antlrcpp::Any AdvplParser::SourcesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AdvplVisitor*>(visitor))
    return parserVisitor->visitSources(this);
  else
    return visitor->visitChildren(this);
}

AdvplParser::SourcesContext* AdvplParser::sources() {
  SourcesContext *_localctx = _tracker.createInstance<SourcesContext>(_ctx, getState());
  enterRule(_localctx, 0, AdvplParser::RuleSources);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    linePreProcessor();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LinePreProcessorContext ------------------------------------------------------------------

AdvplParser::LinePreProcessorContext::LinePreProcessorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AdvplParser::LinePreProcessorContext::NUMBER() {
  return getToken(AdvplParser::NUMBER, 0);
}

tree::TerminalNode* AdvplParser::LinePreProcessorContext::STRING() {
  return getToken(AdvplParser::STRING, 0);
}

tree::TerminalNode* AdvplParser::LinePreProcessorContext::CRLF() {
  return getToken(AdvplParser::CRLF, 0);
}


size_t AdvplParser::LinePreProcessorContext::getRuleIndex() const {
  return AdvplParser::RuleLinePreProcessor;
}

void AdvplParser::LinePreProcessorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLinePreProcessor(this);
}

void AdvplParser::LinePreProcessorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLinePreProcessor(this);
}


antlrcpp::Any AdvplParser::LinePreProcessorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AdvplVisitor*>(visitor))
    return parserVisitor->visitLinePreProcessor(this);
  else
    return visitor->visitChildren(this);
}

AdvplParser::LinePreProcessorContext* AdvplParser::linePreProcessor() {
  LinePreProcessorContext *_localctx = _tracker.createInstance<LinePreProcessorContext>(_ctx, getState());
  enterRule(_localctx, 2, AdvplParser::RuleLinePreProcessor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    match(AdvplParser::T__0);
    setState(11);
    match(AdvplParser::NUMBER);
    setState(12);
    match(AdvplParser::STRING);
    setState(13);
    match(AdvplParser::CRLF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CrlfContext ------------------------------------------------------------------

AdvplParser::CrlfContext::CrlfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AdvplParser::CrlfContext::CRLF() {
  return getTokens(AdvplParser::CRLF);
}

tree::TerminalNode* AdvplParser::CrlfContext::CRLF(size_t i) {
  return getToken(AdvplParser::CRLF, i);
}


size_t AdvplParser::CrlfContext::getRuleIndex() const {
  return AdvplParser::RuleCrlf;
}

void AdvplParser::CrlfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCrlf(this);
}

void AdvplParser::CrlfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCrlf(this);
}


antlrcpp::Any AdvplParser::CrlfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AdvplVisitor*>(visitor))
    return parserVisitor->visitCrlf(this);
  else
    return visitor->visitChildren(this);
}

AdvplParser::CrlfContext* AdvplParser::crlf() {
  CrlfContext *_localctx = _tracker.createInstance<CrlfContext>(_ctx, getState());
  enterRule(_localctx, 4, AdvplParser::RuleCrlf);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AdvplParser::CRLF: {
        setState(16); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(15);
          match(AdvplParser::CRLF);
          setState(18); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == AdvplParser::CRLF);
        break;
      }

      case AdvplParser::T__1: {
        setState(20);
        match(AdvplParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CrlfEmptyContext ------------------------------------------------------------------

AdvplParser::CrlfEmptyContext::CrlfEmptyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AdvplParser::CrlfEmptyContext::CRLF() {
  return getTokens(AdvplParser::CRLF);
}

tree::TerminalNode* AdvplParser::CrlfEmptyContext::CRLF(size_t i) {
  return getToken(AdvplParser::CRLF, i);
}


size_t AdvplParser::CrlfEmptyContext::getRuleIndex() const {
  return AdvplParser::RuleCrlfEmpty;
}

void AdvplParser::CrlfEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCrlfEmpty(this);
}

void AdvplParser::CrlfEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AdvplListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCrlfEmpty(this);
}


antlrcpp::Any AdvplParser::CrlfEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AdvplVisitor*>(visitor))
    return parserVisitor->visitCrlfEmpty(this);
  else
    return visitor->visitChildren(this);
}

AdvplParser::CrlfEmptyContext* AdvplParser::crlfEmpty() {
  CrlfEmptyContext *_localctx = _tracker.createInstance<CrlfEmptyContext>(_ctx, getState());
  enterRule(_localctx, 6, AdvplParser::RuleCrlfEmpty);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AdvplParser::CRLF: {
        setState(24); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(23);
          match(AdvplParser::CRLF);
          setState(26); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == AdvplParser::CRLF);
        break;
      }

      case AdvplParser::T__1: {
        setState(28);
        match(AdvplParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> AdvplParser::_decisionToDFA;
atn::PredictionContextCache AdvplParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AdvplParser::_atn;
std::vector<uint16_t> AdvplParser::_serializedATN;

std::vector<std::string> AdvplParser::_ruleNames = {
  "sources", "linePreProcessor", "crlf", "crlfEmpty"
};

std::vector<std::string> AdvplParser::_literalNames = {
  "", "'#LINE'", "';'", "'<'", "'>'", "'='", "'<='", "'>='", "'=='", "'!='", 
  "'<>'", "'#'", "'$'", "'++'", "'--'", "'+='", "'+'", "'-'", "'*'", "'/'", 
  "'**'", "'%'", "'@'", "'&'", "'BEGIN'", "'TRANSACTION'", "'SEQUENCE'", 
  "", "'->'", "'STEP'", "'TO'", "'.T.'", "'.F.'", "'NIL'", "'#DEFINE'", 
  "'#UNDEF'", "'#IFDEF'", "'#IFNDEF'", "'#ELSE'", "'#ENDIF'", "'FOR'", "'NEXT'", 
  "'WHILE'", "'DO'", "'ELSEIF'", "'IF'", "'ELSE'", "'ENDI'", "'ENDIF'", 
  "'ENDIF.'", "'ENDDO'", "'ENDFOR'", "'END'", "'EXTENDED'", "'CASE'", "'ENDCASE'", 
  "'OTHERWISE'", "'EXIT'", "'LOOP'", "'LOCA'", "'LOCAL'", "'PRIVATE'", "'PUBLIC'", 
  "'STATIC'", "'USER'", "'WEB'", "'MAIN'", "'FUNCTION'", "'FUNCTIO'", "'PROCEDURE'", 
  "'SELF'", "'PROJECT'", "'TEMPLATE'", "'.AND.'", "'.OR.'", "'.NOT.'", "'DEFAULT'", 
  "'RETURN'", "'ASSUME'", "'CLASS'", "'ENDCLASS'", "'METHOD'", "'DATA'", 
  "'FROM'", "'HIDDEN'", "'READONLY'", "'DESCRIPTION'", "'QSSTRUCT'", "'QSMETHOD'", 
  "'MODULE'", "'INIT'", "'AS'", "'OF'", "'PRODUCES'", "'OPTIONAL'", "'REQUEST'", 
  "'QUERYPARAM'", "'WSREST'", "'CAMELCASE'", "'PATHPARAM'", "'GET'", "'POST'", 
  "'PUT'", "'DELETE'", "'BYREF'", "'DATASET'", "'PROCESS'", "'TITLE'", "'PERGUNTE'", 
  "'PATH'", "'('", "')'", "'['", "']'", "", "','", "'.'", "':='", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'\uFFFD'", 
  "'\u0004'", "'\u00A0'", "'\u0001'", "'\u0002'", "'\u0003'", "'\u001F'", 
  "'\u00A7'", "'\u00A2'", "'\u00A3'", "'\u00C0'", "'\u00DF'", "'\u00B1'", 
  "'\u00C4'", "'\u00C1'", "'\u00D9'", "'`'", "'\u00BB'", "'\u00BF'"
};

std::vector<std::string> AdvplParser::_symbolicNames = {
  "", "", "", "MINOR", "MAJOR", "EQUALS", "MINOREQUALS", "MAJOREQUALS", 
  "DOUBLEEQUAL", "DIF1", "DIF2", "DIF3", "CONTIDO", "PLUSPLUS", "MINUSMINUS", 
  "PLUSEQUALS", "PLUS", "MINUS", "MULT", "DIV", "POW", "PERC", "ARROBA", 
  "ECOMERCIAL", "BEGIN", "TRANSACTION", "SEQUENCE", "BEGIN_SQL", "ALIASACCESS", 
  "STEP", "TO", "TRUE", "FALSE", "NIL", "DEFINE", "UNDEFINE", "IFDEF", "IFNDEF", 
  "ELSEDEF", "ENDIFDEF", "FOR", "NEXT", "WHILE", "DO", "ELSEIF", "IF", "ELSE", 
  "ENDI", "ENDIF", "ENDIF_DOT", "ENDDO", "ENDFOR", "END", "EXTENDED", "CASE", 
  "ENDCASE", "OTHERWISE", "EXIT", "LOOP", "LOCA", "LOCAL", "PRIVATE", "PUBLIC", 
  "STATIC", "USER", "WEB", "MAIN", "FUNCTION", "FUNCTIO", "PROCEDURE", "SELF", 
  "PROJECT", "TEMPLATE", "AND", "OR", "NOT", "DEFAULT", "RETURN", "ASSUME", 
  "CLASS", "ENDCLASS", "METHOD", "DATA", "FROM", "C_HIDDEN", "READONLY", 
  "DESCRIPTION", "QSSTRUCT", "QSMETHOD", "MODULE", "INIT", "AS", "OF", "PRODUCES", 
  "OPTIONAL", "REQUEST", "QUERYPARAM", "WSREST", "CAMELCASE", "PATHPARAM", 
  "GET", "POST", "PUT", "DELETE", "BYREF", "DATASET", "PROCESS", "TITLE", 
  "PERGUNTE", "PATH", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "INCLUDE", 
  "COMMA", "DOT", "ATTRIB_OPERATOR", "NUMBER", "IDENTIFIER", "COMMENT", 
  "LINE_COMMENT", "LINE_COMMENT_EE", "LINE_COMMENT_BIZARRO", "LINE_COMMENT_BIZARRO2", 
  "LINE_COMMENT_BIZARRO3", "LINE_COMMENT_BIZARRO4", "LINE_COMMENT_BIZARRO5", 
  "LINE_COMMENT_BIZARRO6", "LINE_COMMENT_BIZARRO7", "ASTERICO", "STRING", 
  "STRINGSIMPLE", "CRLF", "WS", "INVALID_CHAR", "INVALID_CHAR_1", "INVALID_CHAR_2", 
  "INVALID_CHAR_3", "INVALID_CHAR_4", "INVALID_CHAR_14", "INVALID_CHAR_17", 
  "INVALID_CHAR_5", "INVALID_CHAR_6", "INVALID_CHAR_7", "INVALID_CHAR_8", 
  "INVALID_CHAR_9", "INVALID_CHAR_10", "INVALID_CHAR_11", "INVALID_CHAR_12", 
  "INVALID_CHAR_13", "INVALID_CHAR_16", "INVALID_CHAR_18", "INVALID_CHAR_19", 
  "ErrorChar"
};

dfa::Vocabulary AdvplParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AdvplParser::_tokenNames;

AdvplParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x9c, 0x22, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x6, 0x4, 0x13, 0xa, 0x4, 0xd, 0x4, 
    0xe, 0x4, 0x14, 0x3, 0x4, 0x5, 0x4, 0x18, 0xa, 0x4, 0x3, 0x5, 0x6, 0x5, 
    0x1b, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x1c, 0x3, 0x5, 0x5, 0x5, 0x20, 
    0xa, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x2, 0x2, 
    0x21, 0x2, 0xa, 0x3, 0x2, 0x2, 0x2, 0x4, 0xc, 0x3, 0x2, 0x2, 0x2, 0x6, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x5, 
    0x4, 0x3, 0x2, 0xb, 0x3, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x7, 0x3, 0x2, 
    0x2, 0xd, 0xe, 0x7, 0x78, 0x2, 0x2, 0xe, 0xf, 0x7, 0x85, 0x2, 0x2, 0xf, 
    0x10, 0x7, 0x87, 0x2, 0x2, 0x10, 0x5, 0x3, 0x2, 0x2, 0x2, 0x11, 0x13, 
    0x7, 0x87, 0x2, 0x2, 0x12, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x15, 0x18, 0x3, 0x2, 0x2, 0x2, 0x16, 0x18, 0x7, 0x4, 0x2, 
    0x2, 0x17, 0x12, 0x3, 0x2, 0x2, 0x2, 0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x7, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1b, 0x7, 0x87, 0x2, 0x2, 0x1a, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x20, 0x7, 0x4, 0x2, 0x2, 0x1f, 0x1a, 0x3, 0x2, 
    0x2, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x14, 0x17, 0x1c, 0x1f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AdvplParser::Initializer AdvplParser::_init;
