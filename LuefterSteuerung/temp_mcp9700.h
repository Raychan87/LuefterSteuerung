/********************************************************************************
Temperatur Funktion
*********************************************************************************
File: temp_mcp9700.h
Version: 1.1
Author: RayChan
Beschreibung:

Hier werden die Temperatur Sensorpins und die Analoge Referenzspannung angegeben.
Sowie Funktionsprototypen für temp.c.

Hier wird der Temperaturfühler MCP9700 verwendet
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef TEMP_MCP9700_H_
	#define TEMP_MCP9700_H_

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "adc_wandler.h"
	
// ----------------------------------------------------------------------------//
// 	Definition (Einstellungen):
// ----------------------------------------------------------------------------//

	#define TEMP_MCP_DDR		DDRB			//DDR festlegen
	#define TEMP_MCP_PORT		PORTB			//Port festlegen
	#define TEMP_MCP_PIN		PB4				//Pin festlegen
	#define MCP_REF_MODI		AVCC_REFERENZ	//Referenz Modus wählen
	//AREF_Referenz; AVCC_Referenz; Intern_Referenz
    #define MCP_VREF	        5             	//Referenz Spannung
	
// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	extern void temp_mcp_init(void);		//Temperaturmessung initalisierung und ADC starten
	extern float temp_mcp(void);			//Gibt den Fertig berechneten Temperaturwert in Float zurück

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//
#endif /* TEMP_MCP9700_H_ */
