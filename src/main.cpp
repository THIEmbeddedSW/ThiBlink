/**
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

void setup()
{
    pinMode(13, OUTPUT); // initialize LED digital pin as an output
	pinMode(14, INPUT);  // initialize Switch pin of Display Keypad as input
    
    Serial.begin(9600);  // we need the serial line for debugging
}

void loop()
{
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(13, HIGH);

    // wait for 500ms
    delay(500);

    // turn LED off, if switch is not pressed (i.e. if PIN is high)
    if (digitalRead(14)) digitalWrite(13, LOW);

    Serial.println("digital input: " + String(digitalRead(14)));


    // wait for a while, 
    delay(500);
}