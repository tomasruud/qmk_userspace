#include QMK_KEYBOARD_H
#include "tomas.h"

#define CHARYBDIS_MINIMUM_DEFAULT_DPI 200
#define PTR_TRIGGER_THRESHOLD 2

enum extra_layers {
    PTR = FUN + 1,
};

enum extra_keycodes {
    TR_EXPT = KEYMAP_SAFE_RANGE, // Exit pointer layer
};

// clang-format off
#define LAYOUT_LAYER_POINTER LAYOUT(                                                                  \
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DPI_MOD ,\
    KC_LALT ,KC_LGUI ,KC_LCTL ,KC_LSFT ,XXXXXXX ,        XXXXXXX ,DRGSCRL ,XXXXXXX ,XXXXXXX ,DPI_RMOD,\
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
                      XXXXXXX ,TR_EXPT ,DRGSCRL ,        KC_BTN2 ,KC_BTN1                             \
)

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
  XXXXXXX,K30,XXXXXXX,   XXXXXXX,K31         \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = SPLIT_DEF_LAYER(APPLY_LAYOUT),
    [CDH] = SPLIT_CDH_LAYER(APPLY_LAYOUT),
    [NAV] = SPLIT_NAV_LAYER(APPLY_LAYOUT),
    [NUM] = SPLIT_NUM_LAYER(APPLY_LAYOUT),
    [SYM] = SPLIT_SYM_LAYER(APPLY_LAYOUT),
    [FUN] = SPLIT_FUN_LAYER(APPLY_LAYOUT),
    [PTR] = LAYOUT_LAYER_POINTER,
};

// clang-format on

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > PTR_TRIGGER_THRESHOLD || abs(mouse_report.y) > PTR_TRIGGER_THRESHOLD) {
        if (IS_LAYER_OFF(PTR)) {
            layer_on(PTR);
        }
    }

    // Invert Y scroll
    mouse_report.v = -mouse_report.v;

    return mouse_report;
}

bool process_record_user_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode == TR_EXPT) {
        // Exit pointer layer on keydown to avoid having to press twice. Without
        // this, you have to push the button first one time to toggle the layer
        // off, and then again to trigger the new keycode.
        if (IS_LAYER_ON(PTR)) {
            layer_off(PTR);
        }
    }

    return true;
}
