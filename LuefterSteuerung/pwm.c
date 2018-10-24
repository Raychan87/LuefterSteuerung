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

Die Datei enthält die Funktionen der PWM-Routine.
Für ATmega328P, ATtiny44 und ATtiny13
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "pwm.h"
	
// ----------------------------------------------------------------------------//
//							void pwm_init ( pwm_mode )	
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Auswahl des PWM Mode. Ob Fast PWM oder Pahse correct.
//	* Rückgabewert	   : -
//
//	* Beschreibung:		
//	
//		Auswahl des PWM Modes und starten des PWM. Der start beginnt mit 100%
//		der DutyCycle = volle Spg.
//
//		Die Frequenz wie schnell die Periode ist:
//		f = Taktfrequenz/(2 * Prescaler * 256) in Hz
// ----------------------------------------------------------------------------//

	void pwm_init (unsigned char pwm_mode)
	{
		#ifdef ATMEGA328P			
			PWM_PIN_SET_OUTPUT							//PIN als Ausgang schalten
			PWM_PIN_SET_HIGH							//PIN auf High setzen

			if (mode == FASTPWM_8BIT)
			{
				TCCR1A |= (1<<WGM10) | (1<<WGM12) | (1<<COM1A1); //fast PWM, 8-Bit | nicht invertierter modus
				TCCR1B |= (1<<CS11) | (1<<CS10);		//Prescaer 64 = Enable Counter
				OCR1A = 256; 							//Duty Cycle auf 100%
			}
			if (mode == PHASECORRECT_8BIT)
			{
				TCCR1A = (1<<WGM10) | (1<<COM1A1); 		//PWM Phase correct, 8-Bit
				TCCR1B = (1<<CS11) | (1<<CS10); 		//Prescaer 64 = Enable Counter
				OCR1A = 256; 							//Duty Cycle auf 100%
			}		
		#endif

		#ifdef ATTINY44
			PWM_PIN_SET_OUTPUT							//PIN als Ausgang schalten
			PWM_PIN_SET_HIGH							//PIN auf High setzen

			if (mode == FASTPWM_8BIT)
			{
				TCCR0A |= (1<<WGM00) | (1<<WGM01) | (1<<COM0A1); //fast PWM, 8-Bit | nicht invertierter modus
				TCCR0B |= (1<<CS00) | (1<<CS01);		//Prescaer 64 = Enable Counter
				OCRA = 256; 							//Duty Cycle auf 100%
			}
			if (mode == PHASECORRECT_8BIT)
			{
				TCCR0A |= (1<<WGM00) | (1<<COM0A1); 	//PWM Phase correct, 8-Bit
				TCCR0B |= (1<<CS00) | (1<<CS01); 		//Prescaer 64 = Enable Counter
				OCRA = 256; 							//Duty Cycle auf 100%
			}
		#endif

		#ifdef ATTINY13
			PWM_PIN_SET_OUTPUT							//PIN als Ausgang schalten
			PWM_PIN_SET_HIGH							//PIN auf High setzen

			if (mode == FASTPWM_8BIT)
			{
				TCCR0A |= (1<<WGM0) | (1<<WGM1) | (1<<COM01); //fast PWM, 8-Bit | nicht invertierter modus
				TCCR0B |= (1<<CS00) | (1<<CS01);		//Prescaer 64 = Enable Counter
				OCRA = 256; 							//Duty Cycle auf 100%
			}
			if (mode == PHASECORRECT_8BIT)
			{
				TCCR0A |= (1<<WGM0) | (1<<COM01); 	//PWM Phase correct, 8-Bit
				TCCR0B |= (1<<CS00) | (1<<CS01); 		//Prescaer 64 = Enable Counter
				OCRA = 256; 							//Duty Cycle auf 100%
			}
		#endif
	}

// ----------------------------------------------------------------------------//
//					void pwm_output ( unsigned char duty_cycle )	
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: duty_cycle in Prozent (50% Rechtecksignal)
//	* Rückgabewert	   : -
//
//	* Beschreibung:		
//	
//		Erzeugen eines Rechtecksignals.
//		Formel für die Umwandlung der DutyCycle:
//		Vout = duty / 255 * 5V
// ----------------------------------------------------------------------------//

	void pwm_output (unsigned char duty_cycle)
	{
		#ifdef ATMEGA328P
			OCR1A = (255 * duty_cycle) / 100;	//Umrechnung von Prozent in DEZ-Wert
		#endif

		#ifdef ATTINY44 | ATTINY13
			OCRA = (255 * duty_cycle) / 100;		//Umrechnung von Prozent in DEZ-Wert
		#endif
	}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//