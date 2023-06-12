#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;

const char* g_str_orange[] = {
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

const char* g_str_blue[] = {
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

void AppControl::setBtnAFlg(bool flg){
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg){
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg){
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse(){
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState(){
    return m_state;
}

void AppControl::setState(State state){
    m_state = state;
}

Action AppControl::getAction(){
    return m_action;
}

void AppControl::setAction(Action action){
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action){
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState(){
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs){
    m_focus_state = fs;
}

void AppControl::displayTitleInit(){
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit(){
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECICE_X_CRD, MENU_DECICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}

void AppControl::focusChangeImg(FocusState current_state, FocusState next_state){
}

void AppControl::displayWBGTInit(){
}

void AppControl::displayTempHumiIndex(){
}

void AppControl::displayMusicInit(){
}

void AppControl::displayMusicStop(){
}

void AppControl::displayMusicTitle(){
}

void AppControl::displayNextMusic(){
}

void AppControl::displayMusicPlay(){
}

void AppControl::displayMeasureInit(){
}

void AppControl::displayMeasureDistance(){
}

void AppControl::displayDateInit(){
}

void AppControl::displayDateUpdate(){
}

void AppControl::controlApplication(){
    while (1) {

        switch (getState()) {
        case TITLE:

            switch (getAction()) {
            case ENTRY:
                displayTitleInit();
                setStateMachine(TITLE, DO);
                break;

            case DO:
                if(m_flag_btnA_is_pressed == true || m_flag_btnB_is_pressed == true || m_flag_btnC_is_pressed == true){
                setStateMachine(TITLE,EXIT);
                }
                break;

            case EXIT:
                setBtnAllFlgFalse();
                setStateMachine(MENU,ENTRY);
                break;

            default:
                break;
            }

            break;

        case MENU:

            switch (getAction()) {
            case ENTRY:
                mlcd.fillBackgroundWhite();
                displayMenuInit();
                setStateMachine(MENU,DO);
                break;

            case DO:
                /*if(m_flag_btnA_is_pressed == true){
                    focusChangeImg();
                    setBtnAllFlgFalse();
                }
                if(m_flag_btnC_is_pressed == true){
                    focusChangeImg(MENU_WBGT, MENU_MUSIC);
                    setBtnAllFlgFalse();
                }
                
                if(m_flag_btnB_is_pressed == true){
                    
                    setBtnAllFlgFalse();
                    setStateMachine(MENU,EXIT);
                }*/
                break;

            case EXIT:
            
                
                //setStateMachine(WBGT,ENTRY);
                //setStateMachine(MUSIC_STOP,ENTRY);
                //setStateMachine(MEASURE,ENTRY);

            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction()) {
            case ENTRY:
                setStateMachine(WBGT,DO);

                break;

            case DO:
                setStateMachine(WBGT,EXIT);
                break;

            case EXIT:
                setStateMachine(MENU,ENTRY);
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
                setStateMachine(MUSIC_STOP,DO);
                break;

            case DO:
            setStateMachine(MUSIC_STOP,EXIT);
                break;

            case EXIT:
            setStateMachine(MENU,ENTRY);
            setStateMachine(MUSIC_PLAY,ENTRY);
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
            setStateMachine(MUSIC_PLAY,DO);
                break;

            case DO:
            setStateMachine(MUSIC_PLAY,EXIT);
                break;

            case EXIT:
            //setStateMachine(,ENTRY);
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction()) {
            case ENTRY:
            setStateMachine(MEASURE,DO);
                break;

            case DO:
            setStateMachine(MEASURE,EXIT);
                break;

            case EXIT:
            setStateMachine(MENU,ENTRY);
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction()) {
            case ENTRY:
            setStateMachine(DATE,DO);
                break;

            case DO:
            setStateMachine(DATE,EXIT);
                break;

            case EXIT:
            setStateMachine(MENU,ENTRY);
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
