#include "MdMeasureDistance.h"
#include "M5All-In-One-Gadget.h"
#include <Arduino.h>
#include "DrUltraSonic.h"

DrUltraSonic dulsn = DrUltraSonic(ECHO_PIN, TRIG_PIN);

double MdMeasureDistance::getDistance()
{
    double distance = (340.0 / 1000000) * dulsn.measureReturnTime() * 0.5 * 100;
    Serial.println(distance);

    return distance;
}