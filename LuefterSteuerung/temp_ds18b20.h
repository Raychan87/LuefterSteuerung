
/********************************************************************************
Temperatur Funktion
*********************************************************************************
File: temp_ds1b20.h
Version: 0.1
Author: RayChan
Für: Temperatur Sensor DS18B20
Beschreibung:

Hier werden die Temperatur Sensorpins und die Analoge Referenzspannung angegeben.
Sowie Funktionsprototypen für temp.c.
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef TEMP_DS18B20_H
    #define	TEMP_DS18B20_H

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

    #include <init.h>
  
// ----------------------------------------------------------------------------//
// 	Definition (Einstellungen):
// ----------------------------------------------------------------------------//

    #define TEMP_DS_DDR		DDRB	    //DDR festlegen
	#define TEMP_DS_PORT	PORTB	    //Port festlegen
	#define TEMP_DS_PIN		PB4		    //Pin festlegen

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

    
// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /*TEMP_DS18B20_H*/
