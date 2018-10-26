/********************************************************************************
 ADC_Wandler Funktion
*********************************************************************************
Author		: RayChan
WebSeite	: https://FotoTour-und-Technik.de
GitHub		: https://github.com/Raychan87

File		: adc_wandler.h
Version		: 1.6
Status		: in testing

Hier sind die Difinitionen und Funktionsprototypen für ADC-Routinen.

// 10-Bit Analog Digital Wandler //

	Funktion:
	- adc_init(referenzspg)
		- referenzspg:
			0 = AREF als Referenz
			1 = AVcc als Referenz with external capacitor at AREF pin
			2 = Internal 1.1V als Referenz
	- adc_read(Kanal)
		- Kanal:	ADC Pin wählen

********************************************************************************/


// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef ADC_WANDLER_H_
	#define ADC_WANDLER_H_

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "init.h"

// ----------------------------------------------------------------------------//
// 	Definition:
// ----------------------------------------------------------------------------//

	#define AREF_REFERENZ		0				//AREF als Referenz
	#define AVCC_REFERENZ		1				//AVcc als Referenz with external capacitor at AREF pin
	#define INTERN_REFERENZ		2				//Internal 1.1V als Referenz

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	extern void adc_init(unsigned char referenzspg);	//ADC Einschalten und Festlegen der Referenzspg.
	/*	referenzspg:
		0 = AREF als Referenz
		1 = AVcc als Referenz mit externen Kondensator am AREF pin
		2 = Internal 1.1V als Referenz
	*/
	extern unsigned int adc_read(unsigned char channel);//Gibt den Analogenwert als INT-Wert zurück
	/* channel:
		ADC Pin angeben
	*/

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /* ADC_WANDLER_H_ */
