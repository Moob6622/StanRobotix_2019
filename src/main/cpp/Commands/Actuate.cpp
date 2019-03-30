/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Actuate.h"
#include "Robot.h"
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>

Actuate::Actuate() 
{
  Requires(&Robot::m_hatchsystem);
}

// Called just before this Command runs the first time
void Actuate::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void Actuate::Execute() 
{
  Robot::m_hatchsystem.SetActuator(Robot::m_oi.GetActuatorInput());
  SmartDashboard::PutNumber("input actuator", Robot::m_oi.GetActuatorInput());
  std::cout<<"left: "<<Robot::m_hatchsystem.IsSwitchSetL()<<std::endl;
  std::cout<<"right: "<<Robot::m_hatchsystem.IsSwitchSetR()<<std::endl;
  std::cout<<"running"<<std::endl;
  SmartDashboard::PutBoolean("left switch", Robot::m_hatchsystem.IsSwitchSetL());
  SmartDashboard::PutBoolean("right switch", Robot::m_hatchsystem.IsSwitchSetR());
}

// Make this return true when this Command no longer needs to run execute()
bool Actuate::IsFinished() { return false; }

// Called once after isFinished returns true
void Actuate::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Actuate::Interrupted() {}
