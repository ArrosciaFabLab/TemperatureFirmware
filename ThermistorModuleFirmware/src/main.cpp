#include "ThermistorModule.hpp"		// Libreria di gestione del modulo di temperatura
#include <Arduino.h>				// Su un file .ino non è necessario

/*
Schetch di test sul modulo di temperatura con il termistore
*/

// PIN a cui è collegato il il modulo di temperatura con il termistore (analogico)
#define INPUT_TEMP_PIN             5

// La dichiarazione delle funzioni non è necessaria nel file .ino

void DebugSetup();

// Setup inizale di Arduino
void setup()
{
    // Inizializzo il logging sul monitor seriale
    DebugSetup();

    Serial.println( "--- Sto inizializzando la scheda Arduino" );

	// Configurazione iniziale del modulo di temperatura
    ThermistorModuleSetup( INPUT_TEMP_PIN, TEMP_CELSIUS_MODE );

    Serial.println( "--- Ho finito di inizializzare la scheda Arduino" );
}

// Loop standard di Arduino
void loop()
{
    Serial.println( "--- Inizio il loop principale della scheda Arduino" );

	double dTemp =  0;

    // Leggo il valore del sensore in unità Celsius
    dTemp = ThermistorModuleGetTemp( INPUT_TEMP_PIN );

	Serial.println( "Il valore della temperatura letto dal modulo con il termistore è di " + String( int( dTemp ) ) + "° C" );

	delay( 1000 );
}

void DebugSetup()
{
    Serial.begin( 9600 );
    Serial.println( "--- Ho inizializzato il debug su monitor seriale");
}
