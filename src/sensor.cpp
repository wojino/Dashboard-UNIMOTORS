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
        delay(TIMEDELAY);

        previousSensor = newSensor;
        newSensor = getSpeedSensor();

        if(previousSensor == true && newSensor == false) {
            time1 = millis();
            Serial.println(time1);
        }
        
        else if(previousSensor == false && newSensor == true) {
            time2 = millis();
            Serial.println(time2);
            break;
        }
    }
    
    Serial.println(time2);
    Serial.println(time1);

    timeInterval = (time2 - time1) / 1000.0;

    return timeInterval;
}

float calSpeed(float timeInterval) { // km/h
    float speed = (2.0 * PI * R / timeInterval) * 3.6;
    return speed;
}

float calRPM(float timeInterval) {
    float rpm = (2.0 * PI * R / timeInterval) * 60.0;
    return rpm;
}

// Temperature
float getTemperature() { // C
    float temperature;
    int value = analogRead(TEMPERATURE);
    Serial.println(value);
    temperature = (value * V * 100.0) / 1024.0;
    
    return temperature;
}
