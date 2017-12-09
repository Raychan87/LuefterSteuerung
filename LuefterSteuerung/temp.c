/********************************************************************************
Temperatur Funktion
*********************************************************************************
File: temp.c
Version: 1.0
Author: David "RayChan" R�ckert
Beschreibung:

In der Datei ist f�r den Temperaturf�hler MCP9700 die ben�tigten Funktionen
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "temp.h"

// ----------------------------------------------------------------------------//
//							void temp_init(void)
// ----------------------------------------------------------------------------//
//	* �bergabeparameter: -
//	* R�ckgabewert	   : -
//
//	* Beschreibung:
//
//	Diese Funktion stellt den Eingangs Pin ein und startet den AD-Wandler
// ----------------------------------------------------------------------------//

	void temp_init(void)						//Temperaturf�hler Vorbereitung
	{
		TEMP_DDR &=	~(1 << TEMP_PIN);			//Pin als Eingang schalten
		adc_init(REF_MODI);						//AD-Wandler einschalten und Festlegung der Referenzspg.
	}

// ----------------------------------------------------------------------------//
//							float temp(void)
// ----------------------------------------------------------------------------//
//	* �bergabeparameter: -
//	* R�ckgabewert	   : Die Funktion gibt den Temperaturwert als Float und in
//						 Grad zur�ck
//	* Beschreibung:
//
//	In der Funktion werden 3 Analoge Werte vom Temperaturf�hler eingelesen und mit
//	einer Kalibrierten Formel auf der Seite:
//  http://www.instructables.com/id/How-to-calibrate-a-cheap-temperature-sensor/step3/Calibration/
//	(Stand 12/2016) Berechnet.
//  Aus diesen wird noch der Mittelwert gebildet und in Grad in Floatwert zur�ckgegeben
//
//
// ----------------------------------------------------------------------------//

	float temp(void)							//Temperatur einholen
	{
		float merker_temp = 0;					//Variable f�r Temperatur speichern
		unsigned char i;

		for (i = 1; i <= 3 ; i++)				//3 Messwerte einholen
		{
			/*	Temperatur auslesen und Formel f�r genaue Kalibrierung der Temperaturwerte */
			merker_temp = merker_temp + (((float)ADC_lesen(TEMP_PIN)*VREF/1024)-0.4802)/0.01;	//0.4802
			_delay_ms(20);						//Kurze Pause
		}
		merker_temp = merker_temp / 3;			//Durchschnitt der 3 Temperaturwerte bilden
		return merker_temp;						//Temperaturwert ausgeben
	}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//
