/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Aligner.h"
#include "Robot.h"
#include <SmartDashboard/SmartDashboard.h>

Aligner::Aligner(AlignmentPID * iPid) 
{
  Requires(&Robot::m_drivetrain);
  Requires(&Robot::m_vision);
  mPidPtr = iPid; 
}

// Called just before this Command runs the first time
void Aligner::Initialize() 
{
  mPidPtr->SetSetpoint(90);
}

// Called repeatedly when this Command is scheduled to run
void Aligner::Execute()
{
  double wPower = mPidPtr->GetPIDOutput();

  Robot::m_drivetrain.TankDrive(wPower,-wPower);
}

// Make this return true when this Command no longer needs to run execute()
bool Aligner::IsFinished() 
{
  return mPidPtr->OnTarget();

}

// Called once after isFinished returns true
void Aligner::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Aligner::Interrupted() {}
