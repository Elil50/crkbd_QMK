/*
// Copyright 2019 @foostan
// Copyright 2020 Drashna Jaelre <@drashna>
// SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3( //alphabetic
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_QUOTE,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_BSPC,                        KC_H,    KC_J,    KC_UP,   KC_K,    KC_L,  KC_COMMA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC, KC_ENTER,           		  KC_B,  MS_BTN1,  MS_BTN3, MS_BTN2,  KC_N,   KC_M,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            	   	 KC_LGUI, XXXXXXX, KC_LCTL,    KC_LSFT,XXXXXXX,KC_ESC
                                      //`--------------------------'  `--------------------------'

  )
};

