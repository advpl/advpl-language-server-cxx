#define BOOST_TEST_MAIN teste1
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include "AdvplLSPCallbacks.hpp"
#include "json.hpp"

void callbackFromJson(const nlohmann::json &j,
                      advpl_ls::AdvplLSPServer &server,
                      advpl_ls::JSONOutput &Out,
                      advpl_ls::JSONRPCDispatcher &Dispatcher,
                      advpl_ls::AdvplLSPCallbacks &Callbacks) {
  std::istringstream is(Out.createJsonRpc(j));

  registerCallbackHandlers(Dispatcher, Out, Callbacks);
  server.run(is, Out, Dispatcher);
}

BOOST_AUTO_TEST_CASE(la) {
  std::string stdout, stderr;
  advpl_ls::AdvplLSPServer server;
  std::ostringstream stdos, erros;
  advpl_ls::JSONOutput Out(stdos, erros);

  advpl_ls::JSONRPCDispatcher Dispatcher(std::make_unique<advpl_ls::Handler>(Out));
  advpl_ls::AdvplLSPCallbacks Callbacks(server);

  // Method initialize
  stdos.str("");
  erros.str("");
  stdos.clear();
  erros.clear();
  callbackFromJson(nlohmann::json({
                                      {"jsonrpc", "2.0"},
                                      {"id", 0},
                                      {"method", "initialize"},
                                      {"params", {
                                          {"processId", 20092},
                                          {"rootPath", nullptr},
                                          {"rootUri", nullptr},
                                          {"capabilities", {
                                              {"workspace", {
                                                  {"applyEdit", true},
                                                  {"didChangeConfiguration", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"didChangeWatchedFiles", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"symbol", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"executeCommand", {
                                                      {"dynamicRegistration", true}
                                                  }}
                                              }},
                                              {"textDocument", {
                                                  {"synchronization", {
                                                      {"dynamicRegistration", true},
                                                      {"willSave", true},
                                                      {"willSaveWaitUntil", true},
                                                      {"didSave", true}
                                                  }},
                                                  {"completion", {
                                                      {"dynamicRegistration", true},
                                                      {"completionItem", {
                                                          {"snippetSupport", true},
                                                          {"commitCharactersSupport", true}
                                                      }}
                                                  }},
                                                  {"hover", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"signatureHelp", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"definition", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"references", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"documentHighlight", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"documentSymbol", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"codeAction", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"codeLens", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"formatting", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"rangeFormatting", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"onTypeFormatting", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"rename", {
                                                      {"dynamicRegistration", true}
                                                  }},
                                                  {"documentLink", {
                                                      {"dynamicRegistration", true}
                                                  }}
                                              }}
                                          }},
                                          {"trace", "off"}
                                      }}
                                  }), server, Out, Dispatcher, Callbacks);
  stdout = stdos.str();
  stderr = erros.str();
  BOOST_CHECK_EQUAL(stderr.empty(), true);

  // Method shutdown
  stdos.str("");
  erros.str("");
  stdos.clear();
  erros.clear();
  callbackFromJson(nlohmann::json({
                                      {"jsonrpc", "2.0"},
                                      {"id", 1},
                                      {"method", "shutdown"},
                                      {"params", nullptr}
                                  }), server, Out, Dispatcher, Callbacks);
  stdout = stdos.str();
  stderr = erros.str();
  BOOST_CHECK_EQUAL(stderr.empty(), true);

  // Method initialized
  stdos.str("");
  erros.str("");
  stdos.clear();
  erros.clear();
  callbackFromJson(nlohmann::json({
                                      {"jsonrpc", "2.0"},
                                      {"id", 1},
                                      {"method", "initialized"},
                                      {"params", nullptr}
                                  }), server, Out, Dispatcher, Callbacks);
  stdout = stdos.str();
  stderr = erros.str();
  BOOST_CHECK_EQUAL(stderr.empty(), true);

  // Method exit
  stdos.str("");
  erros.str("");
  stdos.clear();
  erros.clear();
  callbackFromJson(nlohmann::json({
                                      {"jsonrpc", "2.0"},
                                      {"id", 1},
                                      {"method", "exit"},
                                      {"params", nullptr}
                                  }), server, Out, Dispatcher, Callbacks);
  stdout = stdos.str();
  stderr = erros.str();
  BOOST_CHECK_EQUAL(stderr.empty(), true);
}
