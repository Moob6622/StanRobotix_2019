/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Aligner.h"
#include "Robot.h"

Aligner::Aligner() {
  Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void Aligner::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Aligner::Execute() {

  auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = inst.GetTable("GRIP/myLinesReport");

  angle = table->GetEntry("angle").GetDouble(0);

  Robot::m_drivetrain.TankDrive(0,0); //si angle>90 tourner a gauche (moteur droit), si angle<90 tourner droite (moteur gauche)

}

// Make this return true when this Command no longer needs to run execute()
bool Aligner::IsFinished() { return false; }

// Called once after isFinished returns true
void Aligner::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Aligner::Interrupted() {}
