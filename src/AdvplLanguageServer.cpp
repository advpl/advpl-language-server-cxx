#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>
#include "AdvplLSPCallbacks.hpp"

#pragma execution_character_set("utf-8")

int main(int argc, const char *argv[]) {
  advpl_ls::AdvplLSPServer server;
  advpl_ls::JSONOutput Out(std::cout, std::cerr);

  advpl_ls::JSONRPCDispatcher Dispatcher(std::make_unique<advpl_ls::Handler>(Out));
  advpl_ls::AdvplLSPCallbacks Callbacks(server);

  registerCallbackHandlers(Dispatcher, Out, Callbacks);
  server.run(std::cin, Out, Dispatcher);

  return 0;
}
