#pragma once
enum class CommState {
  ACTIVE = 0,
  CONNECTING,
  CON_FAULT,
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
  CommState commState{ CommState::CONNECTING };
};