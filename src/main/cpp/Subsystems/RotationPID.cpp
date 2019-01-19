/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\RotationPID.h"

#include "LiveWindow\LiveWindow.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Robot.h>

RotationPID::RotationPID()
    : PIDSubsystem("RotationPID", 1, 1, 1) 
{
  SetOutputRange(-0.3,0.3);
  SetAbsoluteTolerance(1);
  Enable();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
}



double RotationPID::ReturnPIDInput() {
  // Return your input value for the PID loop
  // e.g. a sensor, like a potentiometer:
  // yourPot->SetAverageVoltage() / kYourMaxVoltage;
  return Robot::m_gps.GetAngle();
}

void RotationPID::UsePIDOutput(double output) 
{
  Robot::m_drivetrain.SetPIDOutput(output);
  // Use output to drive your system, like a motor
  // e.g. yourMotor->Set(output);
}

void RotationPID::InitDefaultCommand() 
{

}