/********************************************************************************
 Abschlussprojekt "Entwicklung, Aufbau und Inbetriebnahme einer Brandmeldeanlage"
*********************************************************************************
File: temp.h
Version: 1.0
Author: David "RayChan" R�ckert
Beschreibung:

Hier werden die Temperatur Sensorpins und die Analoge Referenzspannung angegeben.
Sowie Funktionsprototypen f�r temp.c.

Hier wird der Temperaturf�hler MCP9700 verwendet
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef TEMP_H_
	#define TEMP_H_

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "init.h"

// ----------------------------------------------------------------------------//
// 	Definition (Einstellungen):
// ----------------------------------------------------------------------------//

	#define TEMP_DDR		DDRB						//DDR festlegen
	#define TEMP_PORT		PORTB						//Port festlegen
	#define TEMP_PIN		PB4							//Pin festlegen
	#define REF_MODI		AVCC_REFERENZ				//Referenz Modus w�hlen
    #define VREF            5                           //Referenz Spannung
	//AREF_Referenz; AVCC_Referenz; Intern_Referenz

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	extern void temp_init(void);						//Temperaturmessung initalisierung und ADC starten
	extern float temp(void);							//Gibt den Fertig berechneten Temperaturwert in Float zur�ck

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//
#endif /* TEMP_H_ */