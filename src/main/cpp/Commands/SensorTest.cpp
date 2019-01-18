#include <Commands/SensorTest.h>
#include <math.h>

SensorTest::SensorTest()
{
	Requires(&Robot::m_sensors);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void SensorTest::Initialize()
{
	Robot::m_sensors.Reset();

}

// Called repeatedly when this Command is scheduled to run
void SensorTest::Execute()
{
	frc::SmartDashboard::PutNumber("EncoderRight", Robot::m_sensors.ReadEncR());
	frc::SmartDashboard::PutNumber("EncoderLeft", Robot::m_sensors.ReadEncL());
	frc::SmartDashboard::PutNumber("Acceleration X-axis", Robot::m_sensors.ReadAcceloX());
	frc::SmartDashboard::PutNumber("Acceleration Y-Axis", Robot::m_sensors.ReadAcceloY());
	frc::SmartDashboard::PutNumber("Acceleration Z-axis", Robot::m_sensors.ReadAcceloZ());
	frc::SmartDashboard::PutNumber("Gyro",Robot::m_sensors.ReadGyro());
}

// Make this return true when this Command no longer needs to run execute()
bool SensorTest::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SensorTest::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SensorTest::Interrupted() {

}
