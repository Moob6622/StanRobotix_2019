/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/PrepareActuate.h"

PrepareActuate::PrepareActuate(double distance) {
  mDistance = distance;
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void PrepareActuate::Initialize() {
  frc::Scheduler::GetInstance();
}

// Called repeatedly when this Command is scheduled to run
void PrepareActuate::Execute() {
  Actuate * mActuate = new Actuate(mDistance);
  if (!(mActuate->isRunning)){
    frc::Scheduler::AddCommand(mActuate);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool PrepareActuate::IsFinished() { return false; }

// Called once after isFinished returns true
void PrepareActuate::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrepareActuate::Interrupted() {}
