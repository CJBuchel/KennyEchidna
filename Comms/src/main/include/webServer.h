#include <iostream>
#include <string>
#include <thread>

// Local files
#include "Comms.h"
#include "mongoose/mongoose.h"

class WebServer {
 public:
  void ConnectServer(Comms *comms);
};