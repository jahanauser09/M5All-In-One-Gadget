#include "DrUltraSonic.h"
#include <Arduino.h>

DrUltraSonic::DrUltraSonic(int echo_pin, int trig_pin)
{
    pinMode(echo_pin, INPUT);
    pinMode(trig_pin, OUTPUT);
    Serial.begin(9600);
}

double DrUltraSonic::measureReturnTime()
{
    digitalWrite(m_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trig_pin, LOW);
    double t = pulseIn(ECHO_PIN, HIGH, 2000000);
    return t;
}