/********************************************************************************
 ADC_Wandler Funktion
*********************************************************************************
File:
Version: 1.5
Author: RayChan
Beschreibung:

Die Datei enthält die Funktionen der ADC-Routine.
Für ATmega328P, ATtiny44 und ATtiny13
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

#include "adc_wandler.h"

// ----------------------------------------------------------------------------//
//							void adc_init(unsigned char referenzspg)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Die Art der benutzten Referenzspannung in Ziffern
//                       referenzspg:
//							0 = AREF als Referenz
//							1 = AVcc als Referenz with external capacitor at AREF pin
//							2 = Internal 1.1V als Referenz
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	Einstellen und einschalten des 10-Bits AD-Wandlers
//
// ----------------------------------------------------------------------------//

	void adc_init( unsigned char referenzspg)
	{
        #ifdef ATMEGA328P
		    if (referenzspg == AREF_REFERENZ)
		    {
			    ADMUX = 0x00;							//AREF Referenz
		    }
		    if (referenzspg == AVCC_REFERENZ)
		    {
			    ADMUX = (1<<REFS0);						//AVCC als Referenzspannung nutzen
		    }
		    if (referenzspg == INTERN_REFERENZ)
		    {
			    ADMUX = (1<<REFS0)|(1<<REFS1);			//Internal 1.1V	Referenz
		    }
        #endif

        #ifdef ATTINY44
            if (referenzspg == AREF_REFERENZ)
             {
                 ADMUX = (1<<REFS0);                    //AREF Referenz
             }
             if (referenzspg == AVCC_REFERENZ)
            {
                ADMUX = 0x00;                           //AVCC als Referenzspannung nutzen
            }
            if (referenzspg == INTERN_REFERENZ)
            {
                ADMUX = (1<<REFS1);                     //Internal 1.1V	Referenz
            }
        #endif

        #ifdef ATTINY13
            if (referenzspg == INTERN_REFERENZ)
            {
                ADMUX = (1<<REFS0);                     //Internal 1.1V Referenz
            }
            if (referenzspg == AVCC_REFERENZ)
            {
                ADMUX = 0x00;                           //AVCC als Referenzspannung nutzen
            }
        #endif
		ADCSRA = (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);	    //Frequenzvorteiler 128 ==> 16Mhz/128 = 125000Khz (sollte zwischen 50kHz-200kHz liegen)
		ADCSRA |= (1<<ADEN);						    //ADC aktivieren

		/* nach Aktivieren des ADC wird ein "Dummy-Readout" empfohlen, man liest
		 also einen Wert und verwirft diesen, um den ADC "warmlaufen zu lassen" */

		ADCSRA |= (1<<ADSC);						    //eine ADC-Wandlung
		while (ADCSRA & (1<<ADSC));					    //auf Abschluss der Konvertierung warten

		/* ADCW muss einmal gelesen werden, sonst wird Ergebnis der nächsten
		Wandlung nicht übernommen. */
	}

// ----------------------------------------------------------------------------//
//				unsigned char ADC_lesen(unsigned char Kanal)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Der Kanal ist der ADC PIN als Ziffer welcher Analog
//						 eingelesen werden soll.
//	* Rückgabewert	   : Der vom ADC Pin angegebene Analogwert wird als unsigned
//						 char zurückgegeben
//
//	* Beschreibung:
//
//	Die Funktionsroutine ist dafür da einen Analogen Wert von einen Bestimmten
//  Pin auszulesen und zurückzugeben.
//  Er bleibt solange in der Funktionsroutine bis eine Wandlung abgeschlossen ist.
//
// ----------------------------------------------------------------------------//


	unsigned int ADC_lesen(unsigned char Kanal)		//aus bestimmten Kanal (ADC PIN) Analogwert auslesen
	{
        #ifdef ATMEGA328P
		    ADMUX = (ADMUX & ~(0x1F)) | (Kanal & 0x1F);	//Kanal waehlen
        #endif

        #ifdef ATTINY44
            ADMUX = (ADMUX & ~(0x3F)) | (Kanal & 0x3F);//Kanal waehlen
        #endif

        #ifdef ATTINY13
            ADMUX = (ADMUX & ~(0x03)) | (Kanal & 0x03);	//Kanal waehlen
        #endif

        ADCSRA |= (1<<ADSC);						//eine Wandlung "single conversion"
        while (ADCSRA & (1 << ADSC));				//auf Abschluss der Konvertierung warten

        return ADCW;								//Analogen Wert zurück geben
	}

// ----------------------------------------------------------------------------//
//	Ende
// ----------------------------------------------------------------------------//
