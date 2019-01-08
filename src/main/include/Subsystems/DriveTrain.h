/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "RobotMap.h"

//includes un peu foireux, a changer
#include <SpeedController.h>
#include <SpeedControllerGroup.h>
#include <Spark.h>
// !!!

class DriveTrain : public frc::Subsystem {
 private:

  //cest faux mais cest vrai

  frc::Spark motorL1{kMotorLeft1};
	frc::Spark motorL2{kMotorLeft2};
	frc::Spark motorR1{kMotorRight1};
	frc::Spark motorR2{kMotorRight2};

	frc::SpeedControllerGroup leftSide{motorL1, motorL2};
	frc::SpeedControllerGroup rightSide{motorR1, motorR2};

  DifferentialDrive Drive{leftSide, rightSide};

  //


  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void InitDefaultCommand() override;
  void f_TankDrive(double left, double right);
};
