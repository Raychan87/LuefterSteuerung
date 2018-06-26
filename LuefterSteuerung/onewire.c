/********************************************************************************
1-Wire Funktion
*********************************************************************************
File: onewire.c
Version: 0.2
Author: RayChan
Beschreibung:


********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include "onewire.h"
	
// ----------------------------------------------------------------------------//
//							OneWireInit( void )
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   :  0 - OK, 1 - communication error 
//
//	* Beschreibung:
//
// ----------------------------------------------------------------------------//

unsigned char OneWireInit()					//Init one wire bus
{
	unsigned char Response = 0;
	unsigned char sreg_tmp = SREG;			//Store status register
	
	cli();									//Deaktivieren der Interrupts

	TEMP_DS_PORT |= TEMP_DS_PIN_MASK;		//Write 1 to output
	TEMP_DS_DDR |= TEMP_DS_PIN_MASK;		//Set port to output
	TEMP_DS_PORT &= ~TEMP_DS_PIN_MASK;		//Write 0 to output

	_delay_us( 600 );

	TEMP_DS_DDR &= ~TEMP_DS_PIN_MASK;		//Set port to input

	_delay_us( 100 );

	Response = TEMP_DS_PIN & TEMP_DS_PIN_MASK; //Read input 

	_delay_us( 200 );

	TEMP_DS_PORT |= TEMP_DS_PIN_MASK;		//Write 1 to output
	TEMP_DS_DDR |= TEMP_DS_PIN_MASK;		//Set port to output

	_delay_us( 600 );

	SREG = sreg_tmp;						//Restore status register
	
	sei();									//Aktivieren der Interrupts

	return Response != 0; //Return logical value ( 0 - OK, 1 - communication error )
}

// ----------------------------------------------------------------------------//
//							OneWireWrite( unsigned char )
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: 1 or 0 to write on OneWire bus
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
// ----------------------------------------------------------------------------//

void OneWireWrite( unsigned char Value )		//Write 1 or 0 to one wire bus
{
	unsigned char sreg_tmp = SREG;				//Store status register

	cli();										//Deaktivieren der Interrupts

	TEMP_DS_PORT |= TEMP_DS_PIN_MASK;			//Write 1 to output
	TEMP_DS_DDR |= TEMP_DS_PIN_MASK;			//Set port to output
	TEMP_DS_PORT &= ~TEMP_DS_PIN_MASK;			//Write 0 to output

	if ( Value != 0 )   //Change delay amounts according to given value
	_delay_us( 8 );
	else
	_delay_us( 80 );

	TEMP_DS_PORT = TEMP_DS_PIN_MASK; 

	if ( Value != 0 )
	_delay_us( 80 );
	else
	_delay_us( 2 );

	SREG = sreg_tmp;
	
	sei();										//Aktivieren der Interrupts
}

// ----------------------------------------------------------------------------//
//						OneWireWriteByte( unsigned char )
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: Byte to write on OneWire bus
//	* Rückgabewert	   : -
//
//	* Beschreibung:
//
// ----------------------------------------------------------------------------//

void OneWireWriteByte( unsigned char Data )		//Write byte to one wire bus
{
	unsigned char i = 0;

	for ( i = 1; i != 0; i <<= 1 )				//Write byte in 8 single bit writes
	{
		OneWireWrite( Data & i );
	}
}

// ----------------------------------------------------------------------------//
//								OneWireRead( void )
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : 1 or 0 - value from OneWire bus
//
//	* Beschreibung:
//
// ----------------------------------------------------------------------------//

unsigned char OneWireRead( ) //Read one wire data bus
{
	unsigned char Response = 0;
	unsigned char sreg_tmp = SREG;				//Store status register

	cli();										//Deaktivieren der interrupts

	TEMP_DS_PORT |= TEMP_DS_PIN_MASK;			//Write 1 to output
	TEMP_DS_DDR |= TEMP_DS_PIN_MASK;			//Set port to output
	TEMP_DS_PORT &= ~TEMP_DS_PIN_MASK;			//Write 0 to output

	_delay_us( 2 );

	TEMP_DS_DDR &= ~TEMP_DS_PIN_MASK;			//Set port to input

	_delay_us( 5 );

	Response = TEMP_DS_PIN;						//Read input

	SREG = sreg_tmp;							//Restore status register

	_delay_us( 60 );

	sei();										//Aktivieren der Interrupts
	
	return ( Response & TEMP_DS_PIN_MASK) != 0; //Return logical value
}

// ----------------------------------------------------------------------------//
//							OneWireReadByte( void )
// ----------------------------------------------------------------------------//
//	* Übergabeparameter: -
//	* Rückgabewert	   : Byte read from OneWire bus
//
//	* Beschreibung:
//
// ----------------------------------------------------------------------------//

unsigned char OneWireReadByte( ) //Read byte from one wire data bus
{
	unsigned char Data = 0;
	unsigned char i = 0;

	for ( i = 1; i != 0; i <<= 1 )				//Read byte in 8 single bit reads
	{
		Data |= OneWireRead() * i;
	}

	return Data;
}

// ----------------------------------------------------------------------------//
// Ende
// ----------------------------------------------------------------------------//
