#include "AdvplLSPCallbacks.hpp"

#define advpl_ls_default_header_response(i, c) "{\"jsonrpc\":\"2.0\",\"id\":"+i+",\"result\":{"+c+"}"

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
      advpl_ls_default_header_response(
          ID,
          R"("capabilities": {
 "textDocumentSync": 1,
 "documentFormattingProvider": true,
 "documentRangeFormattingProvider": true,
 "documentOnTypeFormattingProvider": {
  "firstTriggerCharacter":"}",
  "moreTriggerCharacter":[]
 },
 "codeActionProvider": true,
 "completionProvider": {
  "resolveProvider": false,
  "triggerCharacters": [".",">",":"]
 },
 "definitionProvider": true
})"
      )
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
      advpl_ls_default_header_response(
          ID,
          ""
      )
  );
}

}
