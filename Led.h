#pragma once

#include "UARTCommunicator.h"

class Led
{
public:
	Led();
	void init();
	void write(Packet& packet);
};