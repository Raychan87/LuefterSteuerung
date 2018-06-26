
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

	#include "init.h"
  
// ----------------------------------------------------------------------------//
// 	Definition (Einstellungen):
// ----------------------------------------------------------------------------//

    #define TEMP_DS_DDR			DDRB			//DDR festlegen
    #define TEMP_DS_PORT		PORTB			//Port festlegen
    #define TEMP_DS_PIN			PB4				//Pin festlegen
    #define TEMP_DS_PIN_MASK    0b00001000		//Pin Maske festlegen
	
	
	#define LAT_DQ          LATAbits.LA7
	#define DQ              PORTAbits.RA7
	#define TRIS_DQ         TRISAbits.TRISA7
		
// ----------------------------------------------------------------------------//
// 	Globale Variablen
// ----------------------------------------------------------------------------//

	extern uint8_t ds18x20 [9];

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	unsigned char ow_mri (void);
	unsigned char ow_rd_bit (void);
	unsigned char ow_rd_byte (void);
	void ow_wr_bit (uint8_t val);
	void ow_wr_byte (uint8_t val);
	void ow_skip_rom (void);

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /*TEMP_DS18B20_H*/
