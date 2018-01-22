#ifndef ADVPLLSPSERVER_H
#define ADVPLLSPSERVER_H

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/utility/string_ref.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "JSONRPCDispatcher.hpp"
#include "JSONOutput.hpp"

namespace advpl_ls {
class AdvplLSPServer {

 public:
  void run(std::istream &input, JSONOutput &Out, JSONRPCDispatcher &Dispatcher);
};
}
#endif