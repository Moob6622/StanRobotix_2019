/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\Vision.h"
#include "Subsystems\DriveTrain.h"
#include "Timer.h"
#include <math.h>
#include <iostream>
#include "Robot.h"

Vision::Vision() : Subsystem("Vision"), mCameraServer(nullptr) {}

void Vision::Initialization()
{
  foundLine = true;
  foundContour = true;
  //m_cameraServer->GetInstance()->StartAutomaticCapture("USBCamera");
  if (mCameraServer != nullptr)
  {
    mCameraServer->GetInstance()->AddAxisCamera("Axis Cam",kCameraIP);
    mCameraServer->GetInstance()->PutVideo("Camera MS",axisCamWidth,axisCamHeight);
  }

  mNetworkTableInstanceInst = nt::NetworkTableInstance::GetDefault();
  lastAngle=90;
}

void Vision::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double Vision::GetContoursCentreX(){
  auto table = mNetworkTableInstanceInst.GetTable("GRIP/myContoursReport");

  auto wCoordX = table->GetEntry("centerX").GetDoubleArray(0);
  
  if (!wCoordX.empty())
  {
    if (wCoordX.size() == 2)
    {
      foundContour = true;
      return (wCoordX[0]+wCoordX[1])/2.0;
    }
  }
  foundContour = false;
  return -1;
}

double Vision::GetContourAngle()
{
  //angle forme entre avant du robot et hatch (entre -90 et 90)
  auto table = mNetworkTableInstanceInst.GetTable("GRIP/myContoursReport");

  auto wCoordX = table->GetEntry("centerX").GetDoubleArray(0);
  auto wArea = table->GetEntry("area").GetDoubleArray(0);
  if (!wArea.empty())
  {
    if (wArea.size() == 2)
    {
      foundContour = true;
      //distance au hatch en pieds
      double dist = Robot::m_gps.GetCapteurDistance()/12.0;
      //formule avec ln pour trouver angle
      double absoluteAngle = log(std::min(wArea[0],wArea[1])/std::max(wArea[0],wArea[1])/(0.041+0.007*dist));
      
      // en face du hatch, si bande à ma droite est plus proche :
      if(wCoordX[0]>wCoordX[1])
      {
        if (wArea[0]>wArea[1])
        {
        return -absoluteAngle;
        }
      }
      else
      {
        if (wArea[0]<wArea[1])
        {
        return -absoluteAngle;
        }
      }
      return absoluteAngle;
      //return angle orienté de (arrière-avant du robot) et (avant-arriere du hatch) en degrés
    }
  }
  foundContour = false;
  return 0;
}

double Vision::GetLineAngle()
{
  auto table = mNetworkTableInstanceInst.GetTable("GRIP/myLinesReport");
  auto wAngle = table->GetEntry("angle").GetDoubleArray(0);
  if(wAngle.empty())
  {
    foundLine = false;
    return lastAngle;
  } 
  else
  {
    foundLine = true;
    if(wAngle[0]<0)
    {
      wAngle[0]+=180;
    }
    lastAngle = wAngle[0];
    return wAngle[0];
  }
}

bool Vision::FoundContour()
{
  return foundContour;
}
bool Vision::FoundLine(){
  return foundLine;
}

void Vision::GetLine(double * oLine)
{
  //auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = mNetworkTableInstanceInst.GetTable("GRIP/myLinesReport");

  auto wCoordX1 = table->GetEntry("x1").GetDoubleArray(0); 
  auto wCoordY1 = table->GetEntry("y1").GetDoubleArray(0);
  auto wCoordX2 = table->GetEntry("x2").GetDoubleArray(0);
  auto wCoordY2 = table->GetEntry("y2").GetDoubleArray(0);
  auto wAngle = table->GetEntry("angle").GetDoubleArray(90); 

  int wTaille = 2;
  // Attention : sizeof() est une taille en octets, pas la longueur du array
  //int wTaille =  sizeof( table->GetEntry("y1").GetDoubleArray(0) );
  
  for(int i = 0; i < wTaille ; i++ )
  {
    if(wCoordY1[i]<kLineDetectionVerticalThreshold
      && wCoordY2[i]<kLineDetectionVerticalThreshold)
    {
      oLine[0] = wCoordX1[i];
      oLine[1] = wCoordY1[i];
      oLine[2] = wCoordX2[i];
      oLine[3] = wCoordY2[i];
      oLine[4] = wAngle[i];
      break;
    }
  }
}

void Vision::DisplayData() 
{
  double wCoordLine[5];
  GetLine(wCoordLine);
 
  SmartDashboard::PutNumber("x1", wCoordLine[0]);
  SmartDashboard::PutNumber("y1", wCoordLine[1]);
  SmartDashboard::PutNumber("x2", wCoordLine[2]);
  SmartDashboard::PutNumber("y2", wCoordLine[3]);
  SmartDashboard::PutNumber("angle", wCoordLine[4]);
}


/**
 * 
 *          Section calcul de coordonnees pour PID
 * 
 * 
 * */

void Vision::ReadyData()
{
  mTheta = GetContourAngle();
}


