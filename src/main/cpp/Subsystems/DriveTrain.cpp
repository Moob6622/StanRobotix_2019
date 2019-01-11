/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\DriveTrain.h"
#include "Commands\TankDrive_Joystick.h"
DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {}

void DriveTrain::InitDefaultCommand() {
  SetDefaultCommand(new TankDrive_Joystick());
}

void DriveTrain::f_TankDrive(double left, double right) {
  Drive.TankDrive(left, right);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
