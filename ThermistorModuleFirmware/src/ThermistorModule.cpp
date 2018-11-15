#include "ThermistorModule.hpp"
#include <math.h>
#include <Arduino.h>

int nActualTempUnit = TEMP_CELSIUS_MODE;

/*
 *    Funzione che imposta i parametri di inizializzazione del modulo di temperatura
 */
void ThermistorModuleSetup( int nTempSensorPin, int nTempUnit )
{
	// Imposto il PIN di entrata ad Arduino a cui è collegato il
	// cavo del segnale del modulo del termistore
	pinMode( nTempSensorPin, INPUT );

	nActualTempUnit = nTempUnit;
}

/*
 *    Funzione che ferma restituisce il valore di temperatura letto dal termistore
 *	  nell'unità di misura attualmente impostata
 */
double ThermistorModuleGetTemp( int nTempSensorPin )
{
	int nRawValFromModule = 0;
	double dTemperature =  0;

	// Leggo il valore grezzo della temperatura dal pin di input
	nRawValFromModule = analogRead( nTempSensorPin );

	// Converto il valore grezzo per la configurazione pull-down
	// dTemperature = log( 10000.0 * ( ( 1024.0 / nRawValFromModule - 1 ) ) );

	// Converto il valore grezzo per la configurazione pull-up
	dTemperature = log( 10000.0 / ( 1024.0 / nRawValFromModule - 1 ) );

	switch ( nActualTempUnit )
	{

		// Restituisce la temperatura in gradi Kelvin
		case TEMP_KELVIN_MODE:

			dTemperature = 1 / ( 0.001129148 + ( 0.000234125 + ( 0.0000000876741 * dTemperature * dTemperature ) ) * dTemperature ); // Kelvin
			break;

		// Restituisce la temperatura in gradi Celsius
		case TEMP_CELSIUS_MODE:

			dTemperature = 1 / ( 0.001129148 + ( 0.000234125 + ( 0.0000000876741 * dTemperature * dTemperature ) ) * dTemperature );  // Kelvin
			dTemperature = dTemperature - 273.15; // da Kelvin a Celcius
			break;

		// Restituisce la temperatura in gradi Fahrenheit
		case TEMP_FAHRENHEIT_MODE:

			dTemperature = 1 / ( 0.001129148 + ( 0.000234125 + ( 0.0000000876741 * dTemperature * dTemperature ) ) * dTemperature );  // Kelvin
			dTemperature = dTemperature - 273.15; // da Kelvin a Celcius
			dTemperature = ( dTemperature * 9.0 ) / 5.0 + 32.0; // da Celcius a Fahrenheit
			break;

		// Unità di conversione non contemplata: restituisco il valore raw
		default:
			break;
	}

	return dTemperature;
}
