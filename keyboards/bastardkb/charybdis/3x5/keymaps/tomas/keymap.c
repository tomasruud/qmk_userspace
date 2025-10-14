#include QMK_KEYBOARD_H
#include "tomas.h"

#define CHARYBDIS_MINIMUM_DEFAULT_DPI 400
#define PTR_TRIGGER_THRESHOLD 8

enum extra_layers {
    PTR = FUN + 1,
};

// clang-format off
#define LAYOUT_LAYER_POINTER LAYOUT(                                                                  \
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        KC_ESC  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,DRG_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,\
                      XXXXXXX ,XXXXXXX ,XXXXXXX ,        KC_BTN1 ,KC_BTN2                             \
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
XXXXXXX, XXXXXXX, K30,   K31, XXXXXXX        \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = SPLIT_DEF_LAYER(APPLY_LAYOUT),
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
    return mouse_report;
}

bool process_record_user_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode == KC_ESC) {
        // Cancel snipe mode if active.
        if (charybdis_get_pointer_sniping_enabled()) {
            charybdis_set_pointer_sniping_enabled(false);
            return false; // swallow Esc (use it purely as "cancel")
        }

        // Cancel scroll mode if active.
        if (charybdis_get_pointer_dragscroll_enabled()) {
            charybdis_set_pointer_dragscroll_enabled(false);
            return false; // swallow Esc (use it purely as "cancel")
        }

        // Cancel pointer layer if escape is pressed.
        if (IS_LAYER_ON(PTR)) {
            layer_off(PTR);
            return false; // swallow Esc (use it purely as "cancel")
        }
    }

    return true;
}
