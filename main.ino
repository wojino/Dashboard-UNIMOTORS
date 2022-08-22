#include "src/display.h"
#include "src/sensor.h"
#include "src/TM1637Display.h"

#define DELAY 0
#define CLK1 8
#define DIO1 9
#define CLK2 10
#define DIO2 11
#define CLK3 12
#define DIO3 13

float timeInterval;
float speed, rpm, temperature;
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
    timeInterval = getTimeInterval();

    speed = calSpeed(timeInterval);
    displayNum(display1, (int)speed);

    rpm = calRPM(timeInterval);
    displayNum(display2, (int)rpm);

    temperature = getTemperature();
    displayNum(display3, (int)temperature);


    Serial.print("Time Interval: ");
    Serial.println(timeInterval);
    Serial.print("Speed: ");
    Serial.println(speed);
    Serial.print("RPM: ");
    Serial.println(rpm);
    Serial.print("Temperature: ");
    Serial.println(temperature);
    
    delay(DELAY);

    Serial.println("loop");
}