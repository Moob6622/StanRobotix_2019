/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\DriveTrain.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain"), mDefaultDrivePtr(nullptr), mGyroPtr(nullptr), mAcceleroPtr(nullptr) 
{
  mDefaultDrivePtr = new TankDrive_Joystick();
  mGyroPtr = new AnalogGyro(kGyro);
  mAcceleroPtr = new frc::BuiltInAccelerometer();
}

void DriveTrain::ResetSensors() 
{
  mGyroPtr->Reset();
  mGyroPtr->Calibrate();
}

void DriveTrain::InitDefaultCommand() 
{
  SetDefaultCommand(mDefaultDrivePtr);
}

void DriveTrain::TankDrive(double iLeft, double iRight) 
{
  Drive.TankDrive(iLeft, iRight);
}

double DriveTrain::GetAngle() 
{
  return mGyroPtr->GetAngle();
}

double DriveTrain::GetXAcceleration() 
{
  return mAcceleroPtr->GetX();
}

double DriveTrain::GetYAcceleration() 
{
  return mAcceleroPtr->GetY();
}

double DriveTrain::GetZAcceleration() 
{
  return mAcceleroPtr->GetZ();
}

double DriveTrain::GetAcceleration()
{
  return sqrt(pow(mAcceleroPtr->GetX(),2)   //formule pour calculer
            + pow(mAcceleroPtr->GetY(),2)   // lacceleration totale
            + pow(mAcceleroPtr->GetZ(),2));
          
}






// Put methods for controlling this subsystem
// here. Call these from Commands.
