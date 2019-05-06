// sw7seg.h
// Copyright (C) May 2019, Science World British Columbia
// John Craver, Electronics Technician

#ifndef SW7seg
#define SW7seg

class SW7Seg // Science World 7 Segment Displays
{
public:
    SW7Seg(int clockPin, int dataPin, int latchPin,int gPin, int digits);
    void value(int val); // input 0 to 9999 parse value into digits
    void update();  // load digits into display
    void brightness(float); // input 0.0 to 1.0; change PWM signal on gnotPin

protected:

private:
}


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

uint8_t ledConvert[] = {
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

//---------------------------------------------------------------
void brightness(uint8_t value) {
  analogWrite(G_PIN, 255 - value);
}

#endif