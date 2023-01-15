//
// File: ota_esp32.ino (2022-11-17)
// Demo for the ESP32 microcontroller OTA update.
//
// MIT License

// Copyright (c) 2021 Ralph Bacon
// https://github.com/RalphBacon/228-Wireless-Over-the-Air-OTA-ESP32-updates
// Copyright (c) 2022 Debinix Team, adapted code for my Hackaday project.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <Arduino.h>

#ifdef ARDUINO_TINYPICO
#include <TinyPICO.h>
TinyPICO TP = TinyPICO();
#endif

#include "identification.h" // Does not (normally) requires any edits!

// WiFi logon Credentials - adapt to yours
const char *SSID = "FW114";
const char *PASSWORD = "";

// Project descriptions for the OTA web page
String project_title = "Solder Fume Extraction Station";
String project_description =
    "Solder Fume Extraction Station Deluxe - from scrap.<p> <b>Inhaling the "
    "solder fumes is terrible for the health. Maybe some old parts from my old "
    "PCs could supply some details for this <a "
    "href='https://hackaday.io/project/"
    "187925-solder-fume-extraction-station-deluxe-from-scrap'>Hackaday "
    "project</a></p></b> ";
    
// ------------------------------------------------------------------
// SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP
// ------------------------------------------------------------------
void setup() {
    Serial.begin(9600);

#ifndef ARDUINO_TINYPICO
    pinMode(LED_BUILTIN, OUTPUT);
#endif

    // Connects WiFi and setup the OTA server
    otaInit();
}

// ------------------------------------------------------------------
// MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP
// ------------------------------------------------------------------
void loop() {
    static unsigned long counter = 1;
    static unsigned long prev_millis = 0;

    // Something to look at ...
    if (millis() - prev_millis > 3000) {
        printf("Counter is now %ld\n", ++counter);
        prev_millis = millis();
    }

// Comment/uncomment each section in turn
//---------------------------------------
/* One version of code */
#if defined(ARDUINO_TINYPICO)
    TP.DotStar_SetPixelColor(0, 255, 0); // Fix green
    delay(2500);
#else
    blinkSlow();
#endif

    /* New version of code for OTA */
    //  #if defined(ARDUINO_TINYPICO)
    //  TP.DotStar_SetPixelColor( 255, 0, 0 );  // Fix red
    //  delay(2500);
    //  #else
    //  blinkFast();
    //  #endif
}

// ------------------------------------------------------------------
// HELPERS     HELPERS     HELPERS     HELPERS     HELPERS
// ------------------------------------------------------------------
#ifndef ARDUINO_TINYPICO
void blinkSlow(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}

void blinkFast(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(125);
    digitalWrite(LED_BUILTIN, LOW);
    delay(125);
}
#endif

// EOF
