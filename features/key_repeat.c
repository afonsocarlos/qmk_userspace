/* Copyright 2025 Carlos Afonso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "key_repeat.h"

#include "afonsocarlos.h"
#include "definitions/keycodes.h"

uint16_t last_keycode = 0;

__attribute__((weak)) void on_key_repeat_default_action(uint16_t keycode, keyrecord_t *record) {
    return;
}

uint16_t get_alt_repeat_keycode(uint16_t keycode) {
    switch (keycode) {
        case HOME_A: return KC_A;
        case HOME_R: return KC_R;
        case HOME_S: return KC_S;
        case HOME_T: return KC_T;
        case HOME_N: return KC_N;
        case HOME_E: return KC_E;
        case HOME_I: return KC_I;
        case HOME_O: return KC_O;

        case KC_LPRN: return KC_RPRN;
        case KC_LBRC: return KC_RBRC;
        case KC_LCBR: return KC_RCBR;
    }

    return keycode;
}

bool process_key_repeat(uint16_t keycode, keyrecord_t* record) {

    if (keycode == LTNUMWORD) {
        if (record->tap.count && record->event.pressed) {
            if (last_keycode) {
                tap_code16(get_alt_repeat_keycode(last_keycode));
            } else {
                on_key_repeat_default_action(keycode, record);
            }
            return false;
        }
    }

    switch (keycode) { // Unpack tapping keycode for tap-hold keys.
#ifndef NO_ACTION_TAPPING
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->tap.count == 0) {
                return true;
            }
            keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
            break;
#    ifndef NO_ACTION_LAYER
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) {
                return true;
            }
            keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
            break;
#    endif // NO_ACTION_LAYER
#endif     // NO_ACTION_TAPPING
    }

    // Determine whether the key is a letter.
    switch (keycode) {
        case KC_MINUS ... KC_SLASH:
        case S(KC_9) ... S(KC_0):
        case S(KC_MINUS) ... S(KC_SLASH):
            last_keycode = keycode;
            break;

        default:
            last_keycode = 0;
    }

    return true;
}
