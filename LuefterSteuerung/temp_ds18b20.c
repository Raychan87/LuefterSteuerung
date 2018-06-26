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
//							uint8_t ow_mri (void)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	One_Wire_Master-Reset-Impuls
//	This function will release the master reset impuls and checks if there is at
//  least one 1-wire-component connected to the bus (0) or not (1).
// ----------------------------------------------------------------------------//

uint8_t ow_mri (void)
{
	uint8_t rec;

	LAT_DQ = 0;						// set the (I)O to low level
	TRIS_DQ = 0;                    // config the DQ-IO as output (-> low)
	__delay_us(490);				// delay of >480 us
	TRIS_DQ = 1;                    // config the  DQ-IO as input (high-z -> pull up)
	__delay_us(40);
	rec = DQ;                       // read the level (if low, slave available)
	__delay_us(450);                // wait for end of slot

	return (rec);
}

// ----------------------------------------------------------------------------//
//						void ow_wr_bit (uint8_t val)
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
//	One_Wire_Write_Bit
//	This function will write one single bit on the bus.
// ----------------------------------------------------------------------------//

void ow_wr_bit (uint8_t val)
{
	LAT_DQ = 0;						// set the (I)O to low level
	TRIS_DQ = 0;                    // config the DQ-IO as output (-> low)

	if(val)                    		// if the bit to transfer is a "1"
	{
		__delay_us(1);				// wait 1 us and..
		TRIS_DQ = 1;                // ..config the  DQ-IO as input (high-z -> pull up)
	}

	__delay_us(100);                // wait for end of slot

	TRIS_DQ = 1;                    // config the  DQ-IO as input (high-z -> pull up)
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