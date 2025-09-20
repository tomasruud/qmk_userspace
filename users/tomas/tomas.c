#include "tomas.h"
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
