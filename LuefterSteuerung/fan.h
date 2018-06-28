/********************************************************************************
PWM-Lüfter Funktion
*********************************************************************************
Author		: RayChan
WebSeite	: https://FotoTour-und-Technik.de
GitHub		: https://github.com/Raychan87

File		: fan.c
Version		: 0.1
Status		: in build

Beschreibung:

Hier wird die Drehzahl des Lüfters ermittelt.
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef FAN_H_
	#define FAN_H_
	
// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "init.h"

// ----------------------------------------------------------------------------//
// 	Definition (Einstellungen):
// ----------------------------------------------------------------------------//

	#define FAN_SPEED_DDR			DDRB			//DDR festlegen
	#define FAN_SPEED_PORT			PORTB			//Port festlegen
	#define FAN_SPEED_PIN			PB4				//Pin festlegen
	#define FAN_SPEED_PIN_GROUP		PINB			//PIN Gruppe festlegen

	#define FAN_DDR					DDRB			//DDR festlegen
	#define FAN_PORT				PORTB			//Port festlegen
	#define FAN_PIN					PB4				//Pin festlegen
	#define FAN_PIN_GROUP			PINB			//PIN Gruppe festlegen

// ----------------------------------------------------------------------------//
// 	Macros
// ----------------------------------------------------------------------------//

	#define FAN_SPEED_PIN_SET_OUTPUT	FAN_SPEED_DDR |= (1 << FAN_SPEED_PIN);		//PIN als Ausgang schalten
	#define FAN_SPEED_PIN_SET_INPUT		FAN_SPEED_DDR &= ~(1 << FAN_SPEED_PIN);		//PIN als Eingang schalten
	#define FAN_SPEED_PIN_SET_LOW		FAN_SPEED_PORT &= ~(1 << FAN_SPEED_PIN);	//Ausgang auf Low setzen
	#define FAN_SPEED_PIN_SET_HIGH		FAN_SPEED_PORT |= (1 << FAN_SPEED_PIN);		//Ausgang auf High setzen
	#define FAN_SPEED_PIN_READING		FAN_SPEED_PIN_GROUP & (1 << FAN_SPEED_PIN);	//Pin auslese
	
	#define FAN_PIN_SET_OUTPUT			FAN_DDR |= (1 << FAN_PIN);					//PIN als Ausgang schalten
	#define FAN_PIN_SET_INPUT			FAN_DDR &= ~(1 << FAN_PIN);					//PIN als Eingang schalten
	#define FAN_PIN_SET_LOW				FAN_PORT &= ~(1 << FAN_PIN);				//Ausgang auf Low setzen
	#define FAN_PIN_SET_HIGH			FAN_PORT |= (1 << FAN_PIN);					//Ausgang auf High setzen
	#define FAN_PIN_READING				FAN_PIN_GROUP & (1 << FAN_PIN);				//Pin auslese

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//



// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /* FAN_H_ */