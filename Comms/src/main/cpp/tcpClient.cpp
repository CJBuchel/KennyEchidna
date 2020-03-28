#include "tcpClient.h"

void tcpClient::StartClient(Comms *comms) {
  client.SetIP("127.0.0.1");
  client.SetPort(13200);
  client.Start();
}

void tcpClient::Update(Comms *comms) {
  /** This is where we get items */
}