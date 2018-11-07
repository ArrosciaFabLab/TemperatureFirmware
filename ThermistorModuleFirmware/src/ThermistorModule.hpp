#ifndef THERMISTORMODULE_H_
#define THERMISTORMODULE_H_

/*

*/

// Modo di rilevamento in unità Kelvin
#define TEMP_KELVIN_MODE      1
// Modo di rilevamento in unità Celsius
#define TEMP_CELSIUS_MODE     2
// Modo di rilevamento in unità Fahrenheit
#define TEMP_FAHRENHEIT_MODE  3

// La dichiarazione delle funzioni non è necessaria nel file .ino

/*
 *    Funzione che imposta i parametri di inizializzazione del modulo di temperatura
 */
void ThermistorModuleSetup( int nGate, int nMode );

/*
 *    Funzione che ferma restituisce il valore di temperatura letto dal termistore
 *	  nell'unità di misura attualmente impostata
 */
double ThermistorModuleGetTemp( int nSensorPin );

#endif
