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

struct InitializedHandler : Handler {
  InitializedHandler(JSONOutput &Output, ProtocolCallbacks &Callbacks)
      : Handler(Output), Callbacks(Callbacks) {}
  void handleMethod(boost::property_tree::ptree pt,
                    std::string ID) override {
    Callbacks.onInitialized(pt, ID, Output);
  }

 private:
  ProtocolCallbacks &Callbacks;
};

struct ExitHandler : Handler {
  ExitHandler(JSONOutput &Output, ProtocolCallbacks &Callbacks)
      : Handler(Output), Callbacks(Callbacks) {}
  void handleMethod(boost::property_tree::ptree pt,
                    std::string ID) override {
    Callbacks.onExit(pt, ID, Output);
  }

 private:
  ProtocolCallbacks &Callbacks;
};

struct HoverHandler : Handler {
  HoverHandler(JSONOutput &Output, ProtocolCallbacks &Callbacks)
      : Handler(Output), Callbacks(Callbacks) {}
  void handleMethod(boost::property_tree::ptree pt,
                    std::string ID) override {
    Callbacks.onHover(pt, ID, Output);
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
  Dispatcher.registerHandler(
      "initialized", std::make_unique<InitializedHandler>(Out, Callbacks));
  Dispatcher.registerHandler(
      "exit", std::make_unique<ExitHandler>(Out, Callbacks));
  Dispatcher.registerHandler(
      "textDocument/hover", std::make_unique<HoverHandler>(Out, Callbacks));

  // TODO $/cancelRequest https://microsoft.github.io/language-server-protocol/specification#cancelRequest
  // TODO window/showMessageRequest’ https://microsoft.github.io/language-server-protocol/specification#window_showMessageRequest
  // TODO window/logMessage https://microsoft.github.io/language-server-protocol/specification#window_logMessage
  // TODO telemetry/event https://microsoft.github.io/language-server-protocol/specification#telemetry_e
  // TODO client/registerCapability https://microsoft.github.io/language-server-protocol/specification#client_registerCapability
  // TODO client/unregisterCapability https://microsoft.github.io/language-server-protocol/specification#client_unregisterCapability
}

}
