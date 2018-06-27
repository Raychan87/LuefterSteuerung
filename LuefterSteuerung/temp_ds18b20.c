/********************************************************************************
Temperatur Funktion
*********************************************************************************
File: temp_ds18b20.c
Version: 0.3
Author: RayChan
Für: Temperatur Sensor DS18B20
Beschreibung:

In dem File befinden sich die Funktionen für den DS18b20 Sensor.
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "temp_ds18b20.h"

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
		TEMP_DS_PIN_OUTPUT					//PIN als Ausgang schalten
		
		_delay_us(490);						//Mindestens 480us warten
		
		TEMP_DS_PIN_SET_HIGH				//PIN auf High setzen
		TEMP_DS_PIN_INPUT					//PIN als Eingang schalten
		
		_delay_us(40);						//DS18B20 wartet nach High auf Bus 15-60us ab
		
		request = TEMP_DS_PIN_READING		//Speichern des Signals		
		
		_delay_us(450);						//Warten auf das Ende der Komunikation
	
		return (request);
	}

// ----------------------------------------------------------------------------//
//						void OneWire_SendeBit (uint8_t value)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Bei High wird ein Bit gesendet.
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	
//	Die Funktion schreibt ein Bit auf dem BUS.
// ----------------------------------------------------------------------------//

	void OneWire_SendeBit (uint8_t value)
	{
		TEMP_DS_PIN_SET_LOW				//Ausgang auf Low setzen
		TEMP_DS_PIN_OUTPUT				//PIN als Ausgang schalten
	
		if(value)
		{
			_delay_us(1);				//warte 1us und...
			TEMP_DS_PIN_SET_HIGH		//PIN auf High setzen
			TEMP_DS_PIN_INPUT			//PIN als Eingang schalten
		}
		
		_delay_us(100);					//Warten auf das Ende der Übertragung
	
		TEMP_DS_PIN_SET_HIGH			//PIN auf High setzen
		TEMP_DS_PIN_INPUT				//PIN als Eingang schalten	
	}

// ----------------------------------------------------------------------------//
//						void ow_wr_byte (uint8_t val)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	One_Wire_Write_Byte
//	This function will write a complete byte on the bus.
// ----------------------------------------------------------------------------//

void ow_wr_byte (uint8_t val)
{
	uint8_t i, mask = 1;

	// write the byte by sending eight bits (LSB first)
	for (i=0; i<8; i++)
	{
		ow_wr_bit(val & mask);
		mask = (mask << 1);
	}
}

// ----------------------------------------------------------------------------//
//							uint8_t ow_rd_bit (void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	One_Wire_Read_Bit
//	This function will read one single bit from the bus.
// ----------------------------------------------------------------------------//

uint8_t ow_rd_bit (void)
{
	uint8_t rec;

	// perform a very short low impuls
	TRIS_DQ = 0;					// config the DQ-IO as output (-> low)
	TRIS_DQ = 1;                    // config the  DQ-IO as input (high-z -> pull up)

	__delay_us(15);
	rec = DQ;                       // read the level on DQ (this is the read bit)
	__delay_us(105);                // wait for end of slot

	return(rec);
}

// ----------------------------------------------------------------------------//
//							uint8_t ow_rd_byte (void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	One_Wire_Read_Byte
//	This function will read a complete byte from the bus.
// ----------------------------------------------------------------------------//

uint8_t ow_rd_byte (void)
{
	uint8_t value = 0 , i;

	// read the byte by reading eight bits (LSB first)
	for(i=0; i<8; i++)
	{
		if ( ow_rd_bit() )
		{
			value |= 0x01 << i;
		}
	}

	return(value);
}

// ----------------------------------------------------------------------------//
//							void ow_skip_rom(void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	One_Wire_Skip_Rom
//	This function sends the skip rom command and calls all connected components.
// ----------------------------------------------------------------------------//

void ow_skip_rom(void)
{
	ow_wr_byte(0xCC);
}

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//