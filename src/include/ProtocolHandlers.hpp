#ifndef PROTOCOL_HANDLERS_H
#define PROTOCOL_HANDLERS_H
#include "JSONOutput.hpp"
#include "Handler.hpp"
#include "JSONRPCDispatcher.hpp"
#include <string>
namespace advpl_ls {

class ProtocolCallbacks {
 public:
  virtual ~ProtocolCallbacks() = default;

  virtual void onInitialize(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) = 0;
  virtual void onShutdown(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) = 0;
  virtual void onInitialized(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) = 0;
  virtual void onExit(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) = 0;
};

void registerCallbackHandlers(JSONRPCDispatcher &Dispatcher, JSONOutput &Out,
                              ProtocolCallbacks &Callbacks);

}
#endif