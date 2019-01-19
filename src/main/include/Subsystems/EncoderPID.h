/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <RobotMap.h>
#include "Encoder.h"
#include "Commands/Subsystem.h"
#include "Commands/PIDSubsystem.h"
#include <SpeedController.h>
#include <SpeedControllerGroup.h>
#include "Drive/DifferentialDrive.h"
#include "ctre/Phoenix.h"

class EncoderPID : public frc::PIDSubsystem {
 public:
  EncoderPID();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;
  double getPe();
  double GetIe();
  double GetDe();
  double GetEncR();
  double GetEncL();
  
  private:
  Encoder *encR = new Encoder(0,1,false);
  Encoder *encL = new Encoder(2,3,false);

  WPI_TalonSRX motorL1{kMotorLeft1};
	WPI_TalonSRX motorL2{kMotorLeft2};
	WPI_TalonSRX motorR1{kMotorRight1};
	WPI_TalonSRX motorR2{kMotorRight2};

  frc::SpeedControllerGroup leftSide{motorL1, motorL2};
	frc::SpeedControllerGroup rightSide{motorR1, motorR2};

  DifferentialDrive Drive{leftSide, rightSide};
};