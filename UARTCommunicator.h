#pragma once
#include <stdint.h>

struct Packet
{
	int8_t x;
	int8_t led;
};

class UARTCommunicator
{
public:
	void init();
	bool read(Packet &packet);
};

