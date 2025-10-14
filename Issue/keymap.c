/*
// Copyright 2019 @foostan
// Copyright 2020 Drashna Jaelre <@drashna>
// SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

#include "ps2_mouse.h"
#include "ps2.h"


//    %--------------%
//    |  TRACKPOINT  |
//    %--------------%

// Sensitivity: Adress: 0xE2 0x81 0x4A, value: 0 - 255 in hex. Default: 0x59
// Speed: Adress: 0xE2 0x81 0x60, value: 0 - 255 in hex. Default: 0x61

void ps2_mouse_init_user() {
    PS2_MOUSE_SEND(0xE2, "tpspeed: 0xE2"); //address
    PS2_MOUSE_SEND(0x81, "tpspeed: 0x81"); //address
    PS2_MOUSE_SEND(0x60, "tpspeed: 0x60"); // address
    PS2_MOUSE_SEND(0xFF, "tpspeed: 0xFF"); // value

    PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2"); //address
    PS2_MOUSE_SEND(0x81, "tpsens: 0x81"); //address
    PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A"); // address
    PS2_MOUSE_SEND(0xB4, "tpsens: 0xFF"); // value
}


//    %---------------------%
//    |   KEYBOARD LAYERS   |
//    %---------------------%


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

