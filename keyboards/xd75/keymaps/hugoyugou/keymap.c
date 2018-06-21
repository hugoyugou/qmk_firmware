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
#define MQW 2
#define MFN 3
#define _______ KC_TRNS
#define __ ""

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
    MC_CP,
    MC_MCP,
    MC_DEF,
    MC_MAC
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
 * | LCTRL  | LGUI   | LALT   | SPACE  | FN     | DEL    | DEFLT  | MAC    | [      | ]      | LEFT   | DOWN   | RIGHT  | 0      | P.     |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  MO(_FN), KC_ENT  },
  { KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, MC_P7,   MC_P8,   MC_P9   },
  { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, MC_P4,   MC_P5,   MC_P6   },
  { KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP  , MC_P1,   MC_P2,   MC_P3   },
  { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_FN), KC_DEL,  MC_DEF,  MC_MAC,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, MC_P0,   KC_PDOT },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        | C & P  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | CALC   | DELETE | INSERT | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        | PAUSE  | CAP LK | SCR LK |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | \      |        |        |        |        |        |        |        |        |        | PGUP   | RALT   | RSHIFT | RCTRL  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | HOME   | PGDOWN | END    | RCLICK |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, MC_CP   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CALC, KC_DEL,  KC_INS , KC_PSCR },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_CAPS, KC_SLCK },
  { _______, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_RALT, KC_RSFT, KC_RCTL },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END, KC_BTN2, _______ },
 },

 /* QWERTY (MAC)
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | FN     | ENTER  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
  * | `      | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | BACKSP | P7  P/ | P8  P* | P9  P- |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
  * | TAB    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | P4     | P5     | P6  P+ |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
  * | LSHIFT | /      | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | UP     | P1     | P2     | P3 PEN |
  * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
  * | LCTRL  | LOPT   | LCMD   | SPACE  | FN     | DEL    | DEFLT  | MAC    | [      | ]      | LEFT   | DOWN   | RIGHT  | 0      | P.     |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */

  [MQW] = { /* QWERTY (MAC) */
   { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  MO(MFN), KC_ENT  },
   { KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, MC_P7,   MC_P8,   MC_P9   },
   { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, MC_P4,   MC_P5,   MC_P6   },
   { KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP  , MC_P1,   MC_P2,   MC_P3   },
   { KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  MO(MFN), KC_DEL,  MC_DEF,  MC_MAC,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, MC_P0,   KC_PDOT },
  },

  /* FUNCTION (MAC)
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        | C & P  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        | CALC   | DELETE | INSERT | PR SCR |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        |        | PAUSE  | RSHIFT | SCR LK |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        | \      |        |        |        |        |        |        |        |        |        | PGUP   | RCMD   | ROPT   | RCTRL  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        | HOME   | PGDOWN | END    | RCLICK | CAP LK |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [MFN] = { /* FUNCTION (MAC) */
   { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, MC_MCP  },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CALC, KC_DEL,  KC_INS , KC_PSCR },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_RSFT, KC_SLCK },
   { _______, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_RGUI, KC_RALT, KC_RCTL },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END, KC_BTN2, KC_CAPS },
  }
};

const uint16_t PROGMEM fn_actions[] = {

};

bool is_copied = false;

#define INIT_NUMPAD(MC_KEY) bool is_ ## MC_KEY ## _pressed = false; \
  bool is_ ## MC_KEY ## _shift_pressed = false;

#define CASE_NUMPAD_2(MC_KEY, KEY) case MC_KEY: \
  if (record->event.pressed) { \
    if (!(keyboard_report->mods & MOD_BIT(KC_LSFT))) { \
      is_ ## MC_KEY ## _pressed = true; \
      SEND_STRING(SS_DOWN(KEY)); \
    } \
  } else { \
    if (is_ ## MC_KEY ## _pressed) { \
      is_ ## MC_KEY ## _pressed = false; \
      SEND_STRING(SS_UP(KEY)); \
    } \
  } \
  break;

#define CASE_NUMPAD_3(MC_KEY, KEY, SHIFT_KEY) case MC_KEY: \
  if (record->event.pressed) { \
    if ((keyboard_report->mods & MOD_BIT(KC_LSFT))) { \
      is_ ## MC_KEY ## _shift_pressed = true; \
      SEND_STRING(SS_DOWN(SHIFT_KEY)); \
    } else { \
      is_ ## MC_KEY ## _pressed = true; \
      SEND_STRING(SS_DOWN(KEY)); \
    } \
  } else { \
    if (is_ ## MC_KEY ## _shift_pressed) { \
      is_ ## MC_KEY ## _shift_pressed = false; \
      SEND_STRING(SS_UP(SHIFT_KEY)); \
    } \
    if (is_ ## MC_KEY ## _pressed) { \
      is_ ## MC_KEY ## _pressed = false; \
      SEND_STRING(SS_UP(KEY)); \
    } \
  } \
  break;

INIT_NUMPAD(MC_P0)
INIT_NUMPAD(MC_P1)
INIT_NUMPAD(MC_P2)
INIT_NUMPAD(MC_P3)
INIT_NUMPAD(MC_P4)
INIT_NUMPAD(MC_P5)
INIT_NUMPAD(MC_P6)
INIT_NUMPAD(MC_P7)
INIT_NUMPAD(MC_P8)
INIT_NUMPAD(MC_P9)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    CASE_NUMPAD_2(MC_P0, X_KP_0)
    CASE_NUMPAD_2(MC_P1, X_KP_1)
    CASE_NUMPAD_2(MC_P2, X_KP_2)
    CASE_NUMPAD_3(MC_P3, X_KP_3, X_KP_ENTER)
    CASE_NUMPAD_2(MC_P4, X_KP_4)
    CASE_NUMPAD_2(MC_P5, X_KP_5)
    CASE_NUMPAD_3(MC_P6, X_KP_6, X_KP_PLUS)
    CASE_NUMPAD_3(MC_P7, X_KP_7, X_KP_SLASH)
    CASE_NUMPAD_3(MC_P8, X_KP_8, X_KP_ASTERISK)
    CASE_NUMPAD_3(MC_P9, X_KP_9, X_KP_MINUS)
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
    case MC_MCP:
      if (record->event.pressed) {
        if (is_copied) {
          SEND_STRING(SS_LGUI("v"));
        } else {
          is_copied = true;
          SEND_STRING(SS_LGUI("c"));
        }
      }
      break;
    case MO(_FN):
    case MO(MFN):
      if (!record->event.pressed) {
        is_copied = false;
      }
      break;
    case MC_DEF:
      set_single_persistent_default_layer(_QW);
      break;
    case MC_MAC:
      set_single_persistent_default_layer(MQW);
      break;
  }
  return true;
};
