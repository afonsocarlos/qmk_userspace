/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

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

#include "afonsocarlos.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
        KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         KC_M,  HOME_N,  HOME_E,  HOME_I,   HOME_O,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT,  KC_SLSH,
  //|--------+--------+--------+--------+----------------|    |----------------+--------+--------+--------+--------+--------|
                                     LTNUMWORD, LTMOUS_SPC,   LTNAV_ENT, OSM_LSFT
                                     //`------------------'   `-----------------'
  ),

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
 LGUI_T(KC_Q),    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LCTL_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+----------------|    |----------------+--------+--------+--------+--------+--------|
                                        _______, LTMOUS_SPC,  LTNAV_ENT, _______
                                     //`------------------'   `-----------------'
  ),

  [_NUMS] = LAYOUT(
  //,--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
      KC_MINS,    KC_7,    KC_8,    KC_9, KC_PLUS,                      _______, _______, _______, _______,  _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       HOME_0,  HOME_4,  HOME_5,  HOME_6, KC_ASTR,                      KC_LEQT, HOME_DE, HOME_TE, HOME_NE, HOME_GE,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_DOT,    KC_1,    KC_2,    KC_3, KC_SLSH,                      KC_MINS, KC_TARW, KC_FARW, KC_DCLN, KC_SLSH,
  //|--------+--------+--------+--------+----------------|    |----------------+--------+--------+--------+--------+--------|
                                      _______,  LTMOUS_SPC,   LTNAV_ENT, KC_CANCEL
                                     //`------------------'   `-----------------'
  ),

  [_NAV] = LAYOUT(
  //,--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
      XXXXXXX,   KC_F7,   KC_F8,   KC_F9, KC_F10,                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, QK_LLCK,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, HOME_F4, HOME_F5, HOME_F6, KC_F11,                       KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_RCTL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3, KC_F12,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+----------------|    |----------------+--------+--------+--------+--------+--------|
                                  _______, LT(_SYS,KC_SPC),     _______, _______
                                     //`------------------'   `-----------------'
  ),

  // Extra one shot layer for accessing Function and accents keys
  [_MOUSE] = LAYOUT(
  //,--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
      KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX,                      XXXXXXX,  CKC_W7,  CKC_W8,  CKC_W9, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, HOME_W4, HOME_W5, HOME_W6, HOME_W0,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, XXXXXXX,                      XXXXXXX,  CKC_W1,  CKC_W2,  CKC_W3, XXXXXXX,
  //|--------+--------+--------+--------+----------------|    |----------------+--------+--------+--------+--------+--------|
                                          _______, _______,     LT(_SYS,KC_ENT),  _______
                                     //`------------------'   `-----------------'
  ),

  [_SYS] = LAYOUT(
  //,--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
      QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MRWD, XXXXXXX, KC_MFFD, KC_PSCR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BT_PRF1, BT_PRF2, BT_PRF3, BT_PRF4, BT_UNPR,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI,  TG_WIN,  TG_MAC, TG_LINUX,                     KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX, KC_BRID,
  //|--------+--------+--------+--------+----------------|    |----------------+--------+--------+--------+--------+--------|
                                          _______, _______,     _______, _______
                                     //`------------------'   `-----------------'
  ),

  // Extra layer for Numpad and Gaming keys
  [_GAME_NUMPAD] = LAYOUT(
  //,--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
         KC_Q,    KC_W,    KC_E,    KC_R,   KC_F5,                       KC_NUM,    KC_7,    KC_8,    KC_9, QK_LLCK,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F, XXXXXXX,                      KC_PLUS,    KC_4,    KC_5,    KC_6,  KC_MINS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_1,    KC_2,    KC_3,    KC_4, XXXXXXX,                      KC_ASTR,    KC_1,    KC_2,    KC_3,  KC_SLSH,
  //|--------+--------+--------+--------+----------------|    |----------------+--------+--------+--------+--------+--------|
                                          _______,  KC_SPC,    _______,   _______
                                     //`------------------'   `-----------------'
  ),
};
