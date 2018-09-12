/********************************************************************************
Temperatur Funktion
*********************************************************************************
Author		: RayChan
WebSeite	: https://FotoTour-und-Technik.de
GitHub		: https://github.com/Raychan87

File		: temp_mcp9700.c
Version		: 1.1
Status		: in testing

In der Datei ist für den Temperaturfühler MCP9700 die benötigten Funktionen
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "temp_mcp9700.h"

// ----------------------------------------------------------------------------//
//				void temp_mcp_init(void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	Diese Funktion stellt den Eingangs Pin ein und startet den AD-Wandler
// ----------------------------------------------------------------------------//

	void temp_mcp_init(void)					//Temperaturfühler Vorbereitung
	{
		TEMP_MCP_DDR &=	~(1 << TEMP_MCP_PIN);	//Pin als Eingang schalten
		adc_init(MCP_REF_MODI);					//AD-Wandler einschalten und Festlegung der Referenzspg.
	}

// ----------------------------------------------------------------------------//
//				float temp_mcp(void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : Die Funktion gibt den Temperaturwert als Float und in
//			     Grad zurück
//	* Beschreibung:
//
//	In der Funktion werden 3 Analoge Werte vom Temperaturfühler eingelesen und mit
//	einer Kalibrierten Formel auf der Seite:
//  	http://www.instructables.com/id/How-to-calibrate-a-cheap-temperature-sensor/step3/Calibration/
//	(Stand 12/2016) Berechnet.
//  	Aus diesen wird noch der Mittelwert gebildet und in Grad in Floatwert zurückgegeben
//
//
// ----------------------------------------------------------------------------//

	float temp_mcp(void)					//Temperatur einholen
	{
		float merker_temp = 0;				//Variable für Temperatur speichern
		unsigned char i;

		for (i = 1; i <= 3 ; i++)			//3 Messwerte einholen
		{
			/*	Temperatur auslesen und Formel für genaue Kalibrierung der Temperaturwerte */
			merker_temp = merker_temp + (((float)ADC_lesen(TEMP_MCP_PIN)*MCP_VREF/1024)-0.4802)/0.01;	//0.4802
			_delay_ms(20);					//Kurze Pause
		}
		merker_temp = merker_temp / 3;		//Durchschnitt der 3 Temperaturwerte bilden
		return merker_temp;					//Temperaturwert ausgeben
	}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//
