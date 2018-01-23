#include "AdvplLSPCallbacks.hpp"

namespace advpl_ls {

/*
 * Initialize Request
 *
 * method: ‘initialize’
 * params: InitializeParams
 * result: InitializeResult
 *
 * The initialize request is sent as the first request from the client to the server.
 *
 * https://microsoft.github.io/language-server-protocol/specification#initialize
 *
 */
void AdvplLSPCallbacks::onInitialize(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) {
  std::string processId = pt.get<std::string>("params.processId");
  std::string rootPath = pt.get<std::string>("params.rootPath");
  std::string rootUri = pt.get<std::string>("params.rootUri");
  //initializationOptions
  //capabilities
  std::string trace = pt.get<std::string>("params.trace");

  Out.writeMessage(
      nlohmann::json({
                         {"jsonrpc", "2.0"},
                         {"id", ID},
                         {"result", {
                             {"capabilities", {
                                 {"textDocumentSync", 1},
                                 {"documentFormattingProvider", true},
                                 {"documentRangeFormattingProvider", true},
                                 {"documentOnTypeFormattingProvider", {
                                     {"firstTriggerCharacter", "}"},
                                     {"moreTriggerCharacter", nlohmann::json::array()}
                                 }},
                                 {"codeActionProvider", true},
                                 {"completionProvider", {
                                     {"resolveProvider", false},
                                     {"triggerCharacters", nlohmann::json::array({".", ">", ":"})}
                                 }}
                             }},
                             {"definitionProvider", true}
                         }}

                     })
  );
}

/*
 * Shutdown Request
 *
 * method: ‘shutdown’
 * params: void
 * result: null
 *
 * The shutdown request is sent from the client to the server. It asks the server to shut down, but to not exit
 * (otherwise the response might not be delivered correctly to the client). There is a separate exit notification
 * that asks the server to exit.
 *
 * https://microsoft.github.io/language-server-protocol/specification#shutdown
 *
 */
void AdvplLSPCallbacks::onShutdown(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) {
  Out.writeMessage(
      nlohmann::json({
                         {"jsonrpc", "2.0"},
                         {"id", ID},
                         {"result", nullptr}
                     })
  );
}

}
