/********************************************************************************
 Abschlussprojekt "Entwicklung, Aufbau und Inbetriebnahme einer Brandmeldeanlage"
*********************************************************************************
File: temp.h
Version: 1.0
Author: D. Rückert, R. Malert
Beschreibung:  

Hier werden die Temperatur Sensorpins und die Analoge Referenzspannung angegeben.
Sowie Funktionsprototypen für temp.c.

Hier wird der Temperaturfühler MCP9700 verwendet                                                             
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

	#define TEMP_DDR		DDRC						//DDR festlegen
	#define TEMP_PORT		PORTC						//Port festlegen
	#define TEMP_PIN		PC0							//Pin festlegen
	#define REF_MODI		AVCC_REFERENZ				//Referenz Modus wählen
	//AREF_Referenz; AVCC_Referenz; Intern_Referenz

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	extern void temp_init(void);						//Temperaturmessung initalisierung und ADC starten
	extern float temp(void);							//Gibt den Fertig berechneten Temperaturwert in Float zurück

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//
#endif /* TEMP_H_ */