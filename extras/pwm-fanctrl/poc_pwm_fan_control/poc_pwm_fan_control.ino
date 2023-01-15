//
// File: poc_pwm_fan_control.ino (2023-01-15)
// Board: UM ESP32 TinyPICO
//
// MIT License

// Copyright (c) 2022 Debinix Team.

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


#define DEBUGLEVEL_ON
#include <Rdebug.h>

#include <stdint.h>

//void ICACHE_RAM_ATTR isr(void);
void IRAM_ATTR keyPressed(void);

struct Button {
    const uint8_t button_pin;
    uint32_t numberKeyPresses;
    bool pressed;
};

#define PWM_OFF 0

// GPIO pins UM ESP32
const uint8_t pin_pedal_switch = 23;
const int pin_pwm_out = 19;
const int pin_pedal_led = 25;
const int pin_analog_input = 33;

const int pwm_freq = 10; // Hz
const int pwm_channel = 0;
const int pwm_resolution = 10;
const int MAX_DUTY_CYCLE = (int)(pow(2, pwm_resolution) - 1);

Button PedalSwitch = {pin_pedal_switch, 0, false};

int analog_input;

// milliseconds
int sw_bounce_delay_time = 20;

// ------------------------------------------------------------------
// SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP
// ------------------------------------------------------------------
void setup() {
    Serial.begin(9600);

    // HIGH when open, LOW when closed - see the schematic
    pinMode(PedalSwitch.button_pin, INPUT_PULLUP);
    attachInterrupt(PedalSwitch.button_pin, keyPressed, FALLING);

    pinMode(pin_analog_input, INPUT);

    pinMode(pin_pedal_led, OUTPUT);
    digitalWrite(pin_pedal_led, LOW);

    // PWM setup
    ledcSetup(pwm_channel, pwm_freq, pwm_resolution);
    ledcAttachPin(pin_pwm_out, pwm_channel);

    Serial.println("Setup completed.");
}

// ------------------------------------------------------------------
// MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP
// ------------------------------------------------------------------
void loop() {

    if (PedalSwitch.pressed) {
        digitalWrite(pin_pedal_led, HIGH); // LED on
    } else {
        digitalWrite(pin_pedal_led, LOW); // LED off
    }

    analog_input = analogRead(pin_analog_input);
#if defined(DEBUGLEVEL_ON)
    debug("Raw ESP32 ADC input: ");
    debug(analog_input);
    debug(" /Used for PWM 10 bit write signal: ");
    debugln(analog_input/4);
    
#endif

    // Writes an analog value (PWM wave) to a pin
    if (PedalSwitch.pressed) {
        // ESP has 12 bit(4096) analogRead, 
        // but we used 10 bit pwm resolution
        if(analog_input/4 <= MAX_DUTY_CYCLE) {
            ledcWrite(pwm_channel, analog_input/4);
        } else {
            debug("Invalid PWM duty cycle: ");
            debugln(analog_input/4);            
        }
        
    } else {
        ledcWrite(pwm_channel, PWM_OFF);
    }

    delay(1000);
}

// ------------------------------------------------------------------
// INTERRUPT     INTERRUPT     INTERRUPT     INTERRUPT     INTERRUPT
// ------------------------------------------------------------------
void IRAM_ATTR keyPressed(void){

    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();

    if (interruptTime - lastInterruptTime > sw_bounce_delay_time) {

        PedalSwitch.numberKeyPresses++;

        if (PedalSwitch.numberKeyPresses % 2 == 0) {
            PedalSwitch.pressed = true;
        } else {
            PedalSwitch.pressed = false;
        }
    }
    lastInterruptTime = interruptTime;
}

//EOF
