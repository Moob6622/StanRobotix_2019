/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <iostream>

#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/Actuate.h"

#include <iostream>


GPS Robot::m_gps;
OI Robot::m_oi;
Actuator Robot::m_actuator;
double Robot::PIDVal;
double Robot::PIDP;
double Robot::PIDI;
double Robot::PIDD;

DriveTrain Robot::m_drivetrain;
Vision Robot::m_vision; 
// DetectLines grip::detectLines;

AlignmentPID* Robot::m_AlignPID;


/**
RotationPID * Robot::mPidPtr = new RotationPID(SmartDashboard::GetNumber("DB/Slider 0",0.0),
                                               SmartDashboard::GetNumber("DB/Slider 1",0.0)*0.05, 
                                               SmartDashboard::GetNumber("DB/Slider 2",0.0)*0.05);
**/

void Robot::RobotInit() 
{
  prefs = Preferences::GetInstance();
	PIDVal = prefs->GetDouble("PIDVal", 40.0);
	PIDP = prefs->GetDouble("PIDP", 1.0);
	PIDI = prefs->GetDouble("PIDI", 1.0);
	PIDD = prefs->GetDouble("PIDD", 1.0);
  m_gps.ResetSensors();


  m_vision.Initialization(); 

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  prefs = Preferences::GetInstance();
	PIDVal = prefs->GetDouble("PIDVal", 40.0);
  PIDP = prefs->GetDouble("PIDP", 1.0);
  PIDI = prefs->GetDouble("PIDI", 1.0);
  PIDD = prefs->GetDouble("PIDD", 1.0);
  
  //std::cout<<Robot::PIDSettingsPtr[0]<<" "<<Robot::PIDSettingsPtr[1]<<" "<<Robot::PIDSettingsPtr[2]<<std::endl;
  }
/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() 
{ 
  frc::Scheduler::GetInstance()->Run(); 
}

void Robot::TeleopInit() 
{
}

void Robot::TeleopPeriodic() 
{ 
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() 
{

}

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif
