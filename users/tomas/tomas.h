#pragma once

#include "quantum.h"
#include "norwegian-ansi.h"
#include "oneshot.h"

enum layers {
    DEF, // Qwerty default layer
    NAV, // Navigation and util layer
    NUM, // Number and some symbols layer
    SYM, // Symbols layer
    FUN, // Misc functions layer
};

#define TR_EMOJ G(C(KC_SPC))  // Emoji
#define TR_TMUX C(NO_A)       // Tmux trigger
#define TR_JMPF C(NO_I)       // Jump forwards
#define TR_JMPB C(NO_O)       // Jump backwards
#define TR_COPY G(NO_C)       // Copy
#define TR_PAST G(NO_V)       // Paste
#define TR_WCTR C(S(A(NO_G))) // Center window
#define TR_WGRW C(S(A(NO_M))) // Maximise window

#define SW_NTAB C(KC_TAB)    // Next tab
#define SW_PTAB C(S(KC_TAB)) // Prev tab

enum keycodes {
    SW_APP = SAFE_RANGE, // Switch to next app (cmd-tab)
    SW_WIN,              // Switch to next window (cmd-<)
    KEYMAP_SAFE_RANGE,   // Can be referenced by specific keymaps for adding additional keys
};

#define NUM_SPC LT(NUM, KC_SPC)
#define NUM_ENT LT(NUM, KC_ENT)

// clang-format off
#define SPLIT_DEF_LAYER(APPLY) APPLY(                                                                 \
    NO_Q    ,NO_W    ,NO_E    ,NO_R    ,NO_T    ,        NO_Y    ,NO_U    ,NO_I    ,NO_O    ,NO_P    ,\
    NO_A    ,NO_S    ,NO_D    ,NO_F    ,NO_G    ,        NO_H    ,NO_J    ,NO_K    ,NO_L    ,NO_OSTR ,\
    NO_Z    ,NO_X    ,NO_C    ,NO_V    ,NO_B    ,        NO_N    ,NO_M    ,NO_ARNG ,NO_AE   ,MO(FUN) ,\
                                        MO(NAV) ,        NUM_SPC                                      \
)

#define SPLIT_NAV_LAYER(APPLY) APPLY(                                                                 \
    XXXXXXX ,QK_REP  ,SW_PTAB ,SW_NTAB ,CW_TOGG ,        KC_ESC  ,KC_PGDN ,KC_PGUP ,TR_JMPF ,TR_JMPB ,\
    OS_LALT ,OS_LGUI ,OS_LCTL ,OS_LSFT ,TR_COPY ,        KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,\
    TR_EMOJ ,SW_WIN  ,SW_APP  ,TR_TMUX ,TR_PAST ,        KC_TAB  ,KC_HOME ,KC_END  ,TR_WCTR ,TR_WGRW ,\
                                        _______ ,        NUM_ENT                                      \
)

#define SPLIT_NUM_LAYER(APPLY) APPLY(                                                                 \
    XXXXXXX ,NO_7    ,NO_8    ,NO_9    ,NO_COMM ,        NO_CIRC ,NO_TILD ,NO_ACUT ,NO_GRV  ,NO_UMLA ,\
    XXXXXXX ,NO_4    ,NO_5    ,NO_6    ,NO_DOT  ,        KC_BSPC ,OS_RSFT ,OS_RCTL ,OS_RGUI ,OS_RALT ,\
    XXXXXXX ,NO_1    ,NO_2    ,NO_3    ,NO_0    ,        XXXXXXX ,NO_CLON ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
                                        _______ ,        _______                                      \
)

#define SPLIT_SYM_LAYER(APPLY) APPLY(                                                                 \
    XXXXXXX ,NO_HASH ,NO_DQOU ,NO_QUES ,NO_EXLM ,        NO_AMPR ,NO_LPAR ,NO_RPAR ,NO_SLSH ,XXXXXXX ,\
    NO_DLR  ,NO_ASTR ,NO_QUOT ,NO_SEMI ,NO_MINS ,        NO_EQL  ,NO_LCBR ,NO_RCBR ,NO_PIPE ,NO_PERC ,\
    XXXXXXX ,NO_LABK ,NO_RABK ,NO_PLUS ,NO_USCR ,        NO_AT   ,NO_LBRC ,NO_RBRC ,NO_BLSH ,XXXXXXX ,\
                                        _______ ,        _______                                      \
)

#define SPLIT_FUN_LAYER(APPLY) APPLY(                                                                 \
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DT_PRNT ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,\
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DT_UP   ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DT_DOWN ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,\
                                        XXXXXXX ,        XXXXXXX                                      \
)

// clang-format on
