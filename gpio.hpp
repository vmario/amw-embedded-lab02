/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Zarządzanie GPIO.
 */

#pragma once

/**
 * Numery pinów powiązane z LED-ami.
 */
enum PIN_LED {
	PIN_LED_HEART_BIT = 0,
	PIN_LED_KEY = 1,
	PIN_LED_TOGGLE = 2,
};

/**
 * Numery pinów powiązane z przyciskami.
 */
enum PIN_KEY {
	PIN_KEY1 = 2,
};

/**
 * Zaświeca diodę na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledOn(enum PIN_LED pinLed);

/**
 * Gasi diodę na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledOff(enum PIN_LED pinLed);

/**
 * Zmienia stan diody na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledToggle(enum PIN_LED pinLed);

/**
 * Obsługuje wciśnięcie klawisza.
 */
void handleKey();

/**
 * Inicjalizuje porty GPIO.
 */
void gpioInitialize();