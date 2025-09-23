#include "tomas.h"
#include "norwegian-ansi.h"
#include "swapper.h"

bool sw_app_active = false;
bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record);
    update_swapper(&sw_win_active, KC_LGUI, NO_LABK, SW_WIN, keycode, record);

    if (record->event.pressed && keycode == KC_ESC) {
        // If any one-shot modifiers are active, cancel them
        if (get_oneshot_mods()) {
            clear_oneshot_mods();
            return false; // swallow Esc (use it purely as "cancel")
        }
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NAV, NUM, SYM);
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case NO_USCR:
        case NO_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}
