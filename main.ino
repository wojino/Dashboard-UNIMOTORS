#include "src/display.h"
#include "src/sensor.h"
#include "src/TM1637Display.h"

#define DELAY 100
#define CLK1 3
#define DIO1 4
#define CLK2 5
#define DIO2 6
#define CLK3 7
#define DIO3 8

int speed, rpm, temperature;
String str;
TM1637Display display1 = initDisplay(CLK1, DIO1);
TM1637Display display2 = initDisplay(CLK2, DIO2);
TM1637Display display3 = initDisplay(CLK3, DIO3);

void setup() {
    pinMode(IR, INPUT);
    Serial.begin(115200);
    Serial.println("Serial Monitor Started");
}

void loop() {
    speed = getSpeed();
    displayNum(display1, speed);

    rpm = getRPM();
    displayNum(display3, rpm);

    temperature = getTemperature();
    displayNum(display2, temperature);

    str = speed + " km/h | ";
    str += rpm + " rpm | ";
    str += temperature + " C";
    Serial.println(str);

    delay(DELAY);

    Serial.println("loop");
}