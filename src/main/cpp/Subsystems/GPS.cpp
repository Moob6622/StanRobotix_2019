/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\GPS.h"

GPS::GPS() : frc::Subsystem("GPS"), mGyroPtr(nullptr), mAcceleroPtr(nullptr)
{
  mGyroPtr = new ADXRS450_Gyro();
  mAcceleroPtr = new frc::BuiltInAccelerometer();

  mRightEncoder = new Encoder(0,1,false);
  mLeftEncoder = new Encoder(2,3,false);

  mDistCaptPtr = new AnalogInput(0);
}

void GPS::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void GPS::ResetSensors() 
{
  mGyroPtr->Calibrate();
}

double GPS::GetAngle() 
{
  return mGyroPtr->GetAngle();
}

double GPS::GetXAcceleration() 
{
  return mAcceleroPtr->GetX();
}

double GPS::GetYAcceleration() 
{
  return mAcceleroPtr->GetY();
}

double GPS::GetZAcceleration() 
{
  return mAcceleroPtr->GetZ();
}

double GPS::GetAcceleration()
{
  return sqrt(pow(mAcceleroPtr->GetX(),2)   //formule pour calculer
            + pow(mAcceleroPtr->GetY(),2)   // lacceleration totale
            + pow(mAcceleroPtr->GetZ(),2));
}

double GPS::GetEncoderDistance()
{
  // Dans quelle unite ?
  return mLeftEncoder->GetRaw();
}

double GPS::GetCapteurDistance()
{
  // Dans quelle unite ?
  return mDistCaptPtr->GetVoltage();
}
