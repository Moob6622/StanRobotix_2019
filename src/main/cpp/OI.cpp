/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <RobotMap.h>
#include "Commands/Turn.h"
#include "Commands/Advance.h"
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/MoveServo.h"

OI::OI() 
{
  // Process operator interface input here.
  std::cout<<"bool :"<<Robot::PIDVal<<std::endl;

  mJoystickPtr = new Joystick(kJoystick1);

  mYButtonPtr = new JoystickButton(mJoystickPtr, kYButton);
  mAButtonPtr = new JoystickButton(mJoystickPtr, kAButton);
  mBButtonPtr = new JoystickButton(mJoystickPtr, kBButton);
  mXButtonPtr = new JoystickButton(mJoystickPtr, kXButton);

  //impossible de declarer le mButtonPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp
  
<<<<<<< HEAD
<<<<<<< HEAD
  Turn * mYButtonCommandPtr = new Turn(0.0, Robot::mPid, true);
=======
  Turn * mYButtonCommandPtr = new Turn(0.0, &Robot::mPid, true);
  Advance * mAButtonCommandPtr = new Advance(1000, &Robot::mS_Pid, false);
>>>>>>> 8c8f951b51f75809a0c4a114e652def46fb0ea94

  mYButtonPtr->WhenPressed(mYButtonCommandPtr);
  mAButtonPtr->WhenPressed(mAButtonCommandPtr);

=======
  Turn * mYButtonCommandPtr = new Turn(0.0, &Robot::mPid, true);
  Advance * mAButtonCommandPtr = new Advance(72, &Robot::mS_Pid, false);

  //mYButtonPtr->WhenPressed(mYButtonCommandPtr);
  //mAButtonPtr->WhenPressed(mAButtonCommandPtr);
  MoveServo* Retracter = new MoveServo(0.2);
  MoveServo* Etendre = new MoveServo(0.9);
  mYButtonPtr->WhenPressed(Etendre);
  mAButtonPtr->WhenPressed(Retracter);
>>>>>>> dec28e4c938ba7fe61bb13a7be40f0f4bf893979
}

double OI::GetLeftJoystick() 
{
  return -mJoystickPtr->GetRawAxis(1); //signe << - >> devant la valeur des joysticks car 
                                   // leur orientation est inversee par rapport au tank drive
}

double OI::GetRightJoystick() 
{
  return -mJoystickPtr->GetRawAxis(3); //signe << - >> devant la valeur des joysticks car 
                                   //leur orientation est inversee par rapport au tank drive
}
