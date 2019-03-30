/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <Solenoid.h>

class HatchSystem : public frc::Subsystem {
 private:

  Solenoid * mPistonSolenoid0;
  Solenoid * mPistonSolenoid1;

  Solenoid * mVentouseSolenoid0;
  Solenoid * mVentouseSolenoid1;
  

 public:
  HatchSystem();
  Servo * mActuator;
  void InitDefaultCommand() override;

  //Actuator Methods
  void MoveDelta(double distance);
  bool ActuatorIsMax();
  bool ActuatorIsMin();

  //Piston methods
  void PistonToggle();
  void PistonRetract();

  //Ventouse methods
  void VentouseToggle();
  void VentouseTurnOff();


};
