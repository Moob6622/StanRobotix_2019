/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Actuator.h"
#include <math.h>
#include <iostream>
#include "Commands/Actuate.h"

Actuator::Actuator() : Subsystem("Actuator") {
  actuator = new Servo{0};
}

void Actuator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Actuator::MoveDelta(double distance)
{
  std::cout<<"t'as cru! "<<distance<<std::endl;
  actuator->Set(std::max(std::min(actuator->Get()+distance, 0.999), 0.001));
}