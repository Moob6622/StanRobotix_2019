/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <RobotMap.h>

#include "Commands/TankDrive_Joystick.h"

#include <SpeedController.h>
#include <SpeedControllerGroup.h>

#include "Drive/DifferentialDrive.h"
#include "Commands/Subsystem.h"

#include <AnalogGyro.h>
#include <PWMTalonSRX.h>


class DriveTrain : public frc::Subsystem 
{
 private:

  PWMTalonSRX motorL1{kMotorLeft1};
	PWMTalonSRX motorL2{kMotorLeft2};
	PWMTalonSRX motorR1{kMotorRight1};
	PWMTalonSRX motorR2{kMotorRight2};
  

	frc::SpeedControllerGroup leftSide{motorL1, motorL2};
	frc::SpeedControllerGroup rightSide{motorR1, motorR2};

  DifferentialDrive Drive{leftSide, rightSide};

  frc::AnalogGyro gyro{kGyro};

  TankDrive_Joystick * mDefaultDrivePtr;

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();

  void ResetSensors(); 
  void InitDefaultCommand() override;
  void TankDrive(double iLeft, double iRight);
  double GetAngle();
};
