//rover state machine
#include "drive_state.h"


DriveState  roverDrive = START;

void StateSetup() 
{

    
  
}

void StateLoop() {
  
  if(roverDrive == START)
  {
    TransitionState(FORWARD);
  }
  
  if(roverDrive == FORWARD)
  {
    if(distance < 15)
    {
      TransitionState(STOP);
    }
  }
  
  if(roverDrive == STOP)
  {
    if(distance > 30)
    {
      TransitionState(FORWARD);
    }
  }
  
}

void TransitionState(DriveState newState)
{
  if(newState == roverDrive)
    return;
  
  Log("**new transition**");  
    
  if(newState == FORWARD)
  {
    Log("new state is FORWARD");  

    DriveForward();
  }
  
  if(newState == STOP)
  {
    Log("new state is STOP");
    
    DriveStop();
  }
  
  roverDrive = newState;
}



