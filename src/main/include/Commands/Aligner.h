/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <commands/Command.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

class Aligner : public frc::Command {
 public:
  Aligner();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
  
  double angle;

 private:
  // nt::NetworkTableEntry x1Entry;
  // nt::NetworkTableEntry y1Entry; 
  // nt::NetworkTableEntry x2Entry;
  // nt::NetworkTableEntry y2Entry; 
  
};
