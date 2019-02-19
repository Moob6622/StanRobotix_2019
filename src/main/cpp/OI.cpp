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
#include <math.h>
#include <Commands/ToggleVentouse.h>
#include "Robot.h"
#include "Commands/RobotWiggle.h"

OI::OI() 
{
  // Process operator interface input here.

  mJoystickPtr = new Joystick(kJoystick);

  mYButtonPtr = new JoystickButton(mJoystickPtr, kYButton);
  mAButtonPtr = new JoystickButton(mJoystickPtr, kAButton);
  mBButtonPtr = new JoystickButton(mJoystickPtr, kBButton);
  mXButtonPtr = new JoystickButton(mJoystickPtr, kXButton);
  
  m1ButtonPtr = new JoystickButton(mJoystickPtr, k1Button);
  m2ButtonPtr = new JoystickButton(mJoystickPtr, k2Button);
  m3ButtonPtr = new JoystickButton(mJoystickPtr, k3Button);
  m4ButtonPtr = new JoystickButton(mJoystickPtr, k4Button);

  m3ButtonPtr = new JoystickButton(mJoystickPtr, k3Button);
  m4ButtonPtr = new JoystickButton(mJoystickPtr, k4Button);
  m1ButtonPtr = new JoystickButton(mJoystickPtr, k1Button);

  m1ButtonPtr->WhenPressed(new RobotWiggle());

  //impossible de declarer le mButtonPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp


  PrepHatchAlign* k1ButtonCommand = new PrepHatchAlign();
  ToggleVentouse* k2ButtonCommand = new ToggleVentouse();

  m1ButtonPtr->WhenPressed(k1ButtonCommand);
  m2ButtonPtr->WhenPressed(k2ButtonCommand);
}

double OI::GetLeftJoystick() 
{
  return -mJoystickPtr->GetRawAxis(kJoystickLeft);
}

double OI::GetRightJoystick() 
{
  return -mJoystickPtr->GetRawAxis(kJoystickRight);
  //signe << - >> devant la valeur des joysticks car 
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

double OI::GetM3(){
  if (m3ButtonPtr->Get())
  {
    return -1.0;
  }
  else{
    return 0.0;
  }
}

double OI::GetM4(){
  if (m4ButtonPtr->Get())
  {
    return 1.0;
  }
  else{
    return 0.0;
  }
}
