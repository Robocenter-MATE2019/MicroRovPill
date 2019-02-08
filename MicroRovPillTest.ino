/*
 Name:		MicroRovPillTest.ino
 Created:	03.02.2019 14:49:17
 Author:	Виталий
*/

#include "MicroROV.h"

MicroROV m_rov;

void setup() {
	m_rov.init();
}

void loop() {
	m_rov.run();
}
