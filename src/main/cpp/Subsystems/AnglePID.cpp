/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/AnglePID.h"

#include <livewindow/LiveWindow.h>
#include <smartdashboard/SmartDashboard.h>
#include "Robot.h"
#include <iostream>

AnglePID::AnglePID()
    : PIDSubsystem("AnglePID", 1.0, 1.0, 1.0) 
{
  SetOutputRange(-0.4,0.4);
  SetAbsoluteTolerance(0.1);
  Enable();
  //mPIDOutput = 0.0;
}

double AnglePID::ReturnPIDInput() 
{
  return Robot::m_vision.GetLineAngle();
}

void AnglePID::UsePIDOutput(double output) 
{
  mPIDOutput = output;
} 

void AnglePID::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double AnglePID::GetPIDOutput() 
{
  if (Robot::m_vision.FoundLine())
  {
  return mPIDOutput;
  }
  else
  {
    return 0;
  }
}
