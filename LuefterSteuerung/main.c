/********************************************************************************
  L�fter Steuerung
*********************************************************************************
File: main.c
Version: 0.2
Author: RayChan
Beschreibung:

- Es soll Temperatur eingelesen werden
- Temperatur regelt ein L�fter �ber PWM
- Bei nicht drehenden L�fter T�nt ein Alarm
- Bei zuhoher Temperatur die nicht sinkt erT�nt ein Alarm
- Dreht der L�fter nicht nach 10sec wird der L�fter abgeschaltet
- Bei �berhitzung wird Spannung der Platine abgeschaltet

// ----------------------------------------------------------------------------
// Pin Belegung des ATtiny13-20PU:
// ----------------------------------------------------------------------------
										 --|--|--
	10k gegen GND			Reset	PB5	-|1    8|- VCC	                5V
	�zilator       			ADC3	PB3	-|		|- PB2	ADC1            L�fter
	Temperaturf�hler      	ADC2	PB4	-|		|- PB1	MISO
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
//	* �bergabeparameter: -
//	* R�ckgabewert	   : Null
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