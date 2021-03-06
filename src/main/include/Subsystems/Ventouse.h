/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Solenoid.h>

class Ventouse : public frc::Subsystem {
 public:
  Ventouse();
  void InitDefaultCommand() override;
  void Toggle();
  void TurnOff();

 private:
  Solenoid* solenoid0;
  Solenoid* solenoid1;
};
