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
  //angle forme entre avant du robot et hatch (entre -90 a 90)
  auto table = mNetworkTableInstanceInst.GetTable("GRIP/myContoursReport");

  auto wCoordX = table->GetEntry("centerX").GetDoubleArray(0);
  auto wArea = table->GetEntry("area").GetDoubleArray(0);
  if (!wArea.empty())
  {
    if (wArea.size() == 2)
    {
      foundContour = true;
      double absoluteAngle = (std::min(wArea[0],wArea[1])/std::max(wArea[0],wArea[1])-1)/-0.0088;
      
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
      //return angle orienté de (arrière-avant du robot) et (arrière-avant du hatch) en degrés
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

// Fonction: AlignerRobotLigne
// Entree: oTableau est un array qui contient les valeurs d une ligne
// Sortie: retour: vitesse du robot pour s'aligner
// Sert pour un parametre de la methode TankDrive
// L'autre prend un 0
// Rend par defaut un 0 si le robot est aligne avec la ligne

double Vision::AlignerRobotLigne(const double iTableau[5])
{
  double angle = iTableau[4];
  if(angle != 90)
  {
    if(angle < 90)
    {
      return 0.4;
    }

    else
    {
      return -0.4;
    }
  }
  return 0;
}