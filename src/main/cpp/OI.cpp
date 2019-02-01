/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "RobotMap.h"
#include "Commands/Aligner.h"
#include "Robot.h"

OI::OI() 
{
  // Process operator interface input here.
  joystick = new Joystick(kJoystick1);
  k3Button = new JoystickButton(joystick, 3);

  Aligner* k3ButtonCommand = new Aligner(Robot::m_AlignPID);

  k3Button->WhenPressed(k3ButtonCommand);

}

double OI::GetLeftJoystick() 
{
  return -joystick->GetRawAxis(1); //signe << - >> devant la valeur des joysticks car 
                                   // leur orientation est inversee par rapport au tank drive
}

double OI::GetRightJoystick() 
{
  return -joystick->GetRawAxis(3); //signe << - >> devant la valeur des joysticks car 
                                   //leur orientation est inversee par rapport au tank drive
}
