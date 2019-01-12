/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <RobotMap.h>
#include "Commands/Turn.h"

OI::OI() 
{
  // Process operator interface input here.
  
  mJoystickPtr = new Joystick(kJoystick1);
  mLeftTriggerPtr = new JoystickButton(mJoystickPtr, kLeftTrigger);

  //impossible de declarer le mLeftTriggerCommandPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp
  
  Turn * mLeftTriggerCommandPtr = new Turn(180); 

  mLeftTriggerPtr->WhenPressed(mLeftTriggerCommandPtr);

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
