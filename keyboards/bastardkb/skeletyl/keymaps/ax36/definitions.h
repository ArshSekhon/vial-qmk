#pragma once

enum layer_names {
    BASE = 0,
    NAV,
    NUM,
    SYM,
    MOUSE,
    MEDIA,
    FUN,
    CODE,
    SUPER
};

enum custom_keycodes {
    // Editing actions
    AX36_COPY = USER00,
    AX36_PASTE,
    AX36_CUT,
    AX36_LOCK,
    AX36_UNDO,
    AX36_REDO,



    // Screenshot + Screen Recording
    AX36_SCRNSHT_TO_CLIP,
    AX36_SCRNSHT,
    AX36_SCREEN_RECORD,

    AX36_INDICATE_OS,

    OS_CTRL,
    OS_ALT,
    OS_CMD,
    OS_SHFT
};



// TODO: fix this
#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO KC_AGIN
  #define U_PST KC_PSTE
  #define U_CPY KC_COPY
  #define U_CUT KC_CUT
  #define U_UND KC_UNDO
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO SCMD(KC_Z)
  #define U_PST LCMD(KC_V)
  #define U_CPY LCMD(KC_C)
  #define U_CUT LCMD(KC_X)
  #define U_UND LCMD(KC_Z)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C(KC_Y)
  #define U_PST C(KC_V)
  #define U_CPY C(KC_C)
  #define U_CUT C(KC_X)
  #define U_UND C(KC_Z)
#else
  #define U_RDO SCMD(KC_Z)
  #define U_PST LCMD(KC_V)
  #define U_CPY LCMD(KC_C)
  #define U_CUT LCMD(KC_X)
  #define U_UND LCMD(KC_Z)
#endif
