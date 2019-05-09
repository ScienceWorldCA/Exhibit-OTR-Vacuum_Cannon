// sw7seg.h
// Copyright (C) May 2019, Science World British Columbia
// John Craver, Electronics Technician

#ifndef SW7seg
#define SW7seg

#include <Arduino.h>


class SW7Seg // Science World 7 Segment Displays
{
public:
    SW7Seg(int clockPin, int dataPin, int latchPin,int gnotPin, int digits);

    void setValue(int);

    void update();  // load digits into display
    void brightness(float); // input 0.0 to 1.0; change PWM signal on gnotPin

protected:

private:
    int _gnotPin;
    int _digits;

    void split(int val); // called by SW7Seg::setValue
    int places[]; // stores the individual digits; used by SW7Seg::split()

    typedef const char font_t;
    font_t PROGMEM font[11] =
    {
        //  cdebapfg  //segment legend
        0b11111010, //0
        0b10010000, //1
        0b01111001, //2
        0b11011001, //3
        0b10010011, //4
        0b11001011, //5
        0b11101011, //6
        0b10011000, //7
        0b11111011, //8
        0b10011011,  //9
        0b00000000  //blank
    };


};


/*      a
 *    -----
 *  f|     |b
 *   |  g  |
 *    -----
 *  e|     |c
 *   |  d  |
 *    -----  o dp
 *      
 *   {c,d,e,b,a,dp,f,g}
 */

//---------------------------------------------------------------
SW7Seg::SW7Seg(int clockPin,int dataPin, int latchPin, int gnotPin, int digits)
: _gnotPin(gnotPin),
  _digits(digits)
{
}

void SW7seg::update()
{
    // 74HC595: clock data out, latch when all data has been sent 
}

// splits an integer value into
void SW7Seg::split(int val)
{
    if (val == 0) // special case when value = 0;
    {
        places[0] = 0; // ones digit shows 0

        for (int i = 1; i < _digits; i++) // all leading place values are blanked
        {
            places[i] = 10; // blank
        }
    } 
    else
    {
        for (int i = 0; i < _digits; i++) // start with ones digit
        {
            if(val >= 1)
            {
                places[i] = val % 10; // grab ones digit, shove into array
                val /= 10;  // decimal shift the value in preparation for next loop
            }
            else
            {
                places[i] = 10; // insert leading blank characters
            }
        }
    }
}

void SW7Seg::brightness(float val)
{
  analogWrite(_gnotPin, map(constrain(val,0.00,1.00), 1.00, 0.00, 0, 255));
}

#endif