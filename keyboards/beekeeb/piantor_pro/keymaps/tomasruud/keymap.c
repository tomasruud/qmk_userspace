#include QMK_KEYBOARD_H
#include "tomasruud.h"

// clang-format off
#define TRANSLATE_LAYER(                     \
  K00,K01,K02,K03,K04,   K05,K06,K07,K08,K09,\
  K10,K11,K12,K13,K14,   K15,K16,K17,K18,K19,\
  K20,K21,K22,K23,K24,   K25,K26,K27,K28,K29,\
                  K30,   K31                 \
)                                            \
LAYOUT_split_3x6_3(                                          \
XXXXXXX, K00,K01,K02,K03,K04,   K05,K06,K07,K08,K09, XXXXXXX,\
XXXXXXX, K10,K11,K12,K13,K14,   K15,K16,K17,K18,K19, XXXXXXX,\
XXXXXXX, K20,K21,K22,K23,K24,   K25,K26,K27,K28,K29, XXXXXXX,\
        XXXXXXX, XXXXXXX, K30,   K31, XXXXXXX, XXXXXXX       \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = TRANSLATE_LAYER(SPLIT_DEF_LAYER),
    [NAV] = TRANSLATE_LAYER(SPLIT_NAV_LAYER),
    [NUM] = TRANSLATE_LAYER(SPLIT_NUM_LAYER),
    [SYM] = TRANSLATE_LAYER(SPLIT_SYM_LAYER),
    [FUN] = TRANSLATE_LAYER(SPLIT_FUN_LAYER),
};
