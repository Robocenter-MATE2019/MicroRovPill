#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "ThrustersSubSystem.h"
#include "UARTCommunicator.h"
#include "Led.h"

class MicroROV
{
public:
	void init();
	void run();
private:
	Packet m_packet;
	Led m_led;
	ThrustersSubSystem m_thrustersubsystem;
	UARTCommunicator m_uart;
};