// double Vision::GetC1X() 
// {
//     return kRobotLargeur/2;
// }

// double Vision::GetC1Y()
// {
//   if (mTheta<0)
//   {
//   return (-sqrt( pow(kRobotLargeur,2) - pow(GetC1X()+GetA1X(),2))+GetA1Y());
//   }
//   else
//   {
//     return (-sqrt( pow(kRobotLargeur,2) - pow(GetC1X()+GetA2X(),2))+GetA2Y());
//   }
// }

// double Vision::GetC2X()
// {
//   return -kRobotLargeur/2;
// }

// double Vision::GetC2Y()
// {
//   if (mTheta<0)
//   {
//   return (-sqrt( pow(kRobotLargeur,2) - pow(GetC1X()+GetA1X(),2))+GetA1Y());
//   }
//   else
//   {
//     return (-sqrt( pow(kRobotLargeur,2) - pow(GetC1X()+GetA2X(),2))+GetA2Y());
//   }
// }

// double Vision::GetAX()
// {
  
//   return -cos(mTheta) * Robot::m_gps.GetCapteurDistance();
// }

// double Vision::GetAY()
// {
 
//   return sin(mTheta) * Robot::m_gps.GetCapteurDistance();
// }

// double Vision::GetA1X()
// {
//   return (GetAX() + cos(kAngleDiagonaleRobot + mTheta) * kLongeurDiagonaleRobot);
// }

// double Vision::GetA1Y()
// {
//   return (GetAY() + sin(kAngleDiagonaleRobot + mTheta) * kLongeurDiagonaleRobot);
// }

// double Vision::GetA2X()
// {
//   return (GetAX() - cos(kAngleDiagonaleRobot - mTheta) * kLongeurDiagonaleRobot);
// }

// double Vision::GetA2Y()
// {
//   return (GetAY() + sin(kAngleDiagonaleRobot - mTheta) * kLongeurDiagonaleRobot);
// }

// double Vision::GetRightAngle() 
// {
//   if (mTheta < 0)
//   {
//     double wA2C2 = Robot::m_gps.ComputeDistance(GetA2X(),
//                                                 GetA2Y(),
//                                                 GetC2X(),
//                                                 GetC2Y());
//     double wA1C2 = Robot::m_gps.ComputeDistance(GetA1X(),
//                                                 GetA1Y(),
//                                                 GetC2X(),
//                                                 GetC2Y());
//     double wA1A2 = Robot::m_gps.ComputeDistance(GetA1X(),
//                                                 GetA1Y(),
//                                                 GetA2X(),
//                                                 GetA2Y());
//     return acos((pow(wA2C2,2)-pow(wA1C2,2)-pow(wA1A2,2))/(-2*wA1C2*wA1A2));
//   }
  
//   else
//   {
//     double wA2C2 = Robot::m_gps.ComputeDistance(GetA2X(),
//                                                 GetA2Y(),
//                                                 GetC2X(),
//                                                 GetC2Y());
//     double wA2C1 = Robot::m_gps.ComputeDistance(GetA2X(),
//                                                 GetA2Y(),
//                                                 GetC1X(),
//                                                 GetC1Y());
//     double wC1C2 = Robot::m_gps.ComputeDistance(GetC1X(),
//                                                 GetC1Y(),
//                                                 GetC2X(),
//                                                 GetC2Y());
//     return acos((pow(wA2C2,2)-pow(wA2C1,2)-pow(wC1C2,2))/(-2*wA2C1*wC1C2));
//   }
// }


// double Vision::GetLeftAngle() 
// {
//   if (mTheta > 0)
//   {
//     double wA2C2 = Robot::m_gps.ComputeDistance(GetA2X(),
//                                                 GetA2Y(),
//                                                 GetC2X(),
//                                                 GetC2Y());
//     double wA1C2 = Robot::m_gps.ComputeDistance(GetA1X(),
//                                                 GetA1Y(),
//                                                 GetC2X(),
//                                                 GetC2Y());
//     double wA1A2 = Robot::m_gps.ComputeDistance(GetA1X(),
//                                                 GetA1Y(),
//                                                 GetA2X(),
//                                                 GetA2Y());
//     return acos((pow(wA2C2,2)-pow(wA1C2,2)-pow(wA1A2,2))/(-2*wA1C2*wA1A2));
//   }
  
//   else
//   {
//     double wA1C1 = Robot::m_gps.ComputeDistance(GetA1X(),
//                                                 GetA1Y(),
//                                                 GetC1X(),
//                                                 GetC1Y());
//     double wC2A1 = Robot::m_gps.ComputeDistance(GetC2X(),
//                                                 GetC2Y(),
//                                                 GetA1X(),
//                                                 GetA1Y());
//     double wC1C2 = Robot::m_gps.ComputeDistance(GetC1X(),
//                                                 GetC1Y(),
//                                                 GetC2X(),
//                                                 GetC2Y());
//     return acos((pow(wA1C1,2)-pow(wC2A1,2)-pow(wC1C2,2))/(-2*wC2A1*wC1C2));
//   }


/**
 * 
 *          Section calcul de coordonnees pour PID
 * 
 * 
 * */

