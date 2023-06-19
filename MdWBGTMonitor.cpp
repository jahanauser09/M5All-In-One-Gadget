#include "MdWBGTMonitor.h"
#include "DrTHSensor.h"
#include <Wire.h>

//  初期化
void MdWBGTMonitor::init()
{
    Wire.begin();
    init();
}
//  温湿度の取得             ↓温度                ↓湿度              ↓アラート
/*void MdWBGTMonitor::getWBGT(double* temperature ,double*  humidity ,WbgtIndex* index)
{
DrTHSensor.getTempHumi()

}*/