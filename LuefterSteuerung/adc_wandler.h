/********************************************************************************
 Abschlussprojekt "Entwicklung, Aufbau und Inbetriebnahme einer Brandmeldeanlage"
*********************************************************************************
File: adc_wandler.h
Version: 1.5
Author: David "RayChan" R�ckert
Beschreibung:

Hier sind die Difinitionen und Funktionsprototypen f�r ADC-Routinen.

// 10-Bit Analog Digital Wandler //

	Funktion:
	- adc_init(referenzspg)
		- referenzspg:
			0 = AREF als Referenz
			1 = AVcc als Referenz with external capacitor at AREF pin
			2 = Internal 1.1V als Referenz
	- ADC_lesen_einzel(Kanal)
		- Kanal:	ADC Pin w�hlen

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

	#define AREF_REFERENZ 0								//AREF als Referenz
	#define AVCC_REFERENZ 1								//AVcc als Referenz with external capacitor at AREF pin
	#define INTERN_REFERENZ 2							//Internal 1.1V als Referenz
    #define ATTINY13
    //#define ATMEGA328P

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	extern void adc_init( unsigned char referenzspg);	//ADC Einschalten und Festlegen der Referenzspg.
	/*	referenzspg:
		0 = AREF als Referenz
		1 = AVcc als Referenz mit externen Kondensator am AREF pin
		2 = Internal 1.1V als Referenz
	*/
	extern unsigned int ADC_lesen(unsigned char Kanal);	//Gibt den Analogenwert als INT-Wert zur�ck
	/* Kanal:
		ADC Pin angeben
	*/

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /* ADC_WANDLER_H_ */