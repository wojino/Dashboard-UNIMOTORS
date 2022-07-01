#include "sensor.h"
#include "Arduino.h"


// Speed
bool getSpeedSensor() { // true means detected
    if(digitalRead(IR) == LOW) {
        return true;
    }
    return false;
}

float getTimeInterval() {
    bool previousSensor, newSensor;
    unsigned long time1, time2;
    float timeInterval;

    while(true) {
        newSensor = getSpeedSensor();
        if(newSensor == true) {
            break;
        }
    }

    while(true) {
        previousSensor = newSensor;
        newSensor = getSpeedSensor();

        if(previousSensor == true && newSensor == false) {
            time1 = millis();
        }
        
        else if(previousSensor == false && newSensor == true) {
            time2 = millis();
            break;
        }
    }
    
    timeInterval = (time2 - time1) / 1000;

    return timeInterval;
}

float getSpeed() { // km/h
    float speed;
    float timeInterval = getTimeInterval();
    speed = (2 * PI * R / timeInterval) * 3.6;

    return speed;
}

float getRPM() {
    float rpm;
    float timeInterval = getTimeInterval();
    rpm = (2 * PI * R / timeInterval) * 60;

    return rpm;
}

// Temperature
float getTemperature() { // C
    float temperature;
    int value = analogRead(TEMPERATURE);
    temperature = (value * 5.0 * 100) / 1024.0;
    
    return temperature;
}
