#pragma once
enum class CommState {
  ACTIVE = 0,
  STARTING,
  CONNECTING_UI,
  CONNECTING_TCP,
  UI_FAULT,
  TCP_FAULT,
  STOPPED
};

class Comms {
 public:
  void SetCommState(CommState state) {
    commState = state;
  }

  CommState GetState() {
    return commState;
  }
  
  // State of comms
  CommState commState{ CommState::STARTING };
};