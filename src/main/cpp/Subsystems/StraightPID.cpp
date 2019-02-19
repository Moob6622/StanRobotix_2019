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

StraightPID::StraightPID(): PIDSubsystem("StraightPID", 1, 2, 1)
{
  SetOutputRange(-0.8,0.8);
  SetAbsoluteTolerance(1);
  Enable();
}

double StraightPID::ReturnPIDInput() 
{
  //std::cout<<"dist captee :"<<Robot::m_gps.GetPosition()<<std::endl;
  return Robot::m_gps.GetEncoderDistance();
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