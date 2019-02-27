#pragma once

#include "BrushlessMotor.h"
#include "Config.h"


class ThrustersSubSystem
{
public:
	ThrustersSubSystem();
	void init();
	void set_power(Packet& packet);
private:
	void manual_regulator(int8_t power[], int8_t x);
	BrushlessMotor m_motors[THRUSTER_SIZE];
};