/* Copyright 2017 Wunder 2018 HugoYuGou
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1
#define _______ KC_TRNS
#define __ ""
#define OS_RALT OSM(MOD_RALT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RCTL OSM(MOD_RCTL)

enum custom_keycodes {
    MC_P0 = SAFE_RANGE,
    MC_P1,
    MC_P2,
    MC_P3,
    MC_P4,
    MC_P5,
    MC_P6,
    MC_P7,
    MC_P8,
    MC_P9,
    MC_CP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | FN     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | `      | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | BACKSP | P7  P/ | P8  P* | P9  P- |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | TAB    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | P4     | P5     | P6  P+ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | /      | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | UP     | P1     | P2     | P3 PEN |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | SPACE  | HOME   | PGUP   | PGDOWN | END    | [      | ]      | LEFT   | DOWN   | RIGHT  | 0      | P.     |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  MO(_FN), KC_ENT  },
  { KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, MC_P7,   MC_P8,   MC_P9   },
  { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, MC_P4,   MC_P5,   MC_P6   },
  { KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP  , MC_P1,   MC_P2,   MC_P3   },
  { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, MC_P0,   KC_PDOT },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        | C & P  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | CALC   | DELETE | INSERT | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        | PAUSE  | CAP LK | SCR LK |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | \      |        |        |        |        |        |        |        |        |        |        | RALT   | RSHIFT | RCTRL  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        | RCLICK |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, MC_CP   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CALC, KC_DEL,  KC_INS , KC_PSCR },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_CAPS, KC_SLCK },
  { _______, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RALT, KC_RSFT, KC_RCTL },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN2, _______ },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

bool is_copied = false;

bool is_numpad_pressed[10][2] = {
  { false, false },
  { false, false },
  { false, false },
  { false, false },
  { false, false },
  { false, false },
  { false, false },
  { false, false },
  { false, false },
  { false, false }
};

const bool numpad_shift_diff[10] = {
  false, false, false, true, false, false, true, true, true, true
};

const char* numpad_keymaps[10][2][2] = {
  {
    {SS_DOWN(X_KP_0), SS_UP(X_KP_0)}
  },
  {
    {SS_DOWN(X_KP_1), SS_UP(X_KP_1)}
  },
  {
    {SS_DOWN(X_KP_2), SS_UP(X_KP_2)}
  },
  {
    {SS_DOWN(X_KP_3), SS_UP(X_KP_3)},
    {SS_DOWN(X_KP_ENTER), SS_UP(X_KP_ENTER)}
  },
  {
    {SS_DOWN(X_KP_4), SS_UP(X_KP_4)}
  },
  {
    {SS_DOWN(X_KP_5), SS_UP(X_KP_5)}
  },
  {
    {SS_DOWN(X_KP_6), SS_UP(X_KP_6)},
    {SS_DOWN(X_KP_PLUS), SS_UP(X_KP_PLUS)}
  },
  {
    {SS_DOWN(X_KP_7), SS_UP(X_KP_7)},
    {SS_DOWN(X_KP_SLASH), SS_UP(X_KP_SLASH)}
  },
  {
    {SS_DOWN(X_KP_8), SS_UP(X_KP_8)},
    {SS_DOWN(X_KP_ASTERISK), SS_UP(X_KP_ASTERISK)}
  },
  {
    {SS_DOWN(X_KP_9), SS_UP(X_KP_9)},
    {SS_DOWN(X_KP_MINUS), SS_UP(X_KP_MINUS)}
  }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode >= MC_P0 && keycode <= MC_P9) {
    uint16_t numpad_number = keycode - MC_P0;
    if (record->event.pressed) {
      if ((keyboard_report->mods & MOD_BIT(KC_LSFT)) && numpad_shift_diff[numpad_number] != false) {
        if (is_numpad_pressed[numpad_number][0]) {
          //SEND_STRING(SS_UP(X_KP_7));
          send_string(numpad_keymaps[numpad_number][0][1]);
          is_numpad_pressed[numpad_number][0] = false;
        }
        is_numpad_pressed[numpad_number][1] = true;
        //SEND_STRING(SS_DOWN(X_KP_SLASH));
        send_string(numpad_keymaps[numpad_number][1][0]);
      } else {
        if (is_numpad_pressed[numpad_number][1] && numpad_shift_diff[numpad_number] != false) {
          //SEND_STRING(SS_UP(X_KP_SLASH));
          send_string(numpad_keymaps[numpad_number][1][1]);
          is_numpad_pressed[numpad_number][1] = false;
        }
        is_numpad_pressed[numpad_number][0] = true;
        //SEND_STRING(SS_DOWN(X_KP_7));
        send_string(numpad_keymaps[numpad_number][0][0]);
      }
    } else {
      if (is_numpad_pressed[numpad_number][1] && numpad_shift_diff[numpad_number] != false) {
        is_numpad_pressed[numpad_number][1] = false;
        //SEND_STRING(SS_UP(X_KP_SLASH));
        send_string(numpad_keymaps[numpad_number][1][1]);
      }
      if (is_numpad_pressed[numpad_number][0]) {
        is_numpad_pressed[numpad_number][0] = false;
        //SEND_STRING(SS_UP(X_KP_7));
        send_string(numpad_keymaps[numpad_number][0][1]);
      }
    }
  } else {
    switch(keycode) {
      case MC_CP:
        if (record->event.pressed) {
          if (is_copied) {
            SEND_STRING(SS_LCTRL("v"));
          } else {
            is_copied = true;
            SEND_STRING(SS_LCTRL("c"));
          }
        }
        break;
      case MO(1):
        if (!record->event.pressed) {
          is_copied = false;
        }
    }
  }
  return true;
};
