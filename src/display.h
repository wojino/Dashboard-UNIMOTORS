#ifndef DISPLAY_H
#define DISPLAY_H

#include "TM1637Display.h"

#define BRIGHNESS 8
#define BIT_DELAY 100

TM1637Display initDisplay(uint8_t pinClk, uint8_t pinDIO, unsigned int bitDelay = BIT_DELAY);
void displayNum(TM1637Display display, int number);

#endif