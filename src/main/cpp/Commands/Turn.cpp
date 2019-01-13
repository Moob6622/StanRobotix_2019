/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Turn.h"

Turn::Turn(double iAngle) 
{
  Requires(&Robot::m_drivetrain);
  mTargetAngle = iAngle + Robot::m_drivetrain.GetAngle(); 
}

void Turn::Initialize() 
{

}

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

bool Turn::IsFinished() 
{ 
<<<<<<< HEAD
  if(true) 
=======
  if(abs(Robot::m_drivetrain.GetAngle() - mTargetAngle) < kGyroSensitivity) 
>>>>>>> 90ba242ecf42380d385ce8b2e4df0f29bbd12592
  {
    return true;
  }
  else {return false;} 
}

void Turn::End() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}

void Turn::Interrupted() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}
