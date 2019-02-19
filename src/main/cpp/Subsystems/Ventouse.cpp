/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Ventouse.h"


Ventouse::Ventouse() : Subsystem("Ventouse") {
  solenoid0 = new Solenoid(0);
  //^^^Valve de pression
  solenoid1 = new Solenoid(1);
  //^^^Solenoid de ventouses
  
  solenoid0->Set(true);
  solenoid1->Set(false);
  //ventouse est desactivee quand 0 est true et 1 est false
}

void Ventouse::InitDefaultCommand() {
  
}

void Ventouse::Toggle()
{
  solenoid0->Set(!solenoid0->Get());
  solenoid1->Set(!solenoid1->Get());
}

void Ventouse::TurnOff()
{
  solenoid0->Set(true);
  solenoid1->Set(false);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
