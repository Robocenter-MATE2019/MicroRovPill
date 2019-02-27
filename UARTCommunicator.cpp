#include "UARTCommunicator.h"
#include <Arduino.h>

void UARTCommunicator::init()
{
	Serial.begin(115200);
	pinMode(2, OUTPUT);
}

bool UARTCommunicator::read(Packet& packet)
{
	digitalWrite(2, LOW);

	if (Serial.available() > 3)
	{
		int8_t asterisk = 0;
		while (asterisk != '*')
		{
			asterisk = Serial.read();
			if (Serial.available() == 0)
			{
				return false;
			}
		}
		String axis_ = Serial.readStringUntil('-');
		if (axis_.length() != 2)
		{
			return false;
		}
		packet.x = axis_[0];
		packet.led = axis_[1];
		while (Serial.available()) Serial.read();
//		Serial.readString();
		return true;
	}
	return false;
}

