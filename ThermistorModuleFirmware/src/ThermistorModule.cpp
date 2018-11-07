#include "ThermistorModule.hpp"
#include <math.h>
#include <Arduino.h>

int nActualConversionMode = TEMP_CELSIUS_MODE;

/*
 *    Funzione che imposta i parametri di inizializzazione del modulo di temperatura
 */
void ThermistorModuleSetup( int nGate, int nMode )
{
	// Imposto il PIN di entrata ad Arduino a cui è collegato il
	// cavo del segnale del modulo del termistore
	pinMode( nGate, INPUT );

	nActualConversionMode = nMode;
}

/*
 *    Funzione che ferma restituisce il valore di temperatura letto dal termistore
 *	  nell'unità di misura attualmente impostata
 */
double ThermistorModuleGetTemp( int nSensorPin )
{
	int nValFromModule = 0;
	double dTemperature =  0;

	nValFromModule = analogRead( nSensorPin );

	dTemperature = log( 10000.0 *( ( 1024.0 / nValFromModule - 1 ) ) );

	switch ( nActualConversionMode )
	{
		case TEMP_KELVIN_MODE:

			dTemperature = 1 / ( 0.001129148 + ( 0.000234125 + ( 0.0000000876741 * dTemperature * dTemperature ) ) * dTemperature ); // Kelvin
			break;

		case TEMP_CELSIUS_MODE:

			dTemperature = 1 / ( 0.001129148 + ( 0.000234125 + ( 0.0000000876741 * dTemperature * dTemperature ) ) * dTemperature );  // Kelvin
			dTemperature = dTemperature - 273.15; // Kelvin to Celcius
			break;

		case TEMP_FAHRENHEIT_MODE:

			dTemperature = 1 / ( 0.001129148 + ( 0.000234125 + ( 0.0000000876741 * dTemperature * dTemperature ) ) * dTemperature );  // Kelvin
			dTemperature = dTemperature - 273.15; // Kelvin to Celcius
			dTemperature = ( dTemperature * 9.0 ) / 5.0 + 32.0; // Celcius to Fahrenheit
			break;

		default:
			break;
	}

	return dTemperature;
}
