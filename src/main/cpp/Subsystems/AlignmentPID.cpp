/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/AlignmentPID.h"

#include <livewindow/LiveWindow.h>
#include <smartdashboard/SmartDashboard.h>
#include "Robot.h"

AlignmentPID::AlignmentPID()
    : PIDSubsystem("AlignmentPID", 1.0, 0.0, 0.0) 
{
  SetOutputRange(-0.3,0.3);
  Enable();
}

double AlignmentPID::ReturnPIDInput() 
{
  return Robot::m_vision.GetLineAngle();
}

void AlignmentPID::UsePIDOutput(double output) 
{
  mPIDOutput = output;
} 

void AlignmentPID::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double AlignmentPID::GetPIDOutput() 
{
  return mPIDOutput; 
}
