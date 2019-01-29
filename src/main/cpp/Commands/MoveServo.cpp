/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/MoveServo.h"
#include "Robot.h"

MoveServo::MoveServo(double value) 
{
  moveValue = value;
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveServo::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void MoveServo::Execute() 
{
  Robot::m_Actuator.Set(moveValue);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveServo::IsFinished() { return true; }

// Called once after isFinished returns true
void MoveServo::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveServo::Interrupted() {}
