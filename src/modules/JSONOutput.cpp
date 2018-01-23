#include "JSONOutput.hpp"
namespace advpl_ls {

void JSONOutput::writeMessage(const std::string &Message) {
  /*llvm::SmallString<128> Storage;
  StringRef M = Message.toStringRef(Storage);

  std::lock_guard<std::mutex> Guard(StreamMutex);
  // Log without headers.
  Logs << "--> " << M << '\n';
  Logs.flush();
*/
  // Emit message with header.
  // Outs << "Content-Length: " << M.size() << "\r\n\r\n" << M;
  Outs << this->createJsonRpc(Message);
  Outs.flush();
}

void JSONOutput::writeMessage(const nlohmann::json &j) {
  this->writeMessage(j.dump());
}

std::string JSONOutput::createJsonRpc(const std::string &Message) {
  return "Content-Length: " + std::to_string(Message.size()) + "\r\n\r\n" + Message;
}

std::string JSONOutput::createJsonRpc(const nlohmann::json &j) {
  return this->createJsonRpc(j.dump());
}

void JSONOutput::log(const std::string Message) {
  std::lock_guard<std::mutex> Guard(StreamMutex);
  Logs << Message;
  Logs.flush();
}

}  // namespace advpl_ls