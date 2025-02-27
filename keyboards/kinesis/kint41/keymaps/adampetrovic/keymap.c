/* Copyright 2024 Adam Petrovic
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

#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty
#define LAYER1 1


#define L1_T_SCLN  LT(1, KC_SCLN)

// Rectangle Keycodes
#define RECT_FS     LOPT(LCMD(KC_F))  // Rectangle - Fullscreen
#define RECT_LH     LOPT(LCMD(KC_LEFT))  // Rectangle - Left Half
#define RECT_RH     LOPT(LCMD(KC_RIGHT))  // Rectangle - Right Half
#define RECT_TH     LOPT(LCMD(KC_UP))  // Rectangle - Top Half
#define RECT_BH     LOPT(LCMD(KC_DOWN))  // Rectangle - Bottom Half

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Caps   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Esc    |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Cmd  |         | ROpt  | Meh |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Lyr1 |         | PgUp |      |      |
*                                 | Space| Bkspc|------|         |------|Delete| Enter|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_CAPS, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SCRL  ,KC_PAUS, KC_NO, QK_BOOT,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,     KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,     KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
           KC_ESC, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,     KC_H   ,KC_J   ,KC_K   ,KC_L   ,MT(MOD_LGUI, KC_SCLN),KC_QUOT,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,     KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,             KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
			   KC_LCTL,KC_LCMD,           KC_RALT,KC_MEH,
                                    LT(1, LCMD(KC_ENT)),           KC_PGUP,
                           KC_SPC,KC_BSPC,KC_END,           KC_PGDN,KC_DEL,KC_ENT
    ),

// LAYER1 is activated by the keypad key. It has WAKE on Escape (left-most key),
// and volume keys on PSCR (mute), SLCK (volume down) and PAUS (volume up),
// as printed on the Kinesis Advantage 2.
[LAYER1] = LAYOUT(

           KC_NO ,  KC_NO  ,KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,   KC_NO  ,KC_NO  ,KC_NO,  KC_NO  ,KC_NO  ,KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
           KC_NO ,  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,   KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
           KC_NO ,  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,   KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
           KC_NO ,  KC_NO  ,KC_NO  ,KC_NO  ,RECT_FS,KC_NO  ,   KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
           KC_NO ,  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,   KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
                   KC_NO  ,KC_NO  ,RECT_LH  ,RECT_RH  ,             RECT_TH  ,RECT_BH  ,KC_NO  ,KC_NO  ,
			   KC_NO  ,KC_NO  ,           KC_NO  ,KC_NO  ,
                                    KC_NO  ,           KC_NO  ,
                           KC_NO  ,KC_NO  ,KC_NO  ,           KC_NO  ,KC_NO    ,KC_NO
    ),
};
