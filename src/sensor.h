#ifndef SPEED_H
#define SPEED_H

#define V 4.4
#define IR 2
#define R 0.531 / 2 // m
#define TEMPERATURE A0
#define TIMEDELAY 1

// Speed (FC51)
bool getSpeedSensor();
float getTimeInterval();
float calSpeed(float timeInterval);
float calRPM(float timeInterval);

// Temperature (LM35)
float getTemperature();

#endif