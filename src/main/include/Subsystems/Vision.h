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

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

#include <SmartDashboard/SmartDashboard.h>

#include <math.h>

//class Robot;

class Vision : public frc::Subsystem {
 private:
  frc::CameraServer* mCameraServer;
  nt::NetworkTableInstance mNetworkTableInstanceInst; 

 public:
  Vision();

  void Initialization(); 
  void InitDefaultCommand() override;

  double GetContoursCentreX();
  double GetContourAngle();
  double GetLineAngle();
  void GetLine(double * oLine);

  bool FoundContour();
  bool FoundLine();

  void DisplayData(); 

  double GetAlpha();
  double GetBeta();

  double GetC1X();
  double GetC1Y();
  double GetC2X();
  double GetC2Y(); 

  double GetAX();
  double GetAY();
  double GetA1X();
  double GetA1Y();
  double GetA2X();
  double GetA2Y(); 

  double GetRightAngle();
  double GetLeftAngle();

  void ReadyData();

 private:
  bool foundContour;
  bool foundLine;

  double lastAngle;
  double mTheta;
};
