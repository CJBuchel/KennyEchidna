#include "CommController.h"

void CommController::CommControl() {

  switch (comms.commState) {

    case CommState::ACTIVE:
      client.Update(&comms);
    break;

    case CommState::STARTING:
      webServer.ConnectServer(&comms);
      client.StartClient(&comms);
    break;

    case CommState::CONNECTING_UI:
      webServer.ConnectServer(&comms);
    break;

    case CommState::CONNECTING_TCP:
      client.StartClient(&comms);
    break;

    case CommState::UI_FAULT:
      printf("\n UI FAULT \n");
      printf("\n RECONNECTING \n");
      comms.SetCommState(CommState::CONNECTING_UI);
    break;

    case CommState::TCP_FAULT:
      printf("\n TCP FAULT \n");
      printf("\n RECONNECTING \n");
      comms.SetCommState(CommState::CONNECTING_TCP);
    break;
  }
}