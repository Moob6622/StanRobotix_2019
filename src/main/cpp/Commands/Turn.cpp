/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Turn.h"

#include <iostream>

Turn::Turn(double iAngle) 
{
  Requires(&Robot::m_drivetrain);
  mAngleIncrement = iAngle;
}

void Turn::Initialize() 
{
  mTargetAngle = fmod(mAngleIncrement + Robot::m_gps.GetAngle(), 360);
}

void Turn::Execute() 
{
  if(mTargetAngle < 0)
  {
    Robot::m_drivetrain.TankDrive(-0.2,0.2);
  }
  else 
  {
    Robot::m_drivetrain.TankDrive(0.2,-0.2);
  }
  std::cout<< (abs(Robot::m_gps.GetAngle()) - abs(mTargetAngle)) << std::endl;
}

bool Turn::IsFinished() 
{ 
  if(abs(Robot::m_gps.GetAngle() - mTargetAngle) < kGyroSensitivity) 
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
