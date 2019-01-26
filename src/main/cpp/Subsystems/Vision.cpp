/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\Vision.h"

Vision::Vision() : Subsystem("Vision") {}

void Vision::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Vision::Initialization()
{
  
  //m_cameraServer->GetInstance()->StartAutomaticCapture("USBCamera");
  m_cameraServer->GetInstance()->AddAxisCamera("Axis Cam",kCameraIP);
  m_cameraServer->GetInstance()->PutVideo("Camera MS",480,360);

  mInst = nt::NetworkTableInstance::GetDefault();
}

double * Vision::GetLine()
{
  double oLine[5];
  //auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = mInst.GetTable("GRIP/myLinesReport");

  for(int i = 0; i < sizeof( table->GetEntry("y1").GetDoubleArray(0) ) ; i++ )
  {
    if(table->GetEntry("y1").GetDoubleArray(0)[i]<kLineDetectionVerticalThreshold
      && table->GetEntry("y2").GetDoubleArray(0)[i]<kLineDetectionVerticalThreshold)
    {
      oLine[0] = table->GetEntry("x1").GetDoubleArray(0)[i];
      oLine[1] = table->GetEntry("y1").GetDoubleArray(0)[i];
      oLine[2] = table->GetEntry("x2").GetDoubleArray(0)[i];
      oLine[3] = table->GetEntry("y2").GetDoubleArray(0)[i];
      oLine[4] = table->GetEntry("angle").GetDoubleArray(90)[i];
      break;
    }
  }

  return oLine;
}

double Vision::GetLineAngle()
{
  return GetLine()[4];
}


void Vision::DisplayData() 
{
  double * coordLine = GetLine();

  SmartDashboard::PutNumber("x1", coordLine[0]);
  SmartDashboard::PutNumber("y1", coordLine[1]);
  SmartDashboard::PutNumber("x2", coordLine[2]);
  SmartDashboard::PutNumber("y2", coordLine[3]);
  SmartDashboard::PutNumber("angle", coordLine[4]);
}