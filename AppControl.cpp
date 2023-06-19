#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;

const char *g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};

const char *g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};

void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState()
{
    return m_state;
}

void AppControl::setState(State state)
{
    m_state = state;
}

Action AppControl::getAction()
{
    return m_action;
}

void AppControl::setAction(Action action)
{
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState()
{
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}

void AppControl::displayTitleInit()
{
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit()
{
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECICE_X_CRD, MENU_DECICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}

void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{
    if (MENU_WBGT == current_state && MENU_DATE == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    }
    else if (MENU_DATE == current_state && MENU_MEASURE == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    }
    else if (MENU_MEASURE == current_state && MENU_MUSIC == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    }
    else if (MENU_MUSIC == current_state && MENU_WBGT == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    }
    else if (MENU_WBGT == current_state && MENU_MUSIC == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    }
    else if (MENU_MUSIC == current_state && MENU_MEASURE == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    }
    else if (MENU_MEASURE == current_state && MENU_DATE == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    }
    else if (MENU_DATE == current_state && MENU_WBGT == next_state)
    {
        mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    }
}

void AppControl::displayWBGTInit()
{
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH, WBGT_TEMPERATURE_X_CRD, WBGT_TEMPERATURE_Y_CRD); // 温度
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH, WBGT_TDOT_X_CRD, WBGT_TDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);

    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD); // 湿度
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_HDOT_X_CRD, WBGT_HDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);

    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, WBGT_BACK_X_CRD, WBGT_BACK_Y_CRD);
}

void AppControl::displayTempHumiIndex()
{
    // mlcd.displayJpgImageCoordinate(, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);  //温度
    // mlcd.displayJpgImageCoordinate(, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);

    // mlcd.displayJpgImageCoordinate(, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);  //湿度
    // mlcd.displayJpgImageCoordinate(, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);

    mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD); // セーフのやつ

    // mwbgt.getTempHumi(); //温湿度取得するやつ/引数2つ渡す？
}

void AppControl::displayMusicInit()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);

    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_STOP_X_CRD, MUSIC_STOP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
}

void AppControl::displayMusicStop()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);

    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_STOP_X_CRD, MUSIC_STOP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
}

void AppControl::displayMusicTitle()
{
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD); // 曲タイトル
}

void AppControl::displayNextMusic()
{
    mmplay.selectNextMusic();                                                       // 次曲を読み込む
    mlcd.displayText("                    ", MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD); // 無理やりだがいいのか？
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);      // 次曲タイトル
}

void AppControl::displayMusicPlay()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD); // 曲タイトル

    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_STOP_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
}

void AppControl::displayMeasureInit()
{
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);

    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);

    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
}

