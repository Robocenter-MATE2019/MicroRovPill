#include "Led.h"

Led::Led()
{
}

void Led::init()
{
	pinMode(LED_PIN, OUTPUT);
}

void Led::write(Packet& packet)
{
	analogWrite(LED_PIN, map(packet.led, 0, 100, 0, 255));
}
