/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <RobotMap.h>
#include "Commands/Actuate.h"
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/PrepareActuate.h>

OI::OI() 
{
  // Process operator interface input here.

  mJoystickPtr = new Joystick(kJoystick1);

  mYButtonPtr = new JoystickButton(mJoystickPtr, kYButton);
  mAButtonPtr = new JoystickButton(mJoystickPtr, kAButton);
  mBButtonPtr = new JoystickButton(mJoystickPtr, 3);
  mXButtonPtr = new JoystickButton(mJoystickPtr, 4);

  //impossible de declarer le mButtonPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp


  PrepareActuate * mBButtonCommandPtr = new PrepareActuate(-0.01);
  PrepareActuate * mXButtonCommandPtr = new PrepareActuate(0.01);

  mBButtonPtr->WhileHeld(mBButtonCommandPtr);
  mXButtonPtr->WhileHeld(mXButtonCommandPtr);

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
