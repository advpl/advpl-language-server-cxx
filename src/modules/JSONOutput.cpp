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

/*
 * ShowMessage Notification
 *
 * method: ‘window/showMessage’
 * params: ShowMessageParams
 *
 * The show message notification is sent from a server to a client to ask the client to display a particular message
 * in the user interface.
 *
 * https://microsoft.github.io/language-server-protocol/specification#window_showMessage
 *
 */
void JSONOutput::showMessage(int status, const std::string &Message) {
  this->writeMessage(
      nlohmann::json({
                         {"jsonrpc", "2.0"},
                         {"method", "window/showMessage"},
                         {"params", {
                             {"type", status},
                             {"message", Message}
                         }}
                     })
  );
}
void JSONOutput::showErrorMessage(const std::string &Message) { this->showMessage(1, Message); }
void JSONOutput::showWarningMessage(const std::string &Message) { this->showMessage(2, Message); }
void JSONOutput::showInfoMessage(const std::string &Message) { this->showMessage(3, Message); }
void JSONOutput::showLogMessage(const std::string &Message) { this->showMessage(4, Message); }

}  // namespace advpl_ls