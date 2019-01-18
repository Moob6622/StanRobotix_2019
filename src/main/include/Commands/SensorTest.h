#pragma once

#include <Commands/Command.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Robot.h"

class SensorTest : public frc::Command {
public:
	SensorTest();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

