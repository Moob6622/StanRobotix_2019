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
#include "Commands/PrepHatchAlign.h"
#include "Commands/Aligner.h"
#include "Commands/Advance.h"
#include "Robot.h"
#include <math.h>

OI::OI() 
{
  // Process operator interface input here.

  mJoystickPtr = new Joystick(kJoystick1);

  mYButtonPtr = new JoystickButton(mJoystickPtr, kYButton);
  mAButtonPtr = new JoystickButton(mJoystickPtr, kAButton);
  mBButtonPtr = new JoystickButton(mJoystickPtr, kBButton);
  mXButtonPtr = new JoystickButton(mJoystickPtr, kXButton);
  
  m1ButtonPtr = new JoystickButton(mJoystickPtr, k1Button);
  m2ButtonPtr = new JoystickButton(mJoystickPtr, k2Button);
  m3ButtonPtr = new JoystickButton(mJoystickPtr, k3Button);
  m4ButtonPtr = new JoystickButton(mJoystickPtr, k4Button);

  //impossible de declarer le mButtonPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp


  PrepHatchAlign* k1ButtonCommand = new PrepHatchAlign();

  m1ButtonPtr->WhenPressed(k1ButtonCommand);
  m2ButtonPtr->WhenPressed(new Advance(10, Robot::m_StraightPID, false));
  //m2ButtonPtr->WhenPressed(new Turn(30.0, Robot::m_RotationPID));
}

double OI::GetLeftJoystick() 
{
  return -mJoystickPtr->GetRawAxis(1); 
  double leftValue = -mJoystickPtr->GetRawAxis(1);
  
  if(leftValue > 0.85)
  {
    leftValue = 1;
    return leftValue;
  }

   return pow(leftValue, 3)*0.85+0.15*leftValue - 0.15; //signe << - >> devant la valeur des joysticks car 
                                       // leur orientation est inversee par rapport au tank drive
}

double OI::GetRightJoystick() 
{
  return -mJoystickPtr->GetRawAxis(5); 
  double rightValue = -mJoystickPtr->GetRawAxis(5);
  
  if(rightValue > 0.85)
  {
    rightValue = 1;
    return rightValue;
  }

  return pow(rightValue, 3)*0.85+0.15*rightValue - 0.15;
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
