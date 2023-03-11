/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Implementacja mrugania diodą.
 */

#include "heartBit.hpp"

#include "gpio.hpp"

#include <util/delay.h>

void heartBit()
{
	ledOn(PIN_LED_HEART_BIT);
	_delay_ms(100);
	ledOff(PIN_LED_HEART_BIT);
	_delay_ms(100);
	ledOn(PIN_LED_HEART_BIT);
	_delay_ms(100);
	ledOff(PIN_LED_HEART_BIT);
	_delay_ms(1200);
}
