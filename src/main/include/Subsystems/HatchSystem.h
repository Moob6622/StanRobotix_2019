/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <Solenoid.h>
#include <DigitalInput.h>
#include <Commands\Actuate.h>

class HatchSystem : public frc::Subsystem {
 private:

  Solenoid * mPistonSolenoid0;
  Solenoid * mPistonSolenoid1;

  Solenoid * mVentouseSolenoid0;
  Solenoid * mVentouseSolenoid1;

  Spark * mActuator;

  DigitalInput * mLimitSwitchR;
  DigitalInput * mLimitSwitchL;

  Actuate * mDefaultCommand;
  


 public:
  HatchSystem();
  
  void InitDefaultCommand() override;

  //Actuator Methods
  void SetActuator(double motorInput);
  bool ActuatorIsMax();
  bool ActuatorIsMin();

  //Piston methods
  void PistonToggle();
  void PistonRetract();

  //Ventouse methods
  void VentouseToggle();
  void VentouseTurnOff();

  //Limit Switch methods;
  bool IsSwitchSetR();
  bool IsSwitchSetL();


};
