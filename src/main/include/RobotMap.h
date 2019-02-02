/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <string>

/**
 * Les ports sont au hasard. A changer quand on aura le materiel.
 */

constexpr int kLineDetectionVerticalThreshold = 400;

static std::string kCameraIP = "10.66.22.20";
static std::string kCameraName = "camera0";
constexpr int axisCamWidth = 480;
constexpr int axisCamHeight = 360;

constexpr int kMotorLeft1 = 8;
constexpr int kMotorLeft2 = 9;
constexpr int kMotorRight1 = 4;
constexpr int kMotorRight2 = 5;

constexpr int kJoystick1 = 0;

constexpr int kYButton = 4; 
constexpr int kXButton = 1;
constexpr int kBButton = 3; 
constexpr int kAButton = 2; 

constexpr int k1Button = 1;
constexpr int k3Button = 3;
constexpr int k4Button = 4;

constexpr int kGyro = 0;
constexpr int kGyroSensitivity = 3;

constexpr int kActuator = 0;

constexpr double kCircumference = 0.4787787204060999; 

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
