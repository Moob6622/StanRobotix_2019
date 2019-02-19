/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "Networktables/NetworkTable.h"
#include "Networktables/NetworkTableEntry.h"
#include "Networktables/NetworkTableInstance.h"

#include "Subsystems/AnglePID.h"
#include "Subsystems/CentrePID.h"

class Aligner : public frc::Command {
 public:
  Aligner(AnglePID * iAPid, CentrePID * iCPid);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  AnglePID * mAPidPtr;
  CentrePID * mCPidPtr;
  bool aligned;
  
};
