/*#include "DebugProtocolServer.h"
#include "DebugProtocolCallbacks.h"
#include "ProtocolHandlers.h"
int main()
{
	vscode_debug::DebugProtocolServer server;

	vscode_debug::JSONOutput Out(std::cout, std::cerr);
	vscode_debug::JSONRPCDispatcher Dispatcher(std::make_unique<vscode_debug::Handler>(Out));	
	vscode_debug::DebugProtocolCallbacks Callbacks(server);
	vscode_debug::regiterCallbackHandlers(Dispatcher,Out,Callbacks);
	server.run(std::cin,Out,Dispatcher);
	return 0;
}
*/

#include <iostream>
#include <fcntl.h>
#include "antlr4-runtime.h"
#include "AdvplLexer.h"
#include "AdvplParser.h"
#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp> 
#include "AdvplLSPCallbacks.hpp"
#include "AdvplLSPServer.hpp"
#include "ProtocolHandlers.hpp"

#pragma execution_character_set("utf-8")
using namespace advplParser;
using namespace antlr4;

using namespace advpl_ls;
int main(int argc, const char * argv[]) {
	init_log();
	ANTLRInputStream input("teste");
	AdvplLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	AdvplParser parser(&tokens);
	tree::ParseTree *tree = parser.sources();

	std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";

	std::cout << "Teste";
	AdvplLSPServer server;

	JSONOutput Out(std::cout, std::cerr);
	JSONRPCDispatcher Dispatcher(std::make_unique<Handler>(Out));	
	AdvplLSPCallbacks Callbacks(server);
    registerCallbackHandlers(Dispatcher,Out,Callbacks);
	server.run(std::cin,Out,Dispatcher);
 

  return 0;
}
/*

int main()
{
	int result = _setmode( _fileno( stdout ), _O_BINARY );  
	AdvplLSPServer server;
boost::this_thread::sleep_for(boost::chrono::milliseconds(5000));
	JSONOutput Out(std::cout, std::cerr);
	JSONRPCDispatcher Dispatcher(std::make_unique<Handler>(Out));	
	AdvplLSPCallbacks Callbacks(server);
	regiterCallbackHandlers(Dispatcher,Out,Callbacks);
	server.run(std::cin,Out,Dispatcher);
	return 0;
}
*/