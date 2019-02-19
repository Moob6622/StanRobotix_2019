/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#define _USE_MATH_DEFINES
#include "Commands/HatchAlign.h"
#include <Robot.h>
#include <math.h>
#include <iostream>

HatchAlign::HatchAlign() {
  Requires(&Robot::m_drivetrain);
  Requires(&Robot::m_vision);
  std::cout<<"avant align"<<std::endl;
  //AddSequential(new Aligner(Robot::m_AnglePID, Robot::m_CentrePID));
  double dist = Robot::m_gps.GetCapteurDistance();
  double theta = 50.0;
  //double theta = Robot::m_vision.GetContourAngle();
  std::cout<<"construct"<<std::endl;
  // //Il faudra smooth out toutes les questions d'unites (cm, inch, unite arbitraire, ...)
  //AddSequential(new Turn((90-fabs(theta))*theta/fabs(theta), Robot::m_RotationPID));
  AddSequential(new Turn((90 - fabs(theta))*theta/fabs(theta), Robot::m_RotationPID));
  std::cout<<"fin rotation 1"<<std::endl;
  AddSequential(new Advance(fabs(dist*sin(theta*M_PI/180)), Robot::m_StraightPID, false));
  AddSequential(new Turn(-90*theta/fabs(theta), Robot::m_RotationPID));
  AddSequential(new Advance(dist*cos(theta*M_PI/180), Robot::m_StraightPID, false));
}