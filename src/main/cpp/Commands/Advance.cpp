/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Advance.h"
<<<<<<< HEAD

Advance::Advance() {
  Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void Advance::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Advance::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Advance::IsFinished() { return false; }

// Called once after isFinished returns true
void Advance::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
=======
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
  mPidPtr->SetSetpoint(mTargetDistance);
}

void Advance::Execute() 
{
  std::cout<<mTargetDistance - Robot::m_gps.GetDistance()<<std::endl;
  double wPower = mPidPtr->GetPIDOutput();
  Robot::m_drivetrain.TankDrive(-wPower, -wPower); 
}

bool Advance::IsFinished() 
{ 
  if (mPidPtr->OnTarget())
  {
    return true;
  }
  else return false; 
}

void Advance::End() {}

>>>>>>> 8c8f951b51f75809a0c4a114e652def46fb0ea94
void Advance::Interrupted() {}
