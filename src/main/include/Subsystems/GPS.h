/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <RobotMap.h>

#include <AnalogGyro.h>
#include <BuiltInAccelerometer.h>

#include <Math.h>

class GPS : public frc::Subsystem 
{
 private:
  
  frc::AnalogGyro * mGyroPtr;
  frc::BuiltInAccelerometer * mAcceleroPtr;

 public:
  GPS();
  void InitDefaultCommand() override;
  void ResetSensors(); 
  
  double GetAngle();

  double GetXAcceleration();
  double GetYAcceleration();
  double GetZAcceleration();
  double GetAcceleration();
};
