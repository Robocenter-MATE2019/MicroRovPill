#include "MicroROV.h"

void PrintPacket(Packet& packet)
{
	Serial.print(packet.x);
	Serial.print('-');
	Serial.print(packet.led);
}

void MicroROV::init()
{
	m_uart.init();
	m_thrustersubsystem.init();
	m_led.init();
}

void MicroROV::run()
{
	m_uart.read(m_packet);
	m_led.write(m_packet);
	m_thrustersubsystem.set_power(m_packet);
}