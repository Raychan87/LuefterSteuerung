/********************************************************************************
1-Wire Funktion
*********************************************************************************
File: onewire.h
Version: 0.1
Author: RayChan
Beschreibung:

Header File des 1-Drahtbuses für den DS18B20 Temperatursensor.
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef ONEWIRE_H_
	#define ONEWIRE_H_

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "init.h"

// ----------------------------------------------------------------------------//
// 	Definition (Einstellungen):
// ----------------------------------------------------------------------------//

	

// ----------------------------------------------------------------------------//
// 	Globale Variable:
// ----------------------------------------------------------------------------//

	typedef struct OneWireConfiguration
	{
	    volatile unsigned char TEMP_DS_DDR; 	//Pointer to DDR register
	    volatile unsigned char TEMP_DS_PORT; 	//Pointer to PORT register
	    volatile unsigned char TEMP_DS_PIN; 	//Pointer to PIN register
	    volatile unsigned char TEMP_DS_PIN_MASK;	//Port mask
	    //unsigned char Flags; 			//Additional configuration flags for fututre use
	    unsigned char ROM[8]; 			//ROM address
	} OneWireConfiguration;
	
// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

    	extern unsigned char OneWireInit( OneWireConfiguration * ); //Init one wire bus
	extern void OneWireWrite( OneWireConfiguration *, unsigned char ); //Write 1 or 0 to one wire bus
	extern void OneWireWriteByte( OneWireConfiguration *, unsigned char ); //Write byte to one wire bus
	extern unsigned char OneWireRead( OneWireConfiguration * ); //Read one wire data bus
	extern unsigned char OneWireReadByte( OneWireConfiguration * ); //Read byte from one wire data bus

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /* ONEWIRE_H_ */
