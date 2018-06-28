/********************************************************************************
Temperatur Funktion
*********************************************************************************
Author		: RayChan
WebSeite	: https://FotoTour-und-Technik.de
GitHub		: https://github.com/Raychan87

File		: temp_ds18x20.h
Version		: 0.3
Status		: in build

Beschreibung:

Hier werden für den Sensor DS18x20 alle benötigten Funktionen declariert sowie
Macros und Difinitionen erstellt.


Befehl 				| Beschreibung 													| Code
Convert T 			| Leitet die Temperaturmessung ein 								| 0x44
Read Scratchpad 	| Liest das Scratchpad inklusive des CRC Bytes aus 				| 0xBE
Write Scratchpad 	| Schreibt Daten in das Scratchpad (Byte 2 und 3 <-> TH und TL) | 0x4E
Copy Scratchpad 	| Kopiert TH und TL aus dem EEPROM zum Scratchpad 				| 0x48
Recall E 			| Startet einen Rückruf von TH und TL vom EEPROM zum Scratchpad | 0xB8
Read Power Supply 	| Signalisiert den Versorgungszustand zum PIC 					| 0xB4
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef TEMP_DS18X20_H
    #define	TEMP_DS18X20_H

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
	
// ----------------------------------------------------------------------------//
// 	Macros
// ----------------------------------------------------------------------------//	
	
	#define TEMP_DS_PIN_SET_OUTPUT	TEMP_DS_DDR |= (1 << TEMP_DS_PIN);	//PIN als Ausgang schalten
	#define TEMP_DS_PIN_SET_INPUT	TEMP_DS_DDR &= ~(1 << TEMP_DS_PIN);	//PIN als Eingang schalten
	#define TEMP_DS_PIN_SET_LOW		TEMP_DS_PORT &= ~(1 << TEMP_DS_PIN);//Ausgang auf Low setzen
	#define TEMP_DS_PIN_SET_HIGH	TEMP_DS_PORT |= (1 << TEMP_DS_PIN); //Ausgang auf High setzen
	#define TEMP_DS_PIN_READING		TEMP_DS_PIN_GROUP & (1 << TEMP_DS_PIN);//Pin auslesen
			
// ----------------------------------------------------------------------------//
// 	Globale Variablen
// ----------------------------------------------------------------------------//

	extern uint8_t ds18x20_adr [9];

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	uint8_t OneWire_MasterResetImpuls (void);			//Beginn der Kommunikation
	uint8_t OneWire_ReceiveBit (void);					//Empfangen eines Bits
	uint8_t OneWire_RecevieByte (void);					//Empfangen eines Bytes
	void OneWire_TransmitBit (uint8_t TransmitBit);		//Senden eines Bits
	void OneWire_TransmitByte (uint8_t TransmitByte);	//Senden eines Bytes
	void OneWire_Skip_Rom(void);						//Skip Rom
	void OneWire_adr_reading(void);						//nicht fertig!!!

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /*TEMP_DS18X20_H*/
