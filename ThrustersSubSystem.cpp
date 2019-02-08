#include "ThrustersSubSystem.h"

ThrustersSubSystem::ThrustersSubSystem()
{
	m_motors[0] = BrushlessMotor(H_FRONT_LEFT);
	m_motors[0].set_inverse(H_LEFT_INVERSE);
	//m_motors[1] = BrushMotor(H_LEFT_PIN_ONE, H_LEFT_PIN_TWO);
	//m_motors[1].set_inverse(H_LEFT_INVERSE);
	//m_motors[2] = BrushMotor(V_MOTOR_PIN_ONE, V_MOTOR_PIN_TWO);
	//m_motors[2].set_inverse(V_MOTOR_INVERSE);
}

void ThrustersSubSystem::init()
{
	for (auto& motor : m_motors)
	{
		motor.init();
	}
	delay(10000);
}

void ThrustersSubSystem::set_power(int8_t x, int8_t y, int8_t w, int8_t z)
{
	int8_t power[THRUSTER_SIZE];
	manual_regulator(power, x, y, w, z);
	for (int i = 0; i < THRUSTER_SIZE; i++)
	{
		m_motors[i].set_power(power[i]);
		//Serial.println(power[i]);
	}
	//Serial.println();
}

void ThrustersSubSystem::manual_regulator(int8_t power[], int8_t x, int8_t y, int8_t w, int8_t z)
{
	power[0] = constrain(x, -100, 100);
	//power[1] = constrain(y - x - w, -100, 100);
	//power[2] = constrain(y - x + w, -100, 100);
	//power[3] = constrain(y + x - w, -100, 100);
	//power[4] = constrain(z, -100, 100);
	//power[5] = constrain(z, -100, 100);

}
