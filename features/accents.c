#include "accents.h"
#include "definitions/keycodes.h"
#include "quantum.h"

bool process_accent(uint16_t keycode) {

    switch (keycode) {
        // á key
        case KC_ACUT:
            tap_code16(RALT(KC_A));
            return false;
        // â key
        case KC_ACIR:
            tap_code16(RALT(KC_6));
            tap_code16(KC_A);
            return false;
        // ã key
        case KC_ATIL:
            tap_code16(RALT(KC_TILD));
            tap_code16(KC_A);
            return false;
        // ç key
        case KC_CEDL:
            tap_code16(RALT(KC_COMM));
            return false;
        // é key
        case KC_ECUT:
            tap_code16(RALT(KC_E));
            return false;
        // ê key
        case KC_ECIR:
            tap_code16(RALT(KC_6));
            tap_code16(KC_E);
            return false;
        // í key
        case KC_ICUT:
            tap_code16(RALT(KC_I));
            return false;
        // ó key
        case KC_OCUT:
            tap_code16(RALT(KC_O));
            return false;
        // ô key
        case KC_OCIR:
            tap_code16(RALT(KC_6));
            tap_code16(KC_O);
            return false;
        // õ key
        case KC_OTIL:
            tap_code16(RALT(KC_TILD));
            tap_code16(KC_O);
            return false;
        // ú key
        case KC_UCUT:
            tap_code16(RALT(KC_U));
            return false;

        // ¢ key
        case KC_CENT:
            tap_code16(S(RALT(KC_C)));
            return false;
        // € key
        case KC_EURO:
            tap_code16(RALT(KC_5));
            return false;
        // ✓ key
        case KC_CHECK:
            tap_code16(C(S(KC_U)));
            tap_code16(KC_2);
            tap_code16(KC_7);
            tap_code16(KC_1);
            tap_code16(KC_3);
            tap_code16(KC_SPC);
            return false;
        // π key
        case KC_PI:
            tap_code16(C(S(KC_U)));
            tap_code16(KC_0);
            tap_code16(KC_3);
            tap_code16(KC_C);
            tap_code16(KC_0);
            tap_code16(KC_SPC);
            return false;
    }

    return true;
}
