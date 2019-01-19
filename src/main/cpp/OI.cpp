/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <RobotMap.h>
#include "Commands/Turn.h"
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>

OI::OI() 
{
  // Process operator interface input here.
  
  mJoystickPtr = new Joystick(kJoystick1);

  mYButtonPtr = new JoystickButton(mJoystickPtr, kYButton);
  mAButtonPtr = new JoystickButton(mJoystickPtr, kAButton);
  mBButtonPtr = new JoystickButton(mJoystickPtr, kBButton);
  mXButtonPtr = new JoystickButton(mJoystickPtr, kXButton);

  //impossible de declarer le mButtonPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp
  
  Turn * mYButtonCommandPtr = new Turn(SmartDashboard::GetNumber("PIDSetpoint", 15), &Robot::mPid);

  mYButtonPtr->WhenPressed(mYButtonCommandPtr);

}

double OI::GetLeftJoystick() 
{
  return -mJoystickPtr->GetRawAxis(1); //signe << - >> devant la valeur des joysticks car 
                                   // leur orientation est inversee par rapport au tank drive
}

double OI::GetRightJoystick() 
{
  return -mJoystickPtr->GetRawAxis(3); //signe << - >> devant la valeur des joysticks car 
                                   //leur orientation est inversee par rapport au tank drive
}
