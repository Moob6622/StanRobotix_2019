/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Aligner.h"
#include "Robot.h"
#include <SmartDashboard/SmartDashboard.h>

Aligner::Aligner() {
  Requires(&Robot::m_drivetrain);
  Requires(&Robot::m_vision);
}

// Called just before this Command runs the first time
void Aligner::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Aligner::Execute() {

 
  double wAngle = Robot::m_vision.GetLine()[4];

  if (wAngle<90)
  {
    Robot::m_drivetrain.TankDrive(0,0.4); //si angle>90 tourner a gauche (moteur droit), si angle<90 tourner droite (moteur gauche)
  }
  else if(wAngle==90)
  {
    Robot::m_drivetrain.TankDrive(0.4,0.4);
  }
  else
  {
    Robot::m_drivetrain.TankDrive(0.4,0);
  }

}

// Make this return true when this Command no longer needs to run execute()
bool Aligner::IsFinished() 
{
  //// IL FAUT METTRE UNE TOUCHE SUR LE JOYSTICK QUI ARRETE LA COMMANDE!
  return false; 
}

// Called once after isFinished returns true
void Aligner::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Aligner::Interrupted() {}
