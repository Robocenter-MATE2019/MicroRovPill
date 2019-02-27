#include "ThrustersSubSystem.h"

ThrustersSubSystem::ThrustersSubSystem()
{
	m_motors[0] = BrushlessMotor(H_FRONT_LEFT);
	m_motors[0].set_inverse(H_LEFT_INVERSE);
}

void ThrustersSubSystem::init()
{
	for (auto& motor : m_motors)
	{
		motor.init();
	}
	delay(10000);
}

void ThrustersSubSystem::set_power(Packet& packet)
{
	int8_t power[THRUSTER_SIZE];
	manual_regulator(power, packet.x);
	for (int i = 0; i < THRUSTER_SIZE; i++)
	{
		m_motors[i].set_power(power[i]);
	}
}

void ThrustersSubSystem::manual_regulator(int8_t power[], int8_t x)
{
	power[0] = constrain(x, -100, 100);
}
