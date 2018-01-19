/********************************************************************************
  Lüfter Steuerung
*********************************************************************************
File: main.c
Version: 0.2
Author: RayChan
Beschreibung:

- Es soll Temperatur eingelesen werden
- Temperatur regelt ein Lüfter über PWM
- Bei nicht drehenden Lüfter Tönt ein Alarm
- Bei zuhoher Temperatur die nicht sinkt erTönt ein Alarm
- Dreht der Lüfter nicht nach 10sec wird der Lüfter abgeschaltet
- Bei Überhitzung wird Spannung der Platine abgeschaltet

// ----------------------------------------------------------------------------
// Pin Belegung des ATtiny13-20PU:
// ----------------------------------------------------------------------------
										 --|--|--
	10k gegen GND			Reset	PB5	-|1    8|- VCC	                5V
	Ózilator       			ADC3	PB3	-|		|- PB2	ADC1            Lüfter
	Temperaturfühler      	ADC2	PB4	-|		|- PB1	MISO
	Masse				        	GND	-|4	   5|- PB0	MOSI
										 --------
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "init.h"

// ----------------------------------------------------------------------------//
//							int main(void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : Null
//
//	* Beschreibung:
//
// ----------------------------------------------------------------------------//

	int main(void)
	{
        temp_init();

        do
        {

        } while (1);

		return 0;
	}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//