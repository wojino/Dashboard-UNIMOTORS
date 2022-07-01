#ifndef SPEED_H
#define SPEED_H

#define IR 1
#define R 0.531 / 2 // m
#define TEMPERATURE 2

// Speed (FC51)
bool getSpeedSensor();
float getSpeed();
float getRPM();

// Temperature (LM35)
float getTemperature();

#endif