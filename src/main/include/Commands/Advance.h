/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

<<<<<<< HEAD
#include <frc/commands/Command.h>

class Advance : public frc::Command {
 public:
  Advance();
=======
#include <Commands/Command.h>
#include "Robot.h"

class Advance : public frc::Command {
 public:
  Advance(double iDistance, StraightPID *iPid, bool dynamicDistance = false);
>>>>>>> dec28e4c938ba7fe61bb13a7be40f0f4bf893979
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
<<<<<<< HEAD
=======
 private:
  double mDistanceIncrement;
  double mTargetDistance;
  bool mDynamicDistance;
  StraightPID * mPidPtr;
>>>>>>> dec28e4c938ba7fe61bb13a7be40f0f4bf893979
};
