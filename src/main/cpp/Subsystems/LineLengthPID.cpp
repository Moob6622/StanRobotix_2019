/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/LineLengthPID.h"

#include <livewindow/LiveWindow.h>
#include <smartdashboard/SmartDashboard.h>
#include "Robot.h"
#include <iostream>

LineLengthPID::LineLengthPID()
    : PIDSubsystem("LineLengthPID", 1.0, 1.0, 1.0) 
{
  SetOutputRange(-0.4,0.4);
  SetAbsoluteTolerance(0.1);
  Enable();
  //mPIDOutput = 0.0;
}

double LineLengthPID::ReturnPIDInput() 
{
  return Robot::m_vision.GetLineAngle();
}

void LineLengthPID::UsePIDOutput(double output) 
{
  mPIDOutput = output;
} 

void LineLengthPID::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double LineLengthPID::GetPIDOutput() 
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
