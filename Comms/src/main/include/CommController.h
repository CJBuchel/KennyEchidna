#include "webServer.h"
#include "tcpClient.h"

class CommController {
 public:
  void CommControl();
 private:
  // Main instances
  Comms comms;
  WebServer webServer;
  tcpClient client;
};