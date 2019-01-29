/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Advance.h"
#include <iostream>

Advance::Advance(double iDistance, StraightPID *iPid, bool dynamicDistance) 
{
  Requires(&Robot::m_drivetrain);
  mPidPtr = iPid;
  mDistanceIncrement = iDistance;
  mDynamicDistance = dynamicDistance;
}

void Advance::Initialize() 
{
  mTargetDistance = mDistanceIncrement + Robot::m_gps.GetDistance();
  if(mPidPtr != nullptr) 
  {
    mPidPtr->SetSetpoint(mTargetDistance);
  }
}

void Advance::Execute() 
{
  double wPower = 0;

  if(mPidPtr != nullptr) 
  {
    wPower = mPidPtr->GetPIDOutput();
  }
  
  Robot::m_drivetrain.TankDrive(wPower, wPower); 
}

bool Advance::IsFinished() 
{ 
  if(mPidPtr != nullptr) 
  { 
    return mPidPtr->OnTarget();
  }
  else return false; 
}

void Advance::End() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}

void Advance::Interrupted() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}
