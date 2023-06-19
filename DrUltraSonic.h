/* インクルードガード */
#pragma once

#include "M5All-In-One-Gadget.h"

class DrUltraSonic // classの定義
{
private: // privateはクラス内からしかアクセスできない
    int m_echo_pin = ECHO_PIN;
    int m_trig_pin = TRIG_PIN;

public: // publicはどこからでもアクセス可能
    DrUltraSonic(int m_echo_pin, int m_trig_pin);
    double measureReturnTime();
};
