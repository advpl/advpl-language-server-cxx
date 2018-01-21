
// Generated from /home/vlopes/dev/github/advpl-language-server-cxx/antlr/grammar/Advpl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace advplParser {


class  AdvplLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, MINOR = 3, MAJOR = 4, EQUALS = 5, MINOREQUALS = 6, 
    MAJOREQUALS = 7, DOUBLEEQUAL = 8, DIF1 = 9, DIF2 = 10, DIF3 = 11, CONTIDO = 12, 
    PLUSPLUS = 13, MINUSMINUS = 14, PLUSEQUALS = 15, PLUS = 16, MINUS = 17, 
    MULT = 18, DIV = 19, POW = 20, PERC = 21, ARROBA = 22, ECOMERCIAL = 23, 
    BEGIN = 24, TRANSACTION = 25, SEQUENCE = 26, BEGIN_SQL = 27, ALIASACCESS = 28, 
    STEP = 29, TO = 30, TRUE = 31, FALSE = 32, NIL = 33, DEFINE = 34, UNDEFINE = 35, 
    IFDEF = 36, IFNDEF = 37, ELSEDEF = 38, ENDIFDEF = 39, FOR = 40, NEXT = 41, 
    WHILE = 42, DO = 43, ELSEIF = 44, IF = 45, ELSE = 46, ENDI = 47, ENDIF = 48, 
    ENDIF_DOT = 49, ENDDO = 50, ENDFOR = 51, END = 52, EXTENDED = 53, CASE = 54, 
    ENDCASE = 55, OTHERWISE = 56, EXIT = 57, LOOP = 58, LOCA = 59, LOCAL = 60, 
    PRIVATE = 61, PUBLIC = 62, STATIC = 63, USER = 64, WEB = 65, MAIN = 66, 
    FUNCTION = 67, FUNCTIO = 68, PROCEDURE = 69, SELF = 70, PROJECT = 71, 
    TEMPLATE = 72, AND = 73, OR = 74, NOT = 75, DEFAULT = 76, RETURN = 77, 
    ASSUME = 78, CLASS = 79, ENDCLASS = 80, METHOD = 81, DATA = 82, FROM = 83, 
    C_HIDDEN = 84, READONLY = 85, DESCRIPTION = 86, QSSTRUCT = 87, QSMETHOD = 88, 
    MODULE = 89, INIT = 90, AS = 91, OF = 92, PRODUCES = 93, OPTIONAL = 94, 
    REQUEST = 95, QUERYPARAM = 96, WSREST = 97, CAMELCASE = 98, PATHPARAM = 99, 
    GET = 100, POST = 101, PUT = 102, DELETE = 103, BYREF = 104, DATASET = 105, 
    PROCESS = 106, TITLE = 107, PERGUNTE = 108, PATH = 109, LPAREN = 110, 
    RPAREN = 111, LBRACK = 112, RBRACK = 113, INCLUDE = 114, COMMA = 115, 
    DOT = 116, ATTRIB_OPERATOR = 117, NUMBER = 118, IDENTIFIER = 119, COMMENT = 120, 
    LINE_COMMENT = 121, LINE_COMMENT_EE = 122, LINE_COMMENT_BIZARRO = 123, 
    LINE_COMMENT_BIZARRO2 = 124, LINE_COMMENT_BIZARRO3 = 125, LINE_COMMENT_BIZARRO4 = 126, 
    LINE_COMMENT_BIZARRO5 = 127, LINE_COMMENT_BIZARRO6 = 128, LINE_COMMENT_BIZARRO7 = 129, 
    ASTERICO = 130, STRING = 131, STRINGSIMPLE = 132, CRLF = 133, WS = 134, 
    INVALID_CHAR = 135, INVALID_CHAR_1 = 136, INVALID_CHAR_2 = 137, INVALID_CHAR_3 = 138, 
    INVALID_CHAR_4 = 139, INVALID_CHAR_14 = 140, INVALID_CHAR_17 = 141, 
    INVALID_CHAR_5 = 142, INVALID_CHAR_6 = 143, INVALID_CHAR_7 = 144, INVALID_CHAR_8 = 145, 
    INVALID_CHAR_9 = 146, INVALID_CHAR_10 = 147, INVALID_CHAR_11 = 148, 
    INVALID_CHAR_12 = 149, INVALID_CHAR_13 = 150, INVALID_CHAR_16 = 151, 
    INVALID_CHAR_18 = 152, INVALID_CHAR_19 = 153, ErrorChar = 154
  };

  AdvplLexer(antlr4::CharStream *input);
  ~AdvplLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace advplParser
