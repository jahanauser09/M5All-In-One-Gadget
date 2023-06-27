#include "MdWBGTMonitor.h"
#include "DrTHSensor.h"
#include <Wire.h>

DrTHSensor drths;
//  初期化
void MdWBGTMonitor::init()
{
    drths.init();
}

//  温湿度の取得             ↓温度                ↓湿度              ↓アラート
void MdWBGTMonitor::getWBGT(double *temperature, double *humidity, WbgtIndex *index)
{
    drths.getTempHumi(temperature, humidity);
    int calc_index = 0.68 * (*temperature) + 0.12 * (*humidity);

    if (calc_index <= 15)
    {
        *index = SAFE;
    }else if (calc_index <= 24)
    {
        *index = ATTENTION;
    }else if (calc_index <= 27)
    {
        *index = ALERT;
    }else if (calc_index <= 30)
    {
        *index = HIGH_ALERT;
    }else{
        *index = DANGER;
    }
    
    
    
    
    
}