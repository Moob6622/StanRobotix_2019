/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/HatchSystem.h"
#include <math.h>
#include <iostream>
#include <RobotMap.h>
#include <Commands/Actuate.h>
#include <SmartDashboard/SmartDashboard.h>


HatchSystem::HatchSystem() : Subsystem("HatchSystem"), mDefaultCommand(nullptr)
{
  mActuator = new Spark(kActuator);
  ///////////////////////////////////////////////////
  mPistonSolenoid0 = new Solenoid(0,kHatchPiston0);
  mPistonSolenoid1 = new Solenoid(0,kHatchPiston1);

  mPistonSolenoid0->Set(false);
  mPistonSolenoid1->Set(true);
  //////////////////////////////////////////////////
  mVentouseSolenoid0 = new Solenoid(0,kVentouse0);
  mVentouseSolenoid1 = new Solenoid(0,kVentouse1);

  mVentouseSolenoid0->Set(true);
  mVentouseSolenoid1->Set(false);
  //////////////////////////////////////////////////

  mLimitSwitchR = new DigitalInput(kLimitSwitchR);
  mLimitSwitchL = new DigitalInput(kLimitSwitchL);
  std::cout<<"gd"<<std::endl;

  mDefaultCommand =new Actuate();


}

void HatchSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new Actuate());
}

//Actuator methods
void HatchSystem::SetActuator(double actuatorInput)
{
  mActuator->Set(0.5*actuatorInput);

  SmartDashboard::PutNumber("actuator input", actuatorInput);
}

bool HatchSystem::ActuatorIsMax()
{
  return (mActuator->GetPosition() == 1);
}

bool HatchSystem::ActuatorIsMin()
{
  return (mActuator->GetPosition() == -1);
}

//Piston methods
void HatchSystem::PistonToggle()
{
  mPistonSolenoid0->Set(!mPistonSolenoid0->Get());
  mPistonSolenoid1->Set(!mPistonSolenoid1->Get());
  SmartDashboard::PutBoolean("Piston", mPistonSolenoid1->Get());
}

void HatchSystem::PistonRetract()
{
  mPistonSolenoid0->Set(false);
  mPistonSolenoid1->Set(true);
}

//Ventouse methods
void HatchSystem::VentouseToggle()
{
  mVentouseSolenoid0->Set(!mVentouseSolenoid0->Get());
  mVentouseSolenoid1->Set(!mVentouseSolenoid1->Get());
  SmartDashboard::PutBoolean("Ventouse", mVentouseSolenoid0->Get());
}

void HatchSystem::VentouseTurnOff()
{
  mVentouseSolenoid0->Set(true);
  mVentouseSolenoid1->Set(false);
}

//Limit Switch methods

bool HatchSystem::IsSwitchSetR()
{
  std::cout<<"subsystem"<<mLimitSwitchR->Get()<<std::endl;
  SmartDashboard::PutBoolean("RightSwitch", mLimitSwitchR->Get());
  return mLimitSwitchR->Get();
}

bool HatchSystem::IsSwitchSetL()
{
  std::cout<<"subsystem"<<mLimitSwitchL<<std::endl;
  SmartDashboard::PutBoolean("LeftSwitch", mLimitSwitchL->Get());
  return mLimitSwitchL->Get();
}