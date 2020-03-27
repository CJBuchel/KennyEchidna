#include "webServer.h"

class CommController {
 public:
  void CommControl();
 private:
  // Main instances
  Comms comms;
  WebServer webServer;
};