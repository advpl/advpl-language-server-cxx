#ifndef ADVPLLSPCALLBACKS_H
#define ADVPLLSPCALLBACKS_H
#include "ProtocolHandlers.hpp"
#include "AdvplLSPServer.hpp"
#include "json.hpp"
namespace advpl_ls {

class AdvplLSPCallbacks : public ProtocolCallbacks {
 public:
  AdvplLSPCallbacks(AdvplLSPServer &LangServer) : LangServer(LangServer) {}

  void onInitialize(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) override;
  void onShutdown(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) override;
  void onInitialized(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) override;
  void onExit(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) override;

  void onHover(boost::property_tree::ptree pt, std::string ID, JSONOutput &Out) override;

 private:
  AdvplLSPServer &LangServer;
};

}
#endif
