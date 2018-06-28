/********************************************************************************
Temperatur Funktion
*********************************************************************************
Author		: RayChan
WebSeite	: https://FotoTour-und-Technik.de
GitHub		: https://github.com/Raychan87

File		: temp_ds18x20.c
Version		: 0.3
Status		: in build

Beschreibung:

In dem File befinden sich die Funktionen für den ds18x20 Sensor.
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "temp_ds18x20.h"

// ----------------------------------------------------------------------------//
//					uint8_t OneWire_MasterResetImpuls (void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : 1 = mindesens ein Sensor am PIN / 0 = kein Sensor am Pin
//
//	* Beschreibung:
//
//	Der Master zieht den Bus auf Low für mindestens 480us. Der DS18x20 wartet
//	nun 15-60us ab um seine Antwort zu geben. Wenn 15-60us verstrichen sind
//	zieht der DS18x20 für 60-240us den Bus auf Low. Damit weiß der Master das
//	Mindestens ein Sensor angeschlossen ist.
// ----------------------------------------------------------------------------//

	uint8_t OneWire_MasterResetImpuls (void)
	{
		uint8_t request;
	
		TEMP_DS_PIN_SET_LOW					//Ausgang auf Low setzen
		TEMP_DS_PIN_SET_OUTPUT				//PIN als Ausgang schalten
		
		_delay_us(490);						//Mindestens 480us warten
		
		TEMP_DS_PIN_SET_HIGH				//PIN auf High setzen
		TEMP_DS_PIN_SET_INPUT				//PIN als Eingang schalten
		
		_delay_us(40);						//ds18x20 wartet nach High auf Bus 15-60us ab
		
		request = TEMP_DS_PIN_READING		//Speichern des Signals		
		
		_delay_us(450);						//Warten auf das Ende der Komunikation
	
		return (request);
	}

// ----------------------------------------------------------------------------//
//					void OneWire_TransmitBit (uint8_t TransmitBit)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Das Bit was gesendet werden soll.
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	
//	Die Funktion schreibt ein Bit zum Sensor DS18x20.
// ----------------------------------------------------------------------------//

	void OneWire_TransmitBit (uint8_t TransmitBit)
	{
		TEMP_DS_PIN_SET_LOW				
		TEMP_DS_PIN_SET_OUTPUT			
	
		if(TransmitBit)		//Senden einer "1"
		{
			_delay_us(1);					//warte 1 mikrosek. warten...
			
			TEMP_DS_PIN_SET_HIGH		
			TEMP_DS_PIN_SET_INPUT		
			
			_delay_us(100);					//Warten auf das Ende der Übertragung
		}
		else				//Senden einer "0"
		{
			_delay_us(100);					//lässt das Potenzial auf low
			
			TEMP_DS_PIN_SET_HIGH		
			TEMP_DS_PIN_SET_INPUT		
		}
	}

// ----------------------------------------------------------------------------//
//				void OneWire_TransmitByte (uint8_t TransmitByte)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Das Byte das gesendet werden soll.
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	Die Funktion Sendet ein Byte auf den Bus.
// ----------------------------------------------------------------------------//

	void OneWire_TransmitByte (uint8_t TransmitByte)
	{
		uint8_t i, maske = 0b00000001;

		//Sendet jedes Bit einzeln und das LSB als erstes
		for (i = 0; i < 8; i++ )			//jedes Bit von 8 Bits wird einzeln gesendet
		{
			OneWire_TransmitBit(TransmitByte & maske);
			maske = (maske << 1);			//Links Schiften
		}
	}

// ----------------------------------------------------------------------------//
//						uint8_t OneWire_ReceiveBit (void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   :  Das Bit was empfangen wird.
//
//	* Beschreibung:
//
//	Die Funktion Empfängt ein Bit vom Sensor DS18x20
// ----------------------------------------------------------------------------//

	uint8_t OneWire_ReceiveBit (void)
	{
		uint8_t ReceiveBit;

		//Erzeugen eines sehr kurzen Impuls eines Low Bits
		TEMP_DS_PIN_SET_OUTPUT
		TEMP_DS_PIN_SET_LOW
		TEMP_DS_PIN_SET_HIGH
		TEMP_DS_PIN_SET_INPUT
	
		_delay_us(15);
		ReceiveBit = TEMP_DS_PIN_READING;	//Lesen des Empfangenden Bits
		_delay_us(105);						//Warten auf das Ende der Verbindung

		return(ReceiveBit);
	}

// ----------------------------------------------------------------------------//
//						uint8_t OneWire_RecevieByte (void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : Das Byte was empfangen wird.
//
//	* Beschreibung:
//
//	Die Funktion Empfängt ein Byte vom Sensor DS18x20
// ----------------------------------------------------------------------------//

	uint8_t OneWire_RecevieByte (void)
	{
		uint8_t RecevieByte = CLEAR , i;

		//Lesen des Bytes in Bit schritten (LSB als erstes)
		for( i = 0; i < 8; i++ )
		{
			if ( OneWire_ReceiveBit() )		//Bit lesen
			{
				RecevieByte |= 0x01 << i;	//Bit nach links schiften
			}
		}
		return(RecevieByte);
	}

// ----------------------------------------------------------------------------//
//							void OneWire_Skip_Rom(void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	Für die Verwendung von einen DS18x20 Sensor.
// ----------------------------------------------------------------------------//

	void OneWire_Skip_Rom(void)
	{
		OneWire_TransmitByte(0xCC);
	}

// ----------------------------------------------------------------------------//
//							void OneWire_adr_reading(void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	Unfertige Funktion!
// ----------------------------------------------------------------------------//

	void OneWire_adr_reading(void)
	{
		uint8_t Sensor = CLEAR, i;
		
		Sensor = OneWire_MasterResetImpuls();
		
		if (Sensor)
		{
			OneWire_TransmitByte(33);
			for ( i = 0; i < 9; i++)
			{
				ds18x20_adr[i] = OneWire_RecevieByte();
			}
		}
	}

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//