/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT

#define PS2_PIO_USE_PIO1
#define PS2_CLOCK_PIN B5
#define PS2_DATA_PIN B4

// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER 5
// #define MASTER_RIGHT
// #define EE_HANDS

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

// #ifdef RGBLIGHT_ENABLE
//     // #define RGBLIGHT_EFFECT_BREATHING
//     // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//     // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//     // #define RGBLIGHT_EFFECT_SNAKE
//     // #define RGBLIGHT_EFFECT_KNIGHT
//     // #define RGBLIGHT_EFFECT_CHRISTMAS
//     // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//     // #define RGBLIGHT_EFFECT_RGB_TEST
//     // #define RGBLIGHT_EFFECT_ALTERNATING
//     // #define RGBLIGHT_EFFECT_TWINKLE
//     #define RGBLIGHT_LIMIT_VAL 120
//     #define RGBLIGHT_HUE_STEP 10
//     #define RGBLIGHT_SAT_STEP 17
//     #define RGBLIGHT_VAL_STEP 17
    
//     #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
// #endif

#define MK_3_SPEED
#define TAPPING_TOGGLE 1
//#define MK_MOMENTARY_ACCEL
//#define MK_W_OFFSET_UNMOD 1
#define MK_W_OFFSET_0 2
#define MK_W_OFFSET_1 15
