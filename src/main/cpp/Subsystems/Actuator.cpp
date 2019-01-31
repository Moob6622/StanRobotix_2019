/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Actuator.h"
#include <math.h>
#include <iostream>
#include <RobotMap.h>
#include <Commands/Actuate.h>

double Actuator::lastSetPoint;

Actuator::Actuator() : Subsystem("Actuator"), mActuator(nullptr) 
{
  mActuator = new Servo{kActuator};
  
  lastSetPoint = 0;
  mActuator->Set(0);
  realActuatorGet = 0;

}

void Actuator::InitDefaultCommand() 
{
  SetDefaultCommand(new Actuate());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Actuator::MoveDelta(double iDistance)
{
  if(mActuator != nullptr)
  {

    // //assure que la valeur soit comprise entre le minimum et le maximum
    if (fabs(mActuator->Get() - realActuatorGet) <= 0.01 && iDistance != 0)
    {
      double wDistance = std::max(std::min(realActuatorGet + iDistance * 0.01, 1.0), 0.0);
      std::cout<<"Stacking command "<<iDistance<<std::endl;
      mActuator->Set(wDistance);
    }
  realActuatorGet = std::max(std::min(realActuatorGet + iDistance * 0.008, 1.0), 0.0);
  }
}