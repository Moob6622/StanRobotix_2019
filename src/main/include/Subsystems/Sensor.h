#pragma once

#include <Encoder.h>
#include <ADXRS450_Gyro.h>
#include <BuiltInAccelerometer.h>

class Sensor : public frc::Subsystem {
private:
	Encoder *encL = new Encoder(0,1,false, Encoder::EncodingType::k4X);
	Encoder *encR = new Encoder(2,3,true, Encoder::EncodingType::k4X);
	ADXRS450_Gyro *gyro = new ADXRS450_Gyro();
	BuiltInAccelerometer *accelo = new BuiltInAccelerometer(Accelerometer::kRange_2G);
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:

	Sensor();   

	void InitDefaultCommand() override;
	void Reset();
	double ReadEncL();
	double ReadEncR();
	double ReadGyro();
	double ReadAcceloX();
	double ReadAcceloY();
	double ReadAcceloZ();
};
