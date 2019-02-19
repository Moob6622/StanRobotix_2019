/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/Subsystem.h"
#include "Commands/PIDSubsystem.h"

class CentrePID : public frc::PIDSubsystem {
 public:
  CentrePID();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;
  double GetPIDOutput();
 private:
  double mPIDOutput = 0.0;
};
