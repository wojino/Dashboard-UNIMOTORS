#include "display.h"
#include "Arduino.h"
#include "TM1637Display.h"

TM1637Display initDisplay(uint8_t pinClk, uint8_t pinDIO, unsigned int bitDelay) {
    TM1637Display display(pinClk, pinDIO, bitDelay);
    display.setBrightness(BRIGHNESS);

    return display;
}

void displayNum(TM1637Display display, int number) {
    display.showNumberDec(number, true);
}
