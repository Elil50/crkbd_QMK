/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2025 Elil50 <@Elil50>
SPDX-License-Identifier: GPL-2.0-or-later
*/


#pragma once

#define MASTER_LEFT

#define MK_3_SPEED
#define TAPPING_TOGGLE 1
#define MK_W_OFFSET_1 2
#define MK_W_OFFSET_0 15
#define PS2_MOUSE_X_MULTIPLIER 2
#define PS2_MOUSE_Y_MULTIPLIER 2

#if MY_TRACKPOINT_ENABLE
    #define PS2_PIO_USE_PIO1
    #define PS2_CLOCK_PIN B5
    #define PS2_DATA_PIN B4
#endif

#if MY_UNICODE_ENABLE
    #define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_MACOS, UNICODE_MODE_WINCOMPOSE
    #define OS_DETECTION_SINGLE_REPORT
#endif
