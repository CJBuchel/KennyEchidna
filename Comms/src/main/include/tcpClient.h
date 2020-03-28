#include "Client/client.h"

// Local files
#include "Comms.h"

class tcpClient {
 public:
  void StartClient(Comms *comms);
  void Update(Comms * comms);
 private:
  TCPComms::Client client;
};