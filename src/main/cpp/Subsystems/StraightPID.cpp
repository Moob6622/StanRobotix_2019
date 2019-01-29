/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\StraightPID.h"

#include "LiveWindow\LiveWindow.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Robot.h>
#include <iostream>

StraightPID::StraightPID(): PIDSubsystem("StraightPID", 0.1, 0.0, 0.1)
{
  SetOutputRange(-0.3,0.3);
  SetAbsoluteTolerance(2);
  Enable();
}

double StraightPID::ReturnPIDInput() 
{
  return Robot::m_gps.GetDistance();
}

void StraightPID::UsePIDOutput(double output) 
{
  mPIDOutput = output; 
}

void StraightPID::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double StraightPID::GetPIDOutput() 
{
  return mPIDOutput;
}
