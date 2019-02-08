#include "MicroROV.h"

void PrintAxis(Axis& axis)
{
	Serial.print(axis.x);
	Serial.print('-');
	Serial.print(axis.y);
	Serial.print('-');
	Serial.println(axis.z);
}

void MicroROV::init()
{
	m_uart.init();
	m_thrustersubsystem.init();
}

void MicroROV::run() 
{
	m_uart.read(m_axis);
	PrintAxis(m_axis);
	m_thrustersubsystem.set_power(m_axis.x, m_axis.y, 0, m_axis.z);
}