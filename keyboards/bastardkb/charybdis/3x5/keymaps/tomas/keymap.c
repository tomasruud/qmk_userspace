#include QMK_KEYBOARD_H
#include "tomas.h"

// clang-format off
#define APPLY_LAYOUT(                        \
  K00,K01,K02,K03,K04,   K05,K06,K07,K08,K09,\
  K10,K11,K12,K13,K14,   K15,K16,K17,K18,K19,\
  K20,K21,K22,K23,K24,   K25,K26,K27,K28,K29,\
                  K30,   K31                 \
)                                            \
LAYOUT(                                      \
  K00,K01,K02,K03,K04,   K05,K06,K07,K08,K09,\
  K10,K11,K12,K13,K14,   K15,K16,K17,K18,K19,\
  K20,K21,K22,K23,K24,   K25,K26,K27,K28,K29,\
XXXXXXX, XXXXXXX, K30,   K31, XXXXXXX        \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = SPLIT_DEF_LAYER(APPLY_LAYOUT),
    [NAV] = SPLIT_NAV_LAYER(APPLY_LAYOUT),
    [NUM] = SPLIT_NUM_LAYER(APPLY_LAYOUT),
    [SYM] = SPLIT_SYM_LAYER(APPLY_LAYOUT),
    [FUN] = SPLIT_FUN_LAYER(APPLY_LAYOUT),
};

// clang-format on
