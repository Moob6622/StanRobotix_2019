/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Actuator.h"
#include <iostream>
#include <Commands/MoveServo.h>

Actuator::Actuator() : Subsystem("Actuator") {}

void Actuator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Actuator::Set(double value){
  mActuator.Set(value);
  std::cout<<"ha "<<mActuator.Get()<<std::endl;
}


void Actuator::SetAngle(double value){
  mActuator.SetAngle(value);
  std::cout<<"ha "<<mActuator.GetAngle()<<std::endl;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
