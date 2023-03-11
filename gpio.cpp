/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Implementacja zarządzania GPIO.
 */

#include "gpio.hpp"

#include <avr/io.h>

void ledOn(enum PIN_LED pinLed)
{
	PORTC &= ~_BV(pinLed);
}

void ledOff(enum PIN_LED pinLed)
{
	PORTC |= _BV(pinLed);
}

void ledToggle(enum PIN_LED pinLed)
{
	PORTC ^= _BV(pinLed);
}

void handleKey()
{
	if (bit_is_clear(PIND, PIN_KEY1)) {
		ledOn(PIN_LED_KEY);
	} else {
		ledOff(PIN_LED_KEY);
	}
}

void gpioInitialize()
{
	DDRC = _BV(PIN_LED_HEART_BIT) | _BV(PIN_LED_KEY) | _BV(PIN_LED_TOGGLE);
	PORTC = _BV(PIN_LED_HEART_BIT) | _BV(PIN_LED_KEY) | _BV(PIN_LED_TOGGLE);
	PORTD = _BV(PIN_KEY1);
}
