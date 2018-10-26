/********************************************************************************
PWM Funktion
*********************************************************************************
Author		: RayChan
WebSeite	: https://FotoTour-und-Technik.de
GitHub		: https://github.com/Raychan87

File		: pwm.c
Version		: 0.5
Status		: in build

Beschreibung:

Hier wird der Timer eingestellt und ein PWM Signal erzeugt.
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef PWM_H_
	#define PWM_H_
	
// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "init.h"

// ----------------------------------------------------------------------------//
// 	Definition (Einstellungen):
// ----------------------------------------------------------------------------//

 	#define PWM_DDR				DDRB			//DDR festlegen
    #define PWM_PORT			PORTB			//Port festlegen
    #define PWM_PIN				PB4				//Pin festlegen
	#define PWM_PIN_GROUP		PINB			//PIN Gruppe festlegen

	#define FASTPWM_8BIT		0
	#define PHASECORRECT_8BIT 	1

// ----------------------------------------------------------------------------//
// 	Macros
// ----------------------------------------------------------------------------//

	#define PWM_PIN_SET_OUTPUT	PWM_DDR |= (1 << PWM_PIN);	//PIN als Ausgang schalten
	#define PWM_PIN_SET_HIGH	PWM_PORT |= (1 << PWM_PIN); //Ausgang auf High setzen

// ----------------------------------------------------------------------------//
// 	Funktions Prototypen:
// ----------------------------------------------------------------------------//

	extern void pwm_init (unsigned char pwm_mode, unsigned char output_channel)//PWM Einstellen
	/* 	pwm_mode:
			0 = FASTPWM_8BIT = Fast PWM mode in 8-Bit
			1 = PHASECORRECT_8BIT = PWM Phase correct in 8-Bit
		output_channel:
			1 = OCR0A / 2 = OCR0B / 3 = OCR1A / 4 = OCR1B 
	*/
	extern void pwm_output (unsigned char duty_cycle unsigned char output_channel) 	//PWM Signal erzeugen
	/* 	DutyCycle:
			z.B. 50 = 50% Rechtecksignal
		output_channel:
			1 = OCR0A / 2 = OCR0B / 3 = OCR1A / 4 = OCR1B 
	*/
	
// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /* PWM_H_ */