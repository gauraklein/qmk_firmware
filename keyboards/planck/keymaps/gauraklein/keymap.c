/* Copyright 2015-2021 Jack Humbert
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

/* Modified from planck default to Finnish SFS 5966 by gitdrik, 2020-2023. */

#include QMK_KEYBOARD_H
#include <stdio.h>

enum planck_layers {
  BASE,
  ARROWS,
  SYMBOLS,
  NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Shift|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | Shift| Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  | GUI  | Alt  |Left2 | Left |BkSpc | Spc  |Right |Rghter|   \  |   -  |   /  |
 * `-----------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,          KC_P,    KC_BSPC,
    KC_TAB, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,   KC_J,   KC_K,    KC_L,          KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z, KC_X,    KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,        KC_SLSH, KC_RSFT ,
    ___, ___, ___, KC_LCTL, KC_SPC, KC_LGUI, KC_ENT, KC_SPC,  LT(SYMBOLS, KC_CAPS), ___, ___, ___
),

/* Left
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  F10 |  F9  |  F8  |  F7  |   {  |   }  |   7  |   8  |   9  |   ^  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RCtrl|  F11 |  F6  |  F5  |  F4  |   (  |   )  |   4  |   5  |   6  |   +  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Shift|  F3  |  F2  |  F1  |   [  |   ]  |   1  |   2  |   3  | Shift| Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | F12  | GUI  | Alt  |Lefter| Left |BkSpc | Spc  |Right |   0  |   ,  |   -  |   /  |
 * `-----------------------------------------------------------------------------------'
 */
[ARROWS] = LAYOUT_planck_grid(
    KC_TAB, KC_1,  KC_2,   KC_3,   KC_4,   KC_5, KC_6, KC_7,    KC_8,   KC_9,    KC_0, KC_BSPC,
    KC_RCTL, ____,  ____,   ____,   ____,   ____, KC_LEFT, KC_DOWN,    KC_UP,   KC_RIGHT,  ____,   _____,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, LALT(KC_LGUI),  LCTL(KC_LGUI),     KC_ENT,   LALT(KC_LCTL), ____, ____, ____, ____, 
   
),

/* Right
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  ◌̄   |  ◌̈	  |  ◌́	  |  ◌̀	  |  ◌̃	  |  ◌̆   | Home |  Up  | End  | Ins  | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RCtrl|  @   |   $  |   °  |   &  |   #  |   %  | Left | Down | Right| Del  | PgDn |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Shift|   ”  |   «  |   »  |  ‚ „ |   ‰  |PlayPs|  <<  |  >>  | Shift| Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   “  | GUI  | Alt  |Lefter|      |BkSpc | Spc  |Right |Rghter| Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
 [SYMBOLS] = LAYOUT_planck_grid(
      KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_LCTL, KC_LALT, _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, KC_GRV, KC_TILD,
      KC_LSFT, _______, _______, KC_VOLD, KC_VOLU, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL, KC_RCBR, KC_PIPE, KC_TILD,
      ____, ____, ____, KC_MPRV,  KC_MNXT,  KC_MPLY, _______, _______, _______, ____, ____, ____,
),

/* Lefter
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  § ½ |   "  |   €  |      |  þ Þ |   ¡  |   !  |   ı  |  œ Œ |  ◌̛ ◌̉ | ◌̋  ◌̊ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  ə Ə |  ß ẞ |  ð Ð |   '  |   <  |   >  |      |   ĸ  |   ◌̵  |  ø Ø |  æ Æ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Shift|  × · | ◌̧  ◌̨ |      |      |  ŋ Ŋ |  µ — |  ’ ‘ | ◌̣  ◌̇ | Shift| Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ʒ Ʒ | GUI  | Alt  |Lefter|      | BkSpc| NbSp |      |Rghter|   |  | – ◌̦  |   ?  |
 * `-----------------------------------------------------------------------------------'
 */
 [NUMPAD] = LAYOUT_planck_grid(
      QK_BOOT, _______, _______, _______, _______, _______, KC_EQL, KC_7, KC_8, KC_9, _______, _______,
      _______, _______, _______, _______, _______, KC_UNDS, KC_MINS, KC_4, KC_5, KC_6, _______, _______,
      _______, _______, _______, _______, _______, _______, KC_PLUS, KC_1, KC_2, KC_3, _______, _______,
       _______,  _______,  _______, _______, _______,  _______, KC_ENT, KC_0, _______,  _______,  _______,  _______, 
),
};
