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

constexpr int kMotorLeft1 = 1;
constexpr int kMotorLeft2 = 2;
constexpr int kMotorRight1 = 3;
constexpr int kMotorRight2 = 0;

constexpr int kJoystick1 = 0;

constexpr int kGyro = 1;

static std::string kCameraIP = "10.66.22.20";
static std::string kCameraName = "camera0";

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
