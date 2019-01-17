/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Joystick.h>
#include <Buttons/JoystickButton.h>

//#include <JoystickButton.h>

class OI 
{
  public:
    OI();
    double GetLeftJoystick();
    double GetRightJoystick();

  private:
    Joystick * mJoystickPtr;

    JoystickButton * mYButtonPtr;
    JoystickButton * mXButtonPtr;
    JoystickButton * mBButtonPtr;
    JoystickButton * mAButtonPtr;

    JoystickButton * mFrontLeftTriggerPtr;
    JoystickButton * mBackLeftTriggerPtr;
    JoystickButton * mFrontRightTriggerPtr;
    JoystickButton * mBackRightTriggerPtr;

};
