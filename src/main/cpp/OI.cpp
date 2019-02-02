/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <RobotMap.h>
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/Aligner.h"
#include "Robot.h"

OI::OI() 
{
  // Process operator interface input here.

  mJoystickPtr = new Joystick(kJoystick1);

  mYButtonPtr = new JoystickButton(mJoystickPtr, kYButton);
  mAButtonPtr = new JoystickButton(mJoystickPtr, kAButton);
  mBButtonPtr = new JoystickButton(mJoystickPtr, kBButton);
  mXButtonPtr = new JoystickButton(mJoystickPtr, kXButton);
  
  m1ButtonPtr = new JoystickButton(mJoystickPtr, k1Button);
  m3ButtonPtr = new JoystickButton(mJoystickPtr, k3Button);
  m4ButtonPtr = new JoystickButton(mJoystickPtr, k4Button);

  //impossible de declarer le mButtonPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp


  Aligner* k1ButtonCommand = new Aligner(Robot::m_AnglePID, Robot::m_CentrePID);

  m1ButtonPtr->WhenPressed(k1ButtonCommand);

}

double OI::GetLeftJoystick() 
{
  return -mJoystickPtr->GetRawAxis(1); //signe << - >> devant la valeur des joysticks car 
                                       // leur orientation est inversee par rapport au tank drive
}

double OI::GetRightJoystick() 
{
  return -mJoystickPtr->GetRawAxis(0);
  //return -mJoystickPtr->GetRawAxis(3); //signe << - >> devant la valeur des joysticks car 
                                       //leur orientation est inversee par rapport au tank drive
}

double OI::GetActuatorInput()
{
  if (m4ButtonPtr->Get() && !m3ButtonPtr->Get())
  {
    return 1.0;
  }
  
  if (!m4ButtonPtr->Get() && m3ButtonPtr->Get())
  {
    return -1.0;
  }
  return 0.0;
}
