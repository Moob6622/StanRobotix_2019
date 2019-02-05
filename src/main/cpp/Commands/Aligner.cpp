/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Aligner.h"
#include "Robot.h"
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>

Aligner::Aligner(AnglePID * iAPid, CentrePID * iCPid) 
{
  Requires(&Robot::m_drivetrain);
  Requires(&Robot::m_vision);
  mAPidPtr = iAPid;
  mCPidPtr = iCPid;
}

// Called just before this Command runs the first time
void Aligner::Initialize() 
{
  aligned = false;
  mAPidPtr = new AnglePID();
  mCPidPtr = new CentrePID();
  mAPidPtr->SetSetpoint(90);
  mCPidPtr->SetSetpoint(axisCamWidth/2);
}

// Called repeatedly when this Command is scheduled to run
void Aligner::Execute()
{
  std::cout<<Robot::m_gps.GetDistCaptDist()<<std::endl;
  double xCentre = Robot::m_vision.GetContoursCentreX();
  
  if (fabs(xCentre-axisCamWidth/2) <10 && xCentre!=-1)
  {
    aligned = true;
  }
  if (aligned)
  {
    if (Robot::m_gps.GetDistCaptDist()>5)
    {
      Robot::m_drivetrain.TankDrive(0.4,0.4);
    }
    else
    {
      Robot::m_drivetrain.TankDrive(0.0,0.0);
    }
  }
  else
  {
    Robot::m_drivetrain.TankDrive(Robot::m_oi.GetLeftJoystick(), Robot::m_oi.GetRightJoystick());
  }
}

// Make this return true when this Command no longer needs to run execute()
bool Aligner::IsFinished() 
{

  //return mAPidPtr->OnTarget() || Robot::m_oi.GetActuatorInput()==1;
  //return mCPidPtr->OnTarget() || Robot::m_oi.GetActuatorInput()==1;
  return Robot::m_oi.GetActuatorInput()==1;
}

// Called once after isFinished returns true
void Aligner::End()
{
  std::cout<<"ALIGNER FIIIIIIIIIIIIIIIIIIIIIIINNNNNIIIIII"<<std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Aligner::Interrupted() {}
