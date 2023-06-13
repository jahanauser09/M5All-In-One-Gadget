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
    // mlcd.displayJpgImageCoordinate(, WBGT_TEMP2DIGIT_X_CRD, WBGT_TEMP2DIGIT_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, WBGT_TEMP1DIGIT_X_CRD, WBGT_TEMP1DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH, WBGT_ORANGEDOT_X_CRD, WBGT_ORANGEDOT_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, WBGT_TEMPDECIMAL_X_CRD, WBGT_TEMPDECIMAL_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);

    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD); // 湿度
    // mlcd.displayJpgImageCoordinate(, WBGT_HUMI2DIGIT_X_CRD, WBGT_HUMI2DIGIT_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, WBGT_HUMI1DIGIT_X_CRD, WBGT_HUMI1DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_BLUEDOT_X_CRD, WBGT_BLUEDOT_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, WBGT_HUMIDECIMAL_X_CRD, WBGT_HUMIDECIMAL_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);

    mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_SITUATION_X_CRD, WBGT_SITUATION_Y_CRD); // セーフのやつ
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, WBGT_BACK_X_CRD, WBGT_BACK_Y_CRD);
}

void AppControl::displayTempHumiIndex()
{
    // mwbgt.getTempHumi(); //温湿度取得するやつ/引数2つ何渡す？ワッツ？
}

void AppControl::displayMusicInit()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_SITUATION_X_CRD, MUSIC_SITUATION_Y_CRD);
    mlcd.displayText(mmplay.getTitle(), MUSIC_NAME_X_CRD, MUSIC_NAME_Y_CRD); //曲タイトル

    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAYANDSTOP_X_CRD, MUSIC_PLAYANDSTOP_Y_CRD);

    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
}

void AppControl::displayMusicStop()
{
    // mlcd.displayJpgImageCoordinate(, MUSIC_NAME_X_CRD, MUSIC_NAME_Y_CRD); //曲タイトル
}

void AppControl::displayMusicTitle()
{
    // mlcd.displayJpgImageCoordinate(, MUSIC_NAME_X_CRD, MUSIC_NAME_Y_CRD); //曲タイトル
}

void AppControl::displayNextMusic()
{
}

void AppControl::displayMusicPlay()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_SITUATION_X_CRD, MUSIC_SITUATION_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, MUSIC_NAME_X_CRD, MUSIC_NAME_Y_CRD); //曲タイトル

    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_STOP_IMG_PATH, MUSIC_PLAYANDSTOP_X_CRD, MUSIC_PLAYANDSTOP_Y_CRD);
}

void AppControl::displayMeasureInit()
{
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_SITUATION_X_CRD, MEASURE_SITUATION_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, MEASURE_3DIGIT_X_CRD, MEASURE_3DIGIT_Y_CRD); //3桁目
    // mlcd.displayJpgImageCoordinate(, MEASURE_2DIGIT_X_CRD, MEASURE_2DIGIT_Y_CRD); //2桁目
    // mlcd.displayJpgImageCoordinate(, MEASURE_1DIGIT_X_CRD, MEASURE_1DIGIT_Y_CRD); //1桁目
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_BLUEDOT_X_CRD, MEASURE_BLUEDOT_Y_CRD);
    // mlcd.displayJpgImageCoordinate(, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);  //小数第一
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CENTI_X_CRD, MEASURE_CENTI_Y_CRD);
}

void AppControl::displayMeasureDistance()
{
}

void AppControl::displayDateInit()
{
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_SITUATION_X_CRD, DATE_SITUATION_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
}

void AppControl::displayDateUpdate()
{
    mlcd.displayDateText(mdtime.readDate(), DATE_YEAR_X_CRD, DATE_YEAR_Y_CRD); // ←時刻だすやつ。(String text, int x, int y)引数３つ
    mlcd.displayDateText(mdtime.readTime(), DATE_TIME_X_CRD, DATE_TIME_Y_CRD); // ←時刻だすやつ。(String text, int x, int y)引数３つ
    // mdtime.readDate(); //日付取得
    // mdtime.readTime(); //時刻取得
}

void AppControl::controlApplication()
{
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

                delay(100);
                if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(WBGT, EXIT);
                }
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
                    // mlcd.displayJpgImageCoordinate(, MUSIC_NAME_X_CRD, MUSIC_NAME_Y_CRD); //次曲タイトルか？？
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
                displayMusicPlay();
                setStateMachine(MUSIC_PLAY, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(MUSIC_PLAY, EXIT);
                }
                /*else if (/* condition ) //曲が終わったらの条件式
                {
                    /* code
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
                // displayMeasureDistance();
                delay(100);
                if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(MEASURE, EXIT);
                }

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
                displayDateUpdate();
                delay(100);
                if (m_flag_btnB_is_pressed == true)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(DATE, EXIT);
                }

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
