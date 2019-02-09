/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/CordeMoteur.h"
#include <Commands/CordeMove.h>

CordeMoteur::CordeMoteur() : Subsystem("CordeMoteur") {
  moteur = new Spark(SparkMotor);
}

void CordeMoteur::InitDefaultCommand() {
  SetDefaultCommand(new CordeMove());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void CordeMoteur::Set(double value)
{
  moteur->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
