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


HatchSystem::HatchSystem() : Subsystem("HatchSystem")
{
  mActuator = new Servo{kActuator};
  mActuator->Set(0.25);
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


}

void HatchSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new Actuate());
}

//Actuator methods
void HatchSystem::MoveDelta(double iDistance)
{
  if (mActuator != nullptr)
  {
    if(iDistance != 0)
    {
      double wDistance = std::max(std::min(mActuator->Get() + iDistance * 0.002, 0.8), 0.2);
      mActuator->Set(wDistance);
    }
  }
}

//Piston methods
void HatchSystem::PistonToggle()
{
  std::cout<<"piston"<<std::endl;
  mPistonSolenoid0->Set(!mPistonSolenoid0->Get());
  mPistonSolenoid1->Set(!mPistonSolenoid1->Get());
  SmartDashboard::PutBoolean("Piston", mPistonSolenoid1->Get());
}

void HatchSystem::PistonRetract()
{
  mPistonSolenoid0->Set(false);
  mPistonSolenoid1->Set(true);
}

//Ventous methods
void HatchSystem::VentouseToggle()
{
  std::cout<<"ventouse"<<std::endl;
  mVentouseSolenoid0->Set(!mVentouseSolenoid0->Get());
  mVentouseSolenoid1->Set(!mVentouseSolenoid1->Get());
  SmartDashboard::PutBoolean("Ventouse", mVentouseSolenoid0->Get());
}

void HatchSystem::VentouseTurnOff()
{
  mVentouseSolenoid0->Set(true);
  mVentouseSolenoid1->Set(false);
}