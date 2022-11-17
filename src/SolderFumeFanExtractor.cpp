/*!
 * @file SolderFumeFanExtractor.cpp
 *
 * @mainpage The library controls the extractor fan unit and the lithium charger.
 *
 * @see [Solder Fume Extractor Hardware](https://github.com/berrak/solder-fume-extractor-hw)
 * @section intro_sec Introduction
 *
 * The library supports the fan control of the solder fume extraction unit by fan speed.
 * It also monitors air quality and battery status. In charging mode, the library supports
 * charging, storing, and discharging 18650 cells and monitoring actual cell health.
 *
 * @section dependencies Dependencies
 *
 * The library depends only on Arduino IDE built-in libraries.
 *
 * @section license License
 *
 * The MIT license.
 *
 */
#ifdef ARDUINO
// Required includes for Arduino libraries always go first.
// The class implementation needs these includes.
#include "Arduino.h"
#endif
// Secondly, include required declarations for this class interface.
#include "SolderFumeFanExtractor.h"
