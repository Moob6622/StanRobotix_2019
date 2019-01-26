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
  
  // m_cameraServer->GetInstance()->StartAutomaticCapture();
  m_cameraServer->GetInstance()->AddAxisCamera("Axis Cam",kCameraIP);
  m_cameraServer->GetInstance()->PutVideo("Camera MS",480,360);

  mInst = nt::NetworkTableInstance::GetDefault();
}

double * Vision::GetLine()
{
  double oLine[4];
  //auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = mInst.GetTable("GRIP/myLinesReport");

  oLine[0] = table->GetEntry("x1").GetDoubleArray(0)[0];
  oLine[1] = table->GetEntry("y1").GetDoubleArray(0)[0];
  oLine[2] = table->GetEntry("x2").GetDoubleArray(0)[0];
  oLine[3] = table->GetEntry("y2").GetDoubleArray(0)[0];

  return oLine;
  
}

void Vision::DisplayData() 
{
  double wX1 = GetLine()[0];
  double wY1 = GetLine()[1];
  double wX2 = GetLine()[2];
  double wY2 = GetLine()[3];

  SmartDashboard::PutNumber("x1", wX1);
  SmartDashboard::PutNumber("y1", wY1);
  SmartDashboard::PutNumber("x2", wX2);
  SmartDashboard::PutNumber("y2", wY2);
}