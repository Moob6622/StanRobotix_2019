/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/CordeMoteur.h"
#include <Commands/CordeMove.h>
#include <iostream>

CordeMoteur::CordeMoteur() : Subsystem("CordeMoteur") {
  moteur = new Spark(SparkMotor);
  moteur->SetInverted(false);
  cordeProg = 0;
  //cordeMin = 0;
  cordeMin = -900;
  //cordeMax = 324;
  cordeMax = 900;
  // 0 correspond a la corde retractee, et ... a la corde etendue
}

void CordeMoteur::InitDefaultCommand() {
  SetDefaultCommand(new CordeMove());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void CordeMoteur::Set(double value)
{
  if((value == -1 && cordeProg <= cordeMax) || (value == 1 && cordeProg >= cordeMin))
  {
  moteur->Set(value);
  cordeProg -= value;
  }
  else
  {
    moteur->Set(0.0);
  }
  std::cout<<cordeProg<<std::endl;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
