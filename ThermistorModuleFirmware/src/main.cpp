#include "ThermistorModule.hpp"		// Libreria di gestione del modulo di temperatura
#include <Arduino.h>				// Su un file .ino non è necessario

/*
Schetch di test sul modulo di temperatura con il termistore
*/

// PIN a cui è collegato il il modulo di temperatura con il termistore (analogico)
#define INPUT_TEMP_PIN             A0

double dTemp =  0;
double dLastTemp = 0;

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

    // Leggo il valore del sensore in unità Celsius
    dTemp = ThermistorModuleGetTemp( INPUT_TEMP_PIN );

    if ( dTemp == dLastTemp )
    {
	    Serial.println( "Il valore della temperatura letto dal modulo non è cambiato" );
    }
    else if ( dTemp > dLastTemp )
    {
        Serial.println( "Il valore della temperatura letto dal modulo è aumentato: " + (String)dTemp + "° C" );
    }
    else if ( dTemp < dLastTemp )
    {
        Serial.println( "Il valore della temperatura letto dal modulo è diminuito: " + (String)dTemp + "° C" );
    }

    dLastTemp = dTemp;

	delay( 5000 );
}

void DebugSetup()
{
    Serial.begin( 9600 );
    Serial.println( "--- Ho inizializzato il debug su monitor seriale");
}
