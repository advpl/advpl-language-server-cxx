#include "ProtocolHandlers.hpp"

namespace advpl_ls {
struct InitializeHandler : Handler {
  InitializeHandler(JSONOutput &Output, ProtocolCallbacks &Callbacks)
      : Handler(Output), Callbacks(Callbacks) {}
  void handleMethod(boost::property_tree::ptree Params,
                    std::string ID) override {
    Callbacks.onInitialize(ID, Output);
  }
  /* void handleMethod(llvm::yaml::MappingNode *Params, StringRef ID) override {
     Callbacks.onInitialize(ID, Output);
   }*/

 private:
  ProtocolCallbacks &Callbacks;
};

void registerCallbackHandlers(JSONRPCDispatcher &Dispatcher, JSONOutput &Out,
                              ProtocolCallbacks &Callbacks) {
  Dispatcher.registerHandler(
      "initialize", std::make_unique<InitializeHandler>(Out, Callbacks));
}
}  // namespace advpl_ls