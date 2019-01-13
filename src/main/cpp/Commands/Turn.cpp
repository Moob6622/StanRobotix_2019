/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Turn.h"

Turn::Turn(double iAngle) 
{
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_drivetrain);
  mTargetAngle = iAngle + Robot::m_drivetrain.GetAngle(); 
}

// Called just before this Command runs the first time
void Turn::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() 
{
  if(Robot::m_drivetrain.GetAngle() - mTargetAngle > 0) //choisit le sens de rotation
  {                                                     //selon langle 
    Robot::m_drivetrain.TankDrive(1,-1);
  }
  else
  {
    Robot::m_drivetrain.TankDrive(-1,1);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished() 
{ 
  if() 
  {
    return true;
  }
  else {return false;} 
}

// Called once after isFinished returns true
void Turn::End() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}
