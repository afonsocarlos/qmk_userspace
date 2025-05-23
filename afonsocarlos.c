/*
Copyright 2025 Carlos Afonso  <@afonsocarlos>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <ctype.h>
#include "keycodes.h"
#include "modifiers.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

#include "afonsocarlos.h"
#include "definitions/keycodes.h"
#include "features/accents.h"
#include "features/caps_line.h"
#include "features/key_repeat.h"
#include "features/num_word.h"
#include "features/os_toggle.h"
#include "features/shortcuts.h"
#include "features/sm_td.h"

#define HOME_CTRL is_macos() ? KC_LGUI : KC_LCTL
#define HOME_GUI is_macos() ? KC_LCTL : KC_LGUI



void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(HOME_A, KC_A, HOME_GUI, 2)
        SMTD_MT(HOME_R, KC_R, KC_LALT, 2)
        SMTD_MT(HOME_S, KC_S, HOME_CTRL, 2)
        SMTD_MT(HOME_T, KC_T, KC_LSFT, 2)

        SMTD_MT(HOME_N, KC_N, KC_RSFT, 2)
        SMTD_MT(HOME_E, KC_E, HOME_CTRL, 2)
        SMTD_MT(HOME_I, KC_I, KC_RALT, 2)
        SMTD_MT(HOME_O, KC_O, HOME_GUI, 2)
    }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_I:
            if (timeout == SMTD_TIMEOUT_TAP) return 600;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 3;
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 150;
        case HOME_O:
            if (timeout == SMTD_TIMEOUT_TAP) return 600;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 1;
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 150;
    }

    return get_smtd_timeout_default(timeout);
}


void on_key_repeat_default_action(uint16_t keycode, keyrecord_t *record) {
    if (is_num_word_enabled()) {
        toggle_num_word();
    }
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_key_repeat(keycode, record)) { return false; } // TODO: Move this call to the end of this block after smtd 0.5 update
    if (!process_smtd(keycode, record)) { return false; }
    if (!process_accents(keycode, record)) { return false; }
    if (!process_shortcuts(keycode, record)) { return false; }
    if (!process_os_toggle(keycode, record)) { return false; }
    if (!process_caps_line(keycode, record)) { return false; }
    if (!process_record_num_word(keycode, record)) { return false; }

    switch (keycode) {
        case HOME_W0:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_0));
                return false;
            }
            break;
        case CKC_W1:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_1));
                return false;
            }
            break;
        case CKC_W2:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_2));
                return false;
            }
            break;
        case CKC_W3:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_3));
                return false;
            }
            break;
        case HOME_W4:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_4));
                return false;
            }
            break;
        case HOME_W5:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_5));
                return false;
            }
            break;
        case HOME_W6:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_6));
                return false;
            }
            break;
        case CKC_W7:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_7));
                return false;
            }
            break;
        case CKC_W8:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_8));
                return false;
            }
            break;
        case CKC_W9:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_9));
                return false;
            }
            break;
        case KC_LEQT:
            if (record->event.pressed) {
                SEND_STRING("<=");
                return false;
            }
            break;
        case HOME_DE:
            if (record->tap.count && record->event.pressed) {
                SEND_STRING("==");
                return false;
            }
            break;
        case HOME_TE:
            if (record->tap.count && record->event.pressed) {
                SEND_STRING("===");
                return false;
            }
            break;
        case HOME_NE:
            if (record->tap.count && record->event.pressed) {
                SEND_STRING("!=");
                return false;
            }
            break;
        case HOME_GE:
            if (record->tap.count && record->event.pressed) {
                SEND_STRING(">=");
                return false;
            }
            break;
        case KC_TARW:
            if (record->event.pressed) {
                SEND_STRING("->");
                return false;
            }
            break;
        case KC_FARW:
            if (record->event.pressed) {
                SEND_STRING("=>");
                return false;
            }
            break;
        case KC_DCLN:
            if (record->event.pressed) {
                SEND_STRING("::");
                return false;
            }
            break;
    }

    return process_record_keymap(keycode, record);
}

void caps_word_set_user(bool active) {
    if (active) {
        autoshift_disable();
    }
    else {
        autoshift_enable();
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LTMOUS_SPC) {
        return false;
    }

    switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
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
        case C(KC_BSPC): // Continus Caps Word on "Delete keyword"
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:

        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
        case KC_DLR:
        case KC_SLSH:
        case KC_QUES:
        case KC_LPRN:
        case KC_RPRN:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_COMM:
            register_code16((!shifted) ? KC_COMM : KC_SCLN);
            break;
        case KC_DOT:
            register_code16((!shifted) ? KC_DOT : KC_COLN);
            break;
        case KC_DLR:
            register_code16((!shifted) ? KC_DLR : RALT(KC_AT));
            break;
        case KC_SLSH:
            register_code16((!shifted) ? KC_SLSH : KC_PIPE);
            break;
        case KC_QUES:
            register_code16((!shifted) ? KC_QUES : KC_EXLM);
            break;
        case KC_LPRN:
            register_code16((!shifted) ? KC_LPRN : KC_LABK);
            break;
        case KC_RPRN:
            register_code16((!shifted) ? KC_RPRN : KC_RABK);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_COMM:
            unregister_code16((!shifted) ? KC_COMM : KC_SCLN);
            break;
        case KC_DOT:
            unregister_code16((!shifted) ? KC_DOT : KC_COLN);
            break;
        case KC_DLR:
            unregister_code16((!shifted) ? KC_DLR : RALT(KC_AT));
            break;
        case KC_SLSH:
            unregister_code16((!shifted) ? KC_SLSH : KC_PIPE);
            break;
        case KC_QUES:
            unregister_code16((!shifted) ? KC_QUES : KC_EXLM);
            break;
        case KC_LPRN:
            unregister_code16((!shifted) ? KC_LPRN : KC_LABK);
            break;
        case KC_RPRN:
            unregister_code16((!shifted) ? KC_RPRN : KC_RABK);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_PIPE);
const key_override_t question_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &semicolon_key_override,
    &colon_key_override,
    &pipe_key_override,
    &question_key_override
};
#endif // KEY_OVERRIDES
