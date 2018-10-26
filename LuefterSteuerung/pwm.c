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
//		void pwm_init (unsigned char pwm_mode, unsigned char output_channel)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Auswahl des PWM Mode. Ob Fast PWM oder Pahse correct.
//						 Auswahl welcher PIN benutzt wird.
//	* Rückgabewert	   : -
//
//	* Beschreibung:		
//	
//		Auswahl des PWM Modes und starten des PWM. Der start beginnt mit 100%
//		der DutyCycle = volle Spg.
//
//		Die Frequenz wie schnell die Periode ist:
//		f = Taktfrequenz/(2 * Prescaler * 256) in Hz
//
//		output_channel
//		1 = OCR0A / 2 = OCR0B / 3 = OCR1A / 4 = OCR1B 
//
// ----------------------------------------------------------------------------//

	void pwm_init (unsigned char pwm_mode, unsigned char output_channel)
	{
		#ifdef ATMEGA328P			
			switch (output_channel)
			{
				//OCR0A auf PIN D6
				case 1: DDRD |= (1 << PD6);					//PIN als Ausgang schalten
						OCR0A = 128;						//DutyCycle auf 50%
						if (pwm_mode == FASTPWM_8BIT)
						{
							TCCR0A = (1 << COM0A1);			//nicht Invertierter Modus
							TCCR0A |= (1 << WGM01) | (1 << WGM00);//fast PWM Mode
							TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
						}
						if (pwm_mode == PHASECORRECT_8BIT)
						{
							TCCR0A = (1 << COM0A1);			//nicht Invertierter Modus
							TCCR0A |= (1 << WGM00);			//PWM Phase Corrected Mode
							TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
						}	
						break;
				//OCR0B auf PIN D5					
				case 2: DDRD |= (1 << PD5);					//PIN als Ausgang schalten
						OCR0A = 128;						//DutyCycle auf 50%
						if (pwm_mode == FASTPWM_8BIT)
						{
							TCCR0A = (1 << COM0B1);			//nicht Invertierter Modus
							TCCR0A |= (1 << WGM01) | (1 << WGM00);//fast PWM Mode
							TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
						}
						if (pwm_mode == PHASECORRECT_8BIT)
						{
							TCCR0A = (1 << COM0B1);			//nicht Invertierter Modus
							TCCR0A |= (1 << WGM00);			//PWM Phase Corrected Mode
							TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
						}
						break;
				//OCR1A auf PIN B1
				case 3:	DDRB |= (1 << PB1);					//PIN als Ausgang schalten
						OCR1A = 128;						//DutyCycle auf 50%
						if (pwm_mode == FASTPWM_8BIT)
						{
							TCCR1A = (1 << COM1A1);			//nicht Invertierter Modus
							TCCR1B |= (1 << WGM12)|(1 << WGM10);//fast PWM Mode
							TCCR1B = (1 << CS11);			//Prescaler auf 8 und PWM startet
						}
						if (pwm_mode == PHASECORRECT_8BIT)
						{
							TCCR1A = (1 << COM1A1);			//nicht Invertierter Modus
							TCCR1B |= (1 << WGM10);			//PWM Phase Corrected Mode
							TCCR1B = (1 << CS11);			//Prescaler auf 8 und PWM startet
						}
						break;
				//OCR1B auf PIN B2
				case 4: DDRB |= (1 << PB2);					//PIN als Ausgang schalten
						OCR1B = 128;						//DutyCycle auf 50%
						if (pwm_mode == FASTPWM_8BIT)
						{
							TCCR1A = (1 << COM1B1);			//nicht Invertierter Modus
							TCCR1B |= (1 << WGM12)|(1 << WGM10);//fast PWM Mode
							TCCR1B = (1 << CS11);			//Prescaler auf 8 und PWM startet
						}
						if (pwm_mode == PHASECORRECT_8BIT)
						{
							TCCR1A = (1 << COM1B1);			//nicht Invertierter Modus
							TCCR1B |= (1 << WGM10);			//PWM Phase Corrected Mode
							TCCR1B = (1 << CS11);			//Prescaler auf 8 und PWM startet
						}
						break;
			}
		#endif

		#ifdef ATTINY44
			switch (output_channel)
				{
					//OCR0A auf PIN B2
					case 1: DDRB |= (1 << PB2);					//PIN als Ausgang schalten
							OCR0A = 128;						//DutyCycle auf 50%
							if (pwm_mode == FASTPWM_8BIT)
							{
								TCCR0A = (1 << COM0A1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM01) | (1 << WGM00);//fast PWM Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}
							if (mode == PHASECORRECT_8BIT)
							{
								TCCR0A = (1 << COM0A1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM00);			//PWM Phase Corrected Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}	
							break;
					//OCR0B auf PIN PA7					
					case 2: DDRA |= (1 << PA7);					//PIN als Ausgang schalten
							OCR0A = 128;						//DutyCycle auf 50%
							if (pwm_mode == FASTPWM_8BIT)
							{
								TCCR0A = (1 << COM0B1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM01) | (1 << WGM00);//fast PWM Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}
							if (pwm_mode == PHASECORRECT_8BIT)
							{
								TCCR0A = (1 << COM0B1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM00);			//PWM Phase Corrected Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}
							break;
					//OCR1B auf PIN PA5
					case 4: DDRA |= (1 << PA5);					//PIN als Ausgang schalten
							OCR1B = 128;						//DutyCycle auf 50%
							if (pwm_mode == FASTPWM_8BIT)
							{
								TCCR1A = (1 << COM1B1);			//nicht Invertierter Modus
								TCCR1A |= (1 << WGM10);			//fast PWM Mode
								TCCR1B = (1 << WGM12);
								TCCR1B |= (1 << CS11);			//Prescaler auf 8 und PWM startet
							}
							if (pwm_mode == PHASECORRECT_8BIT)
							{
								TCCR1A = (1 << COM1B1);			//nicht Invertierter Modus
								TCCR1A |= (1 << WGM10);			//PWM Phase Corrected Mode
								TCCR1B = (1 << CS11);			//Prescaler auf 8 und PWM startet
							}
							break;
				}
		#endif

		#ifdef ATTINY13
			switch (output_channel)
				{
					//OCR0A auf PIN B0
					case 1: DDRB |= (1 << PB0);					//PIN als Ausgang schalten
							OCR0A = 128;						//DutyCycle auf 50%
							if (pwm_mode == FASTPWM_8BIT)
							{
								TCCR0A = (1 << COM0A1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM01) | (1 << WGM00);//fast PWM Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}
							if (pwm_mode == PHASECORRECT_8BIT)
							{
								TCCR0A = (1 << COM0A1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM00);			//PWM Phase Corrected Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}	
							break;
					//OCR0B auf PIN PB1					
					case 2: DDRB |= (1 << PB1);					//PIN als Ausgang schalten
							OCR0A = 128;						//DutyCycle auf 50%
							if (pwm_mode == FASTPWM_8BIT)
							{
								TCCR0A = (1 << COM0B1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM01) | (1 << WGM00);//fast PWM Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}
							if (pwm_mode == PHASECORRECT_8BIT)
							{
								TCCR0A = (1 << COM0B1);			//nicht Invertierter Modus
								TCCR0A |= (1 << WGM00);			//PWM Phase Corrected Mode
								TCCR0B = (1 << CS01);			//Prescaler auf 8 und PWM startet
							}
							break;
				}
		#endif
	}

// ----------------------------------------------------------------------------//
//	void pwm_output (unsigned char duty_cycle unsigned char output_channel)	
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: duty_cycle in Prozent (50% Rechtecksignal)
//	* Rückgabewert	   : -
//
//	* Beschreibung:		
//	
//		Erzeugen eines Rechtecksignals.
//		Formel für die Umwandlung der DutyCycle:
//		Vout = duty / 255 * 5V
//
//		output_channel
//		1 = OCR0A / 2 = OCR0B / 3 = OCR1A / 4 = OCR1B 	
// ----------------------------------------------------------------------------//

	void pwm_output (unsigned char duty_cycle, unsigned char output_channel)
	{
		unsigned char OCR;

		OCR = (255 * duty_cycle) / 100;	//Umrechnung von Prozent in DEZ-Wert

		#ifdef ATMEGA328P
			switch (output_channel)
			{
				case 1: OCR0A = OCR;
						break;
				case 2: OCR0B = OCR;
						break;
				case 3: OCR1A = OCR;
						break;
				case 4: OCR1B = OCR;
						break;
			}
		#endif

		#ifdef ATTINY44
			switch (output_channel)
			{
				case 1: OCR0A = OCR;
						break;
				case 2: OCR0B = OCR;
						break;
				case 4: OCR1B = OCR;
						break;
			}
		#endif

		#ifdef ATTINY13
			switch (output_channel)
			{
				case 1: OCR0A = OCR;
						break;
				case 2: OCR0B = OCR;
						break;
			}
		#endif
	}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//