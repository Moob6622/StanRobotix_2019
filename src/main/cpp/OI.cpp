/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "Robot.h"

#include <WPILib.h>

using namespace std; 

OI::OI() {
  // Process operator interface input here.
  joystick = new joystick(kJoystick1);
}

float OI::JoystickGetLeft() {
  return -joystick->GetRawAxis(3);
}

float OI::JoystickGetRight() {
  return -joystick->GetRawAxis(1);
}
