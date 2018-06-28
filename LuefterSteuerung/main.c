/********************************************************************************
Projekt	: Temperatur geregelte Lüftersteuerung
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
- Temperatur regelt ein Lüfter über PWM
- Bei nicht drehenden Lüfter Tönt ein Alarm
- Bei zuhoher Temperatur die nicht sinkt erTönt ein Alarm
- Dreht der Lüfter nicht nach 10sec wird der Lüfter abgeschaltet
- Bei Überhitzung wird Spannung der Platine abgeschaltet


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
        temp_mcp_init();

        do
        {

        } while (1);

		return 0;
	}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//