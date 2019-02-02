/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/Subsystem.h"
#include <CameraServer.h>
#include "RobotMap.h"
//#include "Robot.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

#include <SmartDashboard/SmartDashboard.h>

//class Robot;

class Vision : public frc::Subsystem {
 private:
  frc::CameraServer* m_cameraServer;
  nt::NetworkTableInstance mNetworkTableInstanceInst; 

 public:
  Vision();

  void Initialization(); 

  void GetLine(double * oLine);

  bool FoundContour();
  bool FoundLine();

  double GetLineAngle();
  double GetContoursCentreX();

  double AlignerRobotLigne(const double iTableau[5]); //Aligne le robot avec une ligne

  void DisplayData(); 

  void InitDefaultCommand() override;

  private:
  bool foundContour;
  double lastAngle;
  bool foundLine;
};
