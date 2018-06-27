
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
	#define TEMP_DS_PIN_GROUP	PINB			//PIN Gruppe festlegen
	
	 //#define TEMP_DS_PIN_MASK    0b00001000		//Pin Maske festlegen
	 
	 #define LAT_DQ          LATAbits.LA7
	 #define DQ              PORTAbits.RA7
	 #define TRIS_DQ         TRISAbits.TRISA7
	
// ----------------------------------------------------------------------------//
// 	Macros
// ----------------------------------------------------------------------------//	
	
	#define TEMP_DS_PIN_OUTPUT		TEMP_DS_DDR |= (1 << TEMP_DS_PIN);	//PIN als Ausgang schalten
	#define TEMP_DS_PIN_INPUT		TEMP_DS_DDR &= ~(1 << TEMP_DS_PIN);	//PIN als Eingang schalten
	#define TEMP_DS_PIN_SET_LOW		TEMP_DS_PORT &= ~(1 << TEMP_DS_PIN);//Ausgang auf Low setzen
	#define TEMP_DS_PIN_SET_HIGH	TEMP_DS_PORT |= (1 << TEMP_DS_PIN); //Ausgang auf High setzen
	#define TEMP_DS_PIN_READING		TEMP_DS_PIN_GROUP & (1 << TEMP_DS_PIN);//Pin auslesen
			
// ----------------------------------------------------------------------------//
// 	Globale Variablen
// ----------------------------------------------------------------------------//

	extern uint8_t ds18x20 [9];

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	uint8_t OneWire_MasterResetImpuls (void);
	unsigned char ow_rd_bit (void);
	unsigned char ow_rd_byte (void);
	void OneWire_SendeBit (uint8_t value)
	void ow_wr_byte (uint8_t val);
	void ow_skip_rom (void);

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /*TEMP_DS18B20_H*/
