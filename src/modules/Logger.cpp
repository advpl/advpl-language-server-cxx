#include "Logger.hpp"
using namespace advpl_ls;
EmptyLogger &EmptyLogger::getInstance() {
    static EmptyLogger Logger;
    return Logger;
  }
  
  void EmptyLogger::log(const std::string Message) {}
  
  FileLogger &FileLogger::getInstance() {
    static FileLogger Logger;
    return Logger;
  }
  
  void FileLogger::log(const std::string Message) {
    log_info(Message);
  }
  