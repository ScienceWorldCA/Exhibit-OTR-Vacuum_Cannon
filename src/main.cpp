// main.cpp
// Copyright (C) May 2019, Science World British Columbia
// John Craver, Electronics Technician

/*
OTR Vacuum Cannon Description:
This system measures the speed of a ping pong ball projectile using two
phototransistors, and displays the values on a custom LED display board.
In a similar setup, speeds of up to 1200km/h have been recorded.

Speed units are displayed on three Adafruit 8x8 NeoMatrix displays, consisting
of 196 WS2812B RGB LED pixels.  Units are selectable by the user with a
pushbutton switch.

Speed values are displayed on a custom 4-digit 7-segment display module, with
each digit driven by a Texas Instruments TPIC6B595 power shift register IC.
The speed value can be reset to zero by the user with a pushbutton switch.

The two phototransistors measure a duration of time that it takes for the ping
pong ball to travel the distance between them, and calculate speed accordingly.  
*/
#include <Arduino.h>

#include "Adafruit_NeoMatrix.h" // for matrix display
#include "Adafruit_NeoPixel.h" // for matrix display
#include "sw7seg.h"

// 7 segment display constants
const int dataPin(5);  // spi data
const int latchPin(3); // spi latch
const int clockPin(4); // spi clock
const int gnotPin(6);  // PWM brightness pin
const int digits(4);   // number of digits in display

// neopixel pins
const int neoPin(2);   // TODO: verify
const int pixels(192); // 3x64 displays

SW7Seg speedDisp(clockPin,dataPin,latchPin,gnotPin,digits);

void setup()
{

}

void loop()
{

  // put your main code here, to run repeatedly:
}