void AppControl::displayMeasureDistance()
{
    int distance = mmdist.getDistance() * 10;
    Serial.println(distance);

    int digi3 = (((distance / 10) / 10) / 10) % 10;
    Serial.println(digi3);
    if (digi3 == 0)
    {
        mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
    }
    else
    {
        mlcd.displayJpgImageCoordinate(g_str_blue[digi3], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
    }

    int digi2 = ((distance / 10) / 10) % 10;
    Serial.println(digi2);
    if (digi2 == 0 && digi3 == 0)
    {
        mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    }
    else
    {
        mlcd.displayJpgImageCoordinate(g_str_blue[digi2], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    }

    int digi1 = (distance / 10) % 10;
    Serial.println(digi1);
    mlcd.displayJpgImageCoordinate(g_str_blue[digi1], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);

    int deci = distance % 10;
    Serial.println(deci);
    mlcd.displayJpgImageCoordinate(g_str_blue[deci], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);

    /*for (int distanceState = 1; distanceState <= 4; distanceState++)
    {
        int i = distance % 10;

        switch (distanceState)
        {
        case 1: // 小数第一
            mlcd.displayJpgImageCoordinate(g_str_blue[i], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
            Serial.print("dec   ");
            Serial.println(i);

            break;
        case 2: // １桁目
            mlcd.displayJpgImageCoordinate(g_str_blue[i], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
            Serial.print("de1   ");
            Serial.println(i);

            break;
        case 3: // ２桁目
            if (i == 0)
            {
                mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
                Serial.print("tr1   ");
                Serial.println(i);
            }
            else
            {
                mlcd.displayJpgImageCoordinate(g_str_blue[i], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
                Serial.print("fal1   ");
                Serial.println(i);
            }

            break;
        case 4: // ３桁目
            if (i == 0)
            {
                mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
                Serial.print("tr2   ");
                Serial.println(i);
            }
            else
            {
                mlcd.displayJpgImageCoordinate(g_str_blue[i], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
                Serial.print("fal2   ");
                Serial.println(i);
            }

            break;
        }
        distance = distance / 10;
    }*/
}

void AppControl::displayDateInit()
{
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
}

void AppControl::displayDateUpdate()
{
    mlcd.displayDateText(mdtime.readDate(), DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD); // ←日付だすやつ。(String text, int x, int y)引数３つ
    mlcd.displayDateText(mdtime.readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);     // ←時刻だすやつ。(String text, int x, int y)引数３つ
    // mdtime.readDate(); //日付取得
    // mdtime.readTime(); //時刻取得
}

void AppControl::controlApplication()
{
    mmplay.init(); // 指導員指示で追記

    while (1)
    {

        switch (getState())
        {
        case TITLE:

            switch (getAction())
            {
            case ENTRY:
                displayTitleInit();
                setStateMachine(TITLE, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed == true || m_flag_btnB_is_pressed == true || m_flag_btnC_is_pressed == true)
                {
                    setStateMachine(TITLE, EXIT);
                }
                break;

            case EXIT:
                setBtnAllFlgFalse();
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MENU:

            switch (getAction())
            {
            case ENTRY:
                mlcd.fillBackgroundWhite();
                displayMenuInit();
                setStateMachine(MENU, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed == true)
                {
                    switch (getFocusState())
                    {
                    case MENU_WBGT:
                        focusChangeImg(MENU_WBGT, MENU_DATE);
                        setFocusState(MENU_DATE);
                        break;
                    case MENU_MUSIC:
                        focusChangeImg(MENU_MUSIC, MENU_WBGT);
                        setFocusState(MENU_WBGT);
                        break;
                    case MENU_MEASURE:
                        focusChangeImg(MENU_MEASURE, MENU_MUSIC);
                        setFocusState(MENU_MUSIC);
                        break;
                    case MENU_DATE:
                        focusChangeImg(MENU_DATE, MENU_MEASURE);
                        setFocusState(MENU_MEASURE);
                        break;

                    default:
                        break;
                    }
                    setBtnAllFlgFalse();
                }
                if (m_flag_btnC_is_pressed == true)
                {
                    switch (getFocusState())
                    {
                    case MENU_WBGT:
                        focusChangeImg(MENU_WBGT, MENU_MUSIC);
                        setFocusState(MENU_MUSIC);
                        break;
                    case MENU_MUSIC:
                        focusChangeImg(MENU_MUSIC, MENU_MEASURE);
                        setFocusState(MENU_MEASURE);
                        break;
                    case MENU_MEASURE:
                        focusChangeImg(MENU_MEASURE, MENU_DATE);
                        setFocusState(MENU_DATE);
                        break;
                    case MENU_DATE:
                        focusChangeImg(MENU_DATE, MENU_WBGT);
                        setFocusState(MENU_WBGT);
                        break;

                    default:
                        break;
                    }
                    setBtnAllFlgFalse();
                }

                if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(MENU, EXIT);
                }
                break;

            case EXIT:
                switch (getFocusState())
                {
                case MENU_WBGT:
                    setStateMachine(WBGT, ENTRY);
                    break;
                case MENU_MUSIC:
                    setStateMachine(MUSIC_STOP, ENTRY);
                    break;
                case MENU_MEASURE:
                    setStateMachine(MEASURE, ENTRY);
                    break;
                case MENU_DATE:
                    setStateMachine(DATE, ENTRY);
                    break;

                default:
                    break;
                }
                setFocusState(MENU_WBGT);

            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction())
            {
            case ENTRY:
                mlcd.clearDisplay();
                mlcd.fillBackgroundWhite();
                displayWBGTInit();
                setStateMachine(WBGT, DO);
                break;

            case DO:
                do
                {
                    displayTempHumiIndex();
                    delay(100);
                } while (m_flag_btnB_is_pressed == false);
                setBtnAllFlgFalse();
                setStateMachine(WBGT, EXIT);

                /*if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(WBGT, EXIT);
                }*/
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction())
            {
            case ENTRY:
                mlcd.clearDisplay();
                mlcd.fillBackgroundWhite();
                displayMusicInit();
                displayMusicTitle();
                setStateMachine(MUSIC_STOP, DO);
                break;

            case DO:
                if (m_flag_btnB_is_pressed == true)
                {
                    setStateMachine(MUSIC_STOP, EXIT);
                }
                else if (m_flag_btnA_is_pressed == true)
                {
                    setStateMachine(MUSIC_STOP, EXIT);
                }

                if (m_flag_btnC_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    displayNextMusic();
                }

                break;

            case EXIT:
                if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(MENU, ENTRY);
                }
                else if (m_flag_btnA_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(MUSIC_PLAY, ENTRY);
                }

                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction())
            {
            case ENTRY:
                mlcd.clearDisplay();
                mlcd.fillBackgroundWhite();
                mmplay.prepareMP3();
                displayMusicPlay();
                setStateMachine(MUSIC_PLAY, DO);
                break;

            case DO:
                do
                {
                    mmplay.isRunningMP3();
                    mmplay.playMP3();
                } while (m_flag_btnA_is_pressed == false || mmplay.playMP3() == false);
                mmplay.stopMP3();
                setBtnAllFlgFalse();
                setStateMachine(MUSIC_PLAY, EXIT);

                /*mmplay.isRunningMP3();
                mmplay.playMP3();

                if (m_flag_btnA_is_pressed == true)
                {
                    mmplay.stopMP3();
                    setBtnAllFlgFalse();
                    setStateMachine(MUSIC_PLAY, EXIT);
                }
                else if (mmplay.playMP3() == false) // 曲が終わったらの条件式
                {
                    setStateMachine(MUSIC_PLAY, EXIT);
                }*/

                break;

            case EXIT:
                setStateMachine(MUSIC_STOP, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction())
            {
            case ENTRY:
                mlcd.clearDisplay();
                mlcd.fillBackgroundWhite();
                displayMeasureInit();
                setStateMachine(MEASURE, DO);
                break;

            case DO:
                do
                {
                    displayMeasureDistance();
                    delay(250);
                } while (m_flag_btnB_is_pressed == false);
                setBtnAllFlgFalse();
                setStateMachine(MEASURE, EXIT);

                /*if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(MEASURE, EXIT);
                }*/

                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction())
            {
            case ENTRY:
                mlcd.clearDisplay();
                mlcd.fillBackgroundWhite();
                displayDateInit();
                setStateMachine(DATE, DO);
                break;

            case DO:
                do
                {
                    displayDateUpdate();
                    delay(100);
                } while (m_flag_btnB_is_pressed == false);
                setBtnAllFlgFalse();
                setStateMachine(DATE, EXIT);

                /*if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(DATE, EXIT);
                }*/

                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
