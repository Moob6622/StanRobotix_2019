/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "OI.h"
#include "Subsystems/GPS.h"
#include "Subsystems/Actuator.h"
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>
#include "Preferences.h"

#include <solenoid.h>
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Vision.h"
#include <SmartDashboard/SendableChooser.h>
#include <CameraServer.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include <cscore_oo.h>
#include "Timer.h"
#include <Subsystems/AlignmentPID.h>

class Robot : public frc::TimedRobot 
{
 public:
  static GPS m_gps; 
  static OI m_oi;
  static Actuator m_actuator;
  static double PIDVal;
  static double PIDP;
  static double PIDI;
  static double PIDD;


  // double oldTime;
  // double deltaTime;
  // double countdown;

  static DriveTrain m_drivetrain;
  static OI m_oi;
  static Vision m_vision;

  static AlignmentPID* m_AlignPID;
  //static grip::DetectLines detectLines;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  Preferences* prefs;
};
