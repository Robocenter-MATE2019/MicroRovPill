#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "ThrustersSubSystem.h"
#include "UARTCommunicator.h"

class MicroROV
{
public:
	void init();
	void run();
private:
	Axis m_axis;
	ThrustersSubSystem m_thrustersubsystem;
	UARTCommunicator m_uart;
};