#include "ProtocolHandlers.hpp"

namespace advpl_ls {

struct InitializeHandler : Handler {
  InitializeHandler(JSONOutput &Output, ProtocolCallbacks &Callbacks)
      : Handler(Output), Callbacks(Callbacks) {}
  void handleMethod(boost::property_tree::ptree pt,
                    std::string ID) override {
    Callbacks.onInitialize(pt, ID, Output);
  }

 private:
  ProtocolCallbacks &Callbacks;
};

struct ShutdownHandler : Handler {
  ShutdownHandler(JSONOutput &Output, ProtocolCallbacks &Callbacks)
      : Handler(Output), Callbacks(Callbacks) {}
  void handleMethod(boost::property_tree::ptree pt,
                    std::string ID) override {
    Callbacks.onShutdown(pt, ID, Output);
  }

 private:
  ProtocolCallbacks &Callbacks;
};

void registerCallbackHandlers(JSONRPCDispatcher &Dispatcher, JSONOutput &Out,
                              ProtocolCallbacks &Callbacks) {
  Dispatcher.registerHandler(
      "initialize", std::make_unique<InitializeHandler>(Out, Callbacks));
  Dispatcher.registerHandler(
      "shutdown", std::make_unique<ShutdownHandler>(Out, Callbacks));

  // TODO initialized https://microsoft.github.io/language-server-protocol/specification#initialized
  // TODO exit https://microsoft.github.io/language-server-protocol/specification#exit
  // TODO $/cancelRequest https://microsoft.github.io/language-server-protocol/specification#cancelRequest
}

}
