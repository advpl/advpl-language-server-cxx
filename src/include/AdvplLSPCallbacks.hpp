#ifndef ADVPLLSPCALLBACKS_H
#define ADVPLLSPCALLBACKS_H
#include "ProtocolHandlers.hpp"
#include "AdvplLSPServer.hpp"
namespace advpl_ls 
{
    class AdvplLSPCallbacks : public ProtocolCallbacks 
    {
    public:
        AdvplLSPCallbacks (AdvplLSPServer &LangServer): LangServer(LangServer) {}
        
        void onInitialize(std::string ID, JSONOutput &Out)  override;


    private:
        AdvplLSPServer &LangServer;
    };


}
#endif
