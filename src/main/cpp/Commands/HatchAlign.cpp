/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/HatchAlign.h"
#include <Robot.h>

HatchAlign::HatchAlign() {
  Requires(&Robot::m_drivetrain);
  Requires(&Robot::m_vision);
  AddSequential(new Aligner(Robot::m_AnglePID, Robot::m_CentrePID));
  //Il faudra smooth out toutes les questions d'unites (cm, inch, unite arbitraire, ...)
  AddSequential(new Advance(Robot::m_gps.GetCapteurDistance()-1, Robot::m_StraightPID, false));
}
