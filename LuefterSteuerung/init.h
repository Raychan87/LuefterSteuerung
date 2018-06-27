/********************************************************************************
 Lüfter Steuerung
*********************************************************************************
File: init.h
Version: 0.4
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

	#define F_CPU				16000000	//CPU Takt: 16MHz
	//#define BAUDRATE			9600		//Baudrate

// ----------------------------------------------------------------------------//
// Definition:
// ----------------------------------------------------------------------------//
	
	//Mikrocontroller Auswahl (Nur ein MC auswählen!!!)
	#define ATTINY13
    //#define ATMEGA328P
	//#define ATTINY44

	/* Temperatursensor Auswahl */
	#define DS18B20
	#define MCP9700

// ----------------------------------------------------------------------------//
//	Globale Variablen:
// ----------------------------------------------------------------------------//

	//volatile unsigned char i;

// ----------------------------------------------------------------------------//
//	Header-Dateien:
// ----------------------------------------------------------------------------//

	#include <avr\io.h>						//AVR Register und Konstantendefinitionen
	#include <avr\interrupt.h>				//AVR Interrupt Vektoren
	#include <avr\portpins.h>				//Definierte Port Beschriftungen
	#include <util\delay.h>					//Wartezeit Schleife
	//#include <stdint-gcc.h>					//

	#include "temp_ds18x20.h"				//Temperatur Sensor DS18X20
   	#include "temp_mcp9700.h"              	//Temperatur Sensor MCP9700 Funktion
   	#include "adc_wandler.h"               	//ADC Wandler
	#include "fan.h"						//Lüfter Funktionen
	#include "pwm.h"						//Timer (PWM) Funktion

	//#include <avr\pgmspace.h>				//LCD benötigt
	//#include <stdint.h>					//Strings
	//#include <stdio.h>					//sprintf()

// ----------------------------------------------------------------------------//
// 	Ende
// ----------------------------------------------------------------------------//

#endif /* INIT_H_ */
