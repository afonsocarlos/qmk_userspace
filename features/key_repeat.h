/* Copyright 2025 Carlos Afonso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
-* the Free Software Foundation, either version 2 of the License, or
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

#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

uint16_t get_alt_repeat_keycode(uint16_t keycode);
void on_key_repeat_default_action(uint16_t keycode, keyrecord_t *record);

bool process_key_repeat(uint16_t keycode, keyrecord_t *record);
