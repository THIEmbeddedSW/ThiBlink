/**
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include <LcdMenu.h>
#include <MenuScreen.h>
#include <display/LiquidCrystalAdapter.h>
#include <renderer/CharacterDisplayRenderer.h>

#include "avr8-stub.h" // debug interfaces
#include "app_api.h"


// define the required LCD objects
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
CharacterDisplayRenderer renderer(new LiquidCrystalAdapter(&lcd, 16, 2), 16, 2);
LcdMenu menu(renderer);


void setup()
{
    pinMode(13, OUTPUT); // initialize LED digital pin as an output
	pinMode(14, INPUT);  // initialize Switch pin of Display Keypad as input

	debug_init(); // initialize the debug interface
//    Serial.begin(9600);  // we need the serial line for debugging

   renderer.begin();
   lcd.clear();

    // Some hello text
    lcd.setCursor(0,0);
	lcd.print("THI Experiment");
}

void loop()
{
    // turn the LED on (HIGH is the voltage level), put info on LCD
    digitalWrite(13, HIGH);
	lcd.setCursor(0,1);
	lcd.print("On ");

    // wait for 500ms
    delay(500);

    // turn LED off, if switch is not pressed (i.e. if PIN is high), put info on LCD
    if (digitalRead(14)) 
    {
        digitalWrite(13, LOW);
        lcd.setCursor(0,1);
	    lcd.print("Off");
    }
//    Serial.println("digital input: " + String(digitalRead(14)));

    // wait for 500ms, 
    delay(500);
}