/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/HatchPiston.h"
#include <RobotMap.h>

HatchPiston::HatchPiston() : Subsystem("HatchPiston") {
  solenoid0 = new Solenoid(kHatchPiston0);
  //^^^
  solenoid1 = new Solenoid(kHatchPiston1);
  //^^^

  solenoid0->Set(true);
  solenoid1->Set(false);
  //ventouse est desactivee quand ? est true et ? est false
}

void HatchPiston::InitDefaultCommand() {
}

void HatchPiston::Toggle()
{
  solenoid0->Set(!solenoid0->Get());
  solenoid1->Set(!solenoid1->Get());
}

void HatchPiston::Retract()
{
  // valeurs true/false inconnues
  solenoid0->Set(true);
  solenoid1->Set(false);
}