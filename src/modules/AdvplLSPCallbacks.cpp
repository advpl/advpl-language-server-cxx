#include "AdvplLSPCallbacks.hpp"
namespace advpl_ls {
void AdvplLSPCallbacks::onInitialize(std::string ID, JSONOutput &Out) {
  Out.writeMessage(
      R"({"jsonrpc":"2.0","id":)" + ID +
      R"(,"result":{"capabilities":{
          "textDocumentSync": 1,
          "documentFormattingProvider": true,
          "documentRangeFormattingProvider": true,
          "documentOnTypeFormattingProvider": {"firstTriggerCharacter":"}","moreTriggerCharacter":[]},
          "codeActionProvider": true,
          "completionProvider": {"resolveProvider": false, "triggerCharacters": [".",">",":"]},
          "definitionProvider": true
        }}})");
}

}  // namespace advpl_ls