/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Pętla główna.
 */

#include "gpio.hpp"
#include "heartBit.hpp"

#include <avr/interrupt.h>

#include <stdlib.h>

/**
 * Inicjalizacja przerwań.
 */
void interruptsInitialize()
{
}

/**
 * Obsługa przerwania INT0.
 */
ISR(INT0_vect)
{
}

/**
 * Pętla główna.
 */
void mainLoop()
{
	heartBit();
	handleKey();
}

/**
 * Funkcja główna.
 */
int main()
{
	gpioInitialize();
	interruptsInitialize();

	while (true) {
		mainLoop();
	}

	return EXIT_SUCCESS;
}