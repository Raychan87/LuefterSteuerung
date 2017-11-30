/********************************************************************************
 L�fter Steuerung
*********************************************************************************
File: init.h
Version: 0.1
Author: RayChan
Beschreibung:


Der Verwendete Mikroprozessor dieses Projektes:
// ----------------------------------------------------------------------------
// uC: ATtiny13-20PU
// Takt: 16 MHz
// Max. Takt: 20 MHz
// ROM: 1 Kilobytes
// RAM: 64 Bytes
// EEPROM: 64 Bytes
// ----------------------------------------------------------------------------
********************************************************************************/

// ----------------------------------------------------------------------------//
//	Header-Definition:
// ----------------------------------------------------------------------------//

#ifndef INIT_H_
	#define INIT_H_

// ----------------------------------------------------------------------------//
// Definition (Einstellungen):
// ----------------------------------------------------------------------------//

	#define F_CPU				16000000				//CPU Takt: 16MHz
	//#define BAUDRATE			9600					//Baudrate

// ----------------------------------------------------------------------------//
// Definition:
// ----------------------------------------------------------------------------//


// ----------------------------------------------------------------------------//
//	Globale Variablen:
// ----------------------------------------------------------------------------//

	//volatile unsigned char i;

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include <avr\io.h>									//AVR Register und Konstantendefinitionen
	#include <avr\interrupt.h>							//AVR Interrupt Vektoren
	#include <avr\portpins.h>							//Definierte Port Beschriftungen
	//#include <avr\pgmspace.h>							//LCD ben�tigt
	//#include <util\delay.h>								//Wartezeit schleife
	//#include <stdint.h>									//Strings
	//#include <stdio.h>									//sprintf()

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /* INIT_H_ */