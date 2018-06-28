/********************************************************************************
Projekt	: Temperatur geregelte L�ftersteuerung
*********************************************************************************
Author		: RayChan
WebSeite	: https://FotoTour-und-Technik.de
GitHub		: https://github.com/Raychan87

MCU			: ATtiny13
F_OSC		: 16.000 MHz
IDE			: Atmel Studio 7

File		: main.c
Version		: 0.3
Status		: in Build

Beschreibung:

- Es soll Temperatur eingelesen werden
- Temperatur regelt ein L�fter �ber PWM
- Bei nicht drehenden L�fter T�nt ein Alarm
- Bei zuhoher Temperatur die nicht sinkt erT�nt ein Alarm
- Dreht der L�fter nicht nach 10sec wird der L�fter abgeschaltet
- Bei �berhitzung wird Spannung der Platine abgeschaltet


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
        temp_mcp_init();

        do
        {

        } while (1);

		return 0;
	}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//