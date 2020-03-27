#include "CommController.h"
void CommController::CommControl() {
  switch (comms.commState) {
    case CommState::CONNECTING:
      webServer.ConnectServer(&comms);
    break;

    case CommState::CON_FAULT:
      printf("\n FAULT \n");
      printf("\n RECONNECTING \n");
      comms.SetCommState(CommState::CONNECTING);
    break;
  }
}