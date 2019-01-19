/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Turn.h"

#include <iostream>

Turn::Turn(double iAngle, RotationPID* ipid)
{
  Requires(&Robot::m_drivetrain);
  mAngleIncrement = iAngle;
  mPidPtr = ipid;
}

void Turn::Initialize() 
{
  mTargetAngle = mAngleIncrement + Robot::m_gps.GetAngle();
  mPidPtr->SetSetpoint(mTargetAngle);
}

void Turn::Execute() 
{
  double wPower = Robot::m_drivetrain.GetPIDOutput();

  if (mAngleIncrement > 0) 
  {
    Robot::m_drivetrain.TankDrive(wPower, -wPower);
  }
  else 
  {
    Robot::m_drivetrain.TankDrive(-wPower, wPower);
  }
}

bool Turn::IsFinished() 
{ 
  if (mPidPtr->OnTarget())
  {
    return true;
  }
  else return false;
}

void Turn::End() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}

void Turn::Interrupted() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}
