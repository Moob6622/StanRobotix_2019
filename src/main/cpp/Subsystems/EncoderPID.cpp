/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/EncoderPID.h"

#include "LiveWindow/LiveWindow.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Robot.h>

EncoderPID::EncoderPID()
    : PIDSubsystem("EncoderPID", 1.0, 0.01, 0.01) 
  {
    SetOutputRange(-1, 1);
    SetPercentTolerance(0.005);
    Enable();  
  // Use these to get going:
  // SetSetpoint() -  Sets where the PID controller should move the system
  //                  to
  // Enable() - Enables the PID controller.
}

//

double EncoderPID::ReturnPIDInput() {

  // Return your input value for the PID loop
  // e.g. a sensor, like a potentiometer:
  // yourPot->SetAverageVoltage() / kYourMaxVoltage;
  return (encL->GetRaw());
}

void EncoderPID::UsePIDOutput(double output) {
  // Use output to drive your system, like a motor
  // e.g. yourMotor->Set(output);
  frc::SpeedControllerGroup rightSide.Set(output);
  frc::SpeedControllerGroup leftSide.Set(output);
}

void EncoderPID::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  encL->reset();
}