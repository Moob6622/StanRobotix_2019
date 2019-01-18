#include <Commands/SensorTest.h>
#include <Subsystems/Sensor.h>
#include "RobotMap.h"
#include "Robot.h"

Sensor::Sensor() : frc::Subsystem("EncoderTest")
{

}

void Sensor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	 SetDefaultCommand(new SensorTest());
}

void Sensor::Reset()
{
	encR->Reset();
	encL->Reset();
	gyro->Calibrate();
}

double Sensor::ReadEncR()
{
	return encR->GetRaw();
}

double Sensor::ReadEncL()
{
	return encL->GetRaw();
}

double Sensor::ReadGyro()
{
	return gyro->GetAngle();
}

double Sensor::ReadAcceloX()
{
	return accelo->GetX();
}
double Sensor::ReadAcceloY()
{
	return accelo->GetY();
}
double Sensor::ReadAcceloZ()
{
	return accelo->GetZ();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
