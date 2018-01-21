#include "JSONRPCDispatcher.hpp"
namespace advpl_ls {
void JSONRPCDispatcher::registerHandler(std::string method,
                                        std::unique_ptr<Handler> H) {
  // assert(!Handlers.count(Method) && "Handler already registered!");
  Handlers[method] = std::move(H);
}
static void callHandler(std::unique_ptr<Handler> &handle,
                        boost::property_tree::ptree pt, std::string id) {
  handle->handleMethod(pt, id);
}

bool JSONRPCDispatcher::call(boost::string_ref Content) {
  std::stringstream ss;
  ss << Content;

  boost::property_tree::ptree pt;
  boost::property_tree::read_json(ss, pt);

  std::string method = pt.get<std::string>("method");
  std::string id;
  if (pt.count("id") > 0) {
    id = pt.get<std::string>("id");
  }
  MapHandler::iterator it = Handlers.find(method);
  // std::unordered_map<std::string, std::unique_ptr<Handler> > ::iterator it;
  it = Handlers.find(method);

  if (it != Handlers.end()) {
    callHandler(it->second, pt, id);
  }

  return true;
}

}  // namespace advpl_ls