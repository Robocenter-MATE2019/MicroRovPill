#pragma once

#include "BrushlessMotor.h"
#include "Config.h"


class ThrustersSubSystem
{
public:
	ThrustersSubSystem();
	void init();
	void set_power(int8_t x, int8_t y, int8_t w, int8_t z);
private:
	void manual_regulator(int8_t power[], int8_t x, int8_t y, int8_t w, int8_t z);
	BrushlessMotor m_motors[THRUSTER_SIZE];
};