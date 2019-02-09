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
  Robot::m_AnglePID = mAPidPtr;
  Robot::m_CentrePID = mCPidPtr;
  mAPidPtr->SetSetpoint(90);
  mCPidPtr->SetSetpoint(axisCamWidth/2);
}

// Called repeatedly when this Command is scheduled to run
void Aligner::Execute()
{
  
  //double wPower = mAPidPtr->GetPIDOutput();
  //Robot::m_drivetrain.TankDrive(-wPower,wPower);
  // double wPower = mCPidPtr->GetPIDOutput();
  // Robot::m_drivetrain.TankDrive(-wPower,wPower);
  // std::cout.precision(17);
  // std::cout<<"Execute() apres TANKDRIVE : "<<std::fixed<<mCPidPtr->GetPIDOutput()<<std::endl;
  double angleForme = Robot::m_vision.GetContourAngle();
  if (Robot::m_vision.FoundContour())
  {
    std::cout<<"angle forme : "<<angleForme<<std::endl;
  }
  
  // double xCentre = Robot::m_vision.GetContoursCentreX();
  // std::cout<<xCentre<<std::endl;
  // if (fabs(xCentre-axisCamWidth/2) <10 && xCentre !=-1)
  // {
  //   aligned = true;
  // }
  //   Robot::m_drivetrain.TankDrive(Robot::m_oi.GetLeftJoystick(), Robot::m_oi.GetRightJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool Aligner::IsFinished() 
{

  return true;
  //return aligned;
}

// Called once after isFinished returns true
void Aligner::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Aligner::Interrupted() {}
