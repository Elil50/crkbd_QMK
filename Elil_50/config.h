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

#define MASTER_LEFT

#define MK_3_SPEED
#define TAPPING_TOGGLE 1
#define MK_W_OFFSET_0 2
#define MK_W_OFFSET_1 15

#if MY_TRACKPOINT_ENABLE
    #define PS2_PIO_USE_PIO1
    #define PS2_CLOCK_PIN B5
    #define PS2_DATA_PIN B4
#endif

#if MY_UNICODE_ENABLE
    #define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_MACOS, UNICODE_MODE_WINCOMPOSE
    #define OS_DETECTION_SINGLE_REPORT
#endif
