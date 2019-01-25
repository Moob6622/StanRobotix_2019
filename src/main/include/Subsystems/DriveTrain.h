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
#include "ctre/Phoenix.h"

class DriveTrain : public frc::Subsystem 
{
 private:

  WPI_TalonSRX motorL1{kMotorLeft1};
	WPI_TalonSRX motorL2{kMotorLeft2};
	WPI_TalonSRX motorR1{kMotorRight1};
	WPI_TalonSRX motorR2{kMotorRight2};

	frc::SpeedControllerGroup leftSide{motorL1, motorL2};
	frc::SpeedControllerGroup rightSide{motorR1, motorR2};

  DifferentialDrive Drive{leftSide, rightSide};

  TankDrive_Joystick * mDefaultDrivePtr;

  double mPIDOutput;        

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void InitDefaultCommand() override;
  void TankDrive(double iLeft, double iRight);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> dec28e4c938ba7fe61bb13a7be40f0f4bf893979

  void SetPIDOutput(double iPID);
  double GetPIDOutput();

<<<<<<< HEAD
=======
>>>>>>> 8c8f951b51f75809a0c4a114e652def46fb0ea94
=======
>>>>>>> dec28e4c938ba7fe61bb13a7be40f0f4bf893979
};
