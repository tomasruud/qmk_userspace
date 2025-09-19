#pragma once

#include "quantum.h"

enum layers {
    DEF,
    NAV,
    NUM,
    SYM,
    FUN,
};

// Key definitions for Norwegian macOS layout using ANSI layout.
#define NO_1 KC_1             // 1
#define NO_2 KC_2             // 2
#define NO_3 KC_3             // 3
#define NO_4 KC_4             // 4
#define NO_5 KC_5             // 5
#define NO_6 KC_6             // 6
#define NO_7 KC_7             // 7
#define NO_8 KC_8             // 8
#define NO_9 KC_9             // 9
#define NO_0 KC_0             // 0
#define NO_Q KC_Q             // Q
#define NO_A KC_A             // A
#define NO_B KC_B             // B
#define NO_C KC_C             // C
#define NO_D KC_D             // D
#define NO_E KC_E             // E
#define NO_F KC_F             // F
#define NO_G KC_G             // G
#define NO_H KC_H             // H
#define NO_I KC_I             // I
#define NO_J KC_J             // J
#define NO_K KC_K             // K
#define NO_L KC_L             // L
#define NO_M KC_M             // M
#define NO_N KC_N             // N
#define NO_O KC_O             // O
#define NO_P KC_P             // P
#define NO_R KC_R             // R
#define NO_S KC_S             // S
#define NO_T KC_T             // T
#define NO_U KC_U             // U
#define NO_V KC_V             // V
#define NO_W KC_W             // W
#define NO_X KC_X             // X
#define NO_Y KC_Y             // Y
#define NO_Z KC_Z             // Z
#define NO_AE KC_QUOT         // Æ
#define NO_OSTR KC_SCLN       // Ø
#define NO_ARNG KC_LBRC       // Å
#define NO_LCBR S(A(KC_8))    // {
#define NO_RCBR S(A(KC_9))    // }
#define NO_LPAR S(KC_8)       // (
#define NO_RPAR S(KC_9)       // )
#define NO_LBRC A(KC_8)       // [
#define NO_RBRC A(KC_9)       // ]
#define NO_LABK KC_GRV        // <
#define NO_RABK S(KC_GRV)     // >
#define NO_BLSH S(A(KC_7))    // (backslash)
#define NO_PIPE A(KC_7)       // |
#define NO_SLSH S(KC_7)       // /
#define NO_TILD A(KC_RBRC)    // ~ (dead)
#define NO_QUOT KC_NUBS       // '
#define NO_DQOU S(KC_2)       // "
#define NO_HASH S(KC_3)       // #
#define NO_AT KC_BSLS         // @
#define NO_DLR S(KC_4)        // $
#define NO_PERC S(KC_5)       // %
#define NO_AMPR S(KC_6)       // &
#define NO_ASTR S(NO_AT)      // *
#define NO_MINS KC_SLSH       // -
#define NO_USCR S(NO_MINS)    // _
#define NO_CLON S(KC_DOT)     // :
#define NO_COMM KC_COMM       // ,
#define NO_SEMI LSFT(NO_COMM) // ;
#define NO_DOT KC_DOT         // .
#define NO_COMM KC_COMM       // ,
#define NO_EXLM S(NO_1)       // !
#define NO_ACUT KC_EQL        // ` (dead)
#define NO_GRV S(KC_EQL)      // ´ (dead)
#define NO_CIRC S(KC_RBRC)    // ^ (dead)
#define NO_UMLA KC_RBRC       // ¨ (dead)
#define NO_EQL S(KC_0)        // =
#define NO_PLUS KC_MINS       // +
#define NO_QUES S(KC_MINS)    // ?

#define EMOJI G(C(KC_SPC)) // Emoji

#define TR_TMUX C(NO_A) // Tmux trigger
#define TR_SCDN C(NO_D) // Scroll down
#define TR_SCUP C(NO_U) // Scroll up
#define TR_JMPF C(NO_I) // Jump forwards
#define TR_JMPB C(NO_O) // Jump backwards
#define TR_COPY G(NO_C) // Copy
#define TR_PAST G(NO_V) // Paste
#define TR_WCTR C(S(A(NO_G))) // Center window
#define TR_WGRW C(S(A(NO_M))) // Maximise window

#define SW_NTAB C(KC_TAB)    // Next tab
#define SW_PTAB C(S(KC_TAB)) // Prev tab

enum keycodes {
    SW_APP = SAFE_RANGE, // Switch to next app (cmd-tab)
    SW_WIN,              // Switch to next window (cmd-<)
};

// clang-format off
#define SPLIT_DEF_LAYER \
NO_Q    ,NO_W    ,NO_E    ,NO_R    ,NO_T    ,        NO_Y    ,NO_U    ,NO_I    ,NO_O    ,NO_P    ,\
NO_A    ,NO_S    ,NO_D    ,NO_F    ,NO_G    ,        NO_H    ,NO_J    ,NO_K    ,NO_L    ,NO_OSTR ,\
NO_Z    ,NO_X    ,NO_C    ,NO_V    ,NO_B    ,        NO_N    ,NO_M    ,NO_ARNG ,NO_AE   ,MO(FUN) ,\
                                    MO(NAV) ,     LT(NUM, KC_SPC)

#define SPLIT_NAV_LAYER \
XXXXXXX ,XXXXXXX ,SW_PTAB ,SW_NTAB ,CW_TOGG ,        KC_ESC  ,KC_PGDN ,KC_PGUP ,TR_JMPF ,TR_JMPB ,\
OS_LALT ,OS_LGUI ,OS_LCTL ,OS_LSFT ,TR_COPY ,        KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,\
EMOJI   ,SW_WIN  ,SW_APP  ,TR_TMUX ,TR_PAST ,        KC_TAB  ,KC_HOME ,KC_END  ,TR_WCTR ,TR_WGRW ,\
                                    _______ ,     LT(NUM, KC_ENT)

#define SPLIT_NUM_LAYER \
XXXXXXX ,NO_7    ,NO_8    ,NO_9    ,NO_COMM ,        NO_CIRC ,NO_TILD ,NO_ACUT ,NO_GRV  ,NO_UMLA ,\
XXXXXXX ,NO_4    ,NO_5    ,NO_6    ,NO_DOT  ,        KC_BSPC ,OS_RSFT ,OS_RCTL ,OS_RGUI ,OS_RALT ,\
XXXXXXX ,NO_1    ,NO_2    ,NO_3    ,NO_0    ,        XXXXXXX ,NO_CLON ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
                                    _______ ,        _______

#define SPLIT_SYM_LAYER \
XXXXXXX ,NO_HASH ,NO_DQOU ,NO_QUES ,NO_EXLM ,        NO_AMPR ,NO_LPAR ,NO_RPAR ,NO_SLSH ,XXXXXXX ,\
NO_DLR  ,NO_ASTR ,NO_QUOT ,NO_SEMI ,NO_MINS ,        NO_EQL  ,NO_LCBR ,NO_RCBR ,NO_PIPE ,XXXXXXX ,\
NO_PERC ,NO_LABK ,NO_RABK ,NO_PLUS ,NO_USCR ,        NO_AT   ,NO_LBRC ,NO_RBRC ,NO_BLSH ,XXXXXXX ,\
                                    _______ ,        _______

#define SPLIT_FUN_LAYER \
XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,\
XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,\
                                    _______ ,        _______


