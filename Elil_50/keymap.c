/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "ps2_mouse.h"
#include "ps2.h"

#define MY_LESS S(KC_COMM)
#define MY_GREAT S(KC_DOT)

#define LEFT_TOGGLE LT(1, KC_Q)
#define RIGHT_TOGGLE LT(1, KC_NO)

#define ESC_ALT MT(MOD_LALT, KC_ESC)

#define MY_MAX_LAYER 6

//    %--------------%
//    |  TRACKPOINT  |
//    %--------------%

// Sensitivity: Adress: 0x4A, value: 0 - 255 in hex. Default: 0x59
// Speed: Adress: 0x60, value: 0 - 255 in hex. Default: 0x61
// Negative Inertia: Adress: 0x4D, value: 0 - 255 in hex. Default: 0x06
// ?? Press to select: Adress: 0x2C, value: 0 (disabled) or 1 (enabled) in hex (0x00 or 0xFF)

void ps2_mouse_init_user() {
    PS2_MOUSE_SEND(0xE2, "tpspeed: 0xE2"); //enable writing on the Trackpoint
    PS2_MOUSE_SEND(0x81, "tpspeed: 0x81"); //enable writing on the Trackpoint
    PS2_MOUSE_SEND(0x60, "tpspeed: 0x60"); // address
    PS2_MOUSE_SEND(0xFF, "tpspeed: 0xFF"); // value

    PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2"); //enable writing on the Trackpoint
    PS2_MOUSE_SEND(0x81, "tpsens: 0x81"); //enable writing on the Trackpoint
    PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A"); // address
    PS2_MOUSE_SEND(0xB4, "tpsens: 0xB4"); // value

    // PS2_MOUSE_SEND(0xE2, "ptson: 0xE2"); //enable writing on the Trackpoint
    // PS2_MOUSE_SEND(0x47, "ptson: 0x47"); //enable writing on the Trackpoint
    // PS2_MOUSE_SEND(0x2C, "ptson: 0x2C"); // address
    // PS2_MOUSE_SEND(0x00, "ptson: 0x00"); // value
}

//    %--------------%
//    |   NEW KEYS   |
//    %--------------%

enum{ //tap dance enum needs to be separate from new keys enum
    TD_SHIFT_CAPS,
    META_TO6,
};
enum{
    ACCEL = SAFE_RANGE,
};

// TAP DANCE
tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [META_TO6] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, MY_MAX_LAYER),
};



//    %---------------%
//    |   OVERRIDES   |
//    %---------------%

const key_override_t override_1 = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t override_2 = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t override_3 = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t override_4 = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_DOT);
const key_override_t override_6 = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_TILD);
const key_override_t override_8 = ko_make_basic(MOD_MASK_SHIFT, KC_DQT, KC_QUOT);
const key_override_t override_9 = ko_make_basic(MOD_MASK_SHIFT, KC_PAST, KC_CIRC);
const key_override_t override_10 = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_PERC);
const key_override_t override_15 = ko_make_basic(MOD_MASK_ALT, KC_DQT, KC_GRV);
const key_override_t override_17 = ko_make_basic(MOD_MASK_SHIFT, KC_LT, KC_GT);
const key_override_t override_18 = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PMNS);;
const key_override_t override_20 = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_UNDS); 
const key_override_t override_21 = ko_make_basic(MOD_MASK_SHIFT, KC_ENTER, KC_TAB); 
const key_override_t override_22 = ko_make_basic(MOD_MASK_SHIFT, MY_LESS, MY_GREAT);
const key_override_t override_23 = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t override_24 = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_AT);
const key_override_t override_25 = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t override_26 = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, KC_HASH);


const key_override_t *key_overrides[] = {
  &override_1,
  &override_2,
  &override_3,
  &override_4,
  &override_6,
  &override_8,
  &override_9,
  &override_10,
  &override_15,
  &override_17,
  &override_18,
  &override_20,
  &override_21,
  &override_22,
  &override_23,
  &override_24,
  &override_25,
  &override_26,
  NULL
};



//    %-------------%
//    |    COMBO    |
//    %-------------%

const uint16_t PROGMEM combo2[] = {TD(TD_SHIFT_CAPS), KC_COMM, COMBO_END};
const uint16_t PROGMEM combo4[] = {TD(TD_SHIFT_CAPS), KC_EQL, COMBO_END};
const uint16_t PROGMEM combo7[] = {TD(TD_SHIFT_CAPS), KC_DQT, COMBO_END};
const uint16_t PROGMEM combo8[] = {KC_LALT, KC_DQT, COMBO_END};
const uint16_t PROGMEM combo9[] = {TD(TD_SHIFT_CAPS), KC_LT, COMBO_END};
const uint16_t PROGMEM combo10[] = {TD(TD_SHIFT_CAPS), KC_PAST, COMBO_END};
const uint16_t PROGMEM combo11[] = {TD(TD_SHIFT_CAPS), KC_VOLU, COMBO_END};
const uint16_t PROGMEM combo15[] = {TD(TD_SHIFT_CAPS), KC_SLASH, COMBO_END};
const uint16_t PROGMEM combo16[] = {TD(TD_SHIFT_CAPS), KC_LPRN, COMBO_END};
const uint16_t PROGMEM combo17[] = {TD(TD_SHIFT_CAPS), KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo18[] = {TD(TD_SHIFT_CAPS), KC_LCBR, COMBO_END};
const uint16_t PROGMEM combo24[] = {KC_LCTL, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo25[] = {LEFT_TOGGLE, RIGHT_TOGGLE, COMBO_END};
const uint16_t PROGMEM combo29[] = {TD(TD_SHIFT_CAPS), KC_SPC, COMBO_END};
const uint16_t PROGMEM combo30[] = {TD(TD_SHIFT_CAPS), KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo31[] = {TD(TD_SHIFT_CAPS), MY_LESS, COMBO_END};
const uint16_t PROGMEM combo32[] = {TD(TD_SHIFT_CAPS), KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo33[] = {TD(TD_SHIFT_CAPS), KC_AMPR, COMBO_END};
const uint16_t PROGMEM combo34[] = {TD(TD_SHIFT_CAPS), KC_QUES, COMBO_END};
const uint16_t PROGMEM combo35[] = {TD(TD_SHIFT_CAPS), KC_DLR, COMBO_END};

combo_t key_combos[] = {
  COMBO(combo2, KC_DOT),
  COMBO(combo4, KC_TILD),
  COMBO(combo7, KC_QUOT),
  COMBO(combo8, KC_GRV),
  COMBO(combo9, KC_GT),
  COMBO(combo10, KC_CIRC),
  COMBO(combo11, KC_VOLD),
  COMBO(combo15, KC_PERC),
  COMBO(combo16, KC_RPRN),
  COMBO(combo17, KC_RBRC),
  COMBO(combo18, KC_RCBR),
  COMBO(combo24, C(KC_LALT)),
  COMBO(combo25, TO(2)),
  COMBO(combo29, KC_UNDS),
  COMBO(combo30, KC_TAB),
  COMBO(combo31, MY_GREAT),
  COMBO(combo32, KC_DEL),
  COMBO(combo33, KC_AT),
  COMBO(combo34, KC_EXLM),
  COMBO(combo35, KC_HASH),

};


//saving general syntax for pressing and holding key
/*
if (record->event.pressed) {
        if (record->tap.count) {
            //default_layer_set(1 << 0);
            layer_off(1);
        } else {
            //register_mods(MOD_BIT(KC_LSFT));
            layer_off(1);
        }
    } else {
        if (!record->tap.count) {
            //unregister_mods(MOD_BIT(KC_LSFT));
            layer_on(1);
        }
    }
    return false;
    break;
*/
/*
if (record->tap.count && record->event.pressed) {
	//default_layer_set(1 << 1);
	layer_on(1);
	return false;
}
break;
*/



//    %---------------------%
//    |  NEW KEY BEHAVIOUR  |
//    %---------------------%

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case RIGHT_TOGGLE:
        
            if (record->event.pressed) {
                for(uint16_t i=1; i<=MY_MAX_LAYER; i++){
                    layer_off(i);
                }
            }
            else {
                if (!record->tap.count) {
                    layer_on(1);
                }
            }
            return false;
            break;
            
        ///// ---------------------

        case LEFT_TOGGLE:
            
            if (record->event.pressed) {
                layer_on(1);
                for(uint16_t i=2; i<=MY_MAX_LAYER; i++){
                    layer_off(i);
                }
            }
            else {
                if (!record->tap.count) {
                    layer_off(1);
                }
            }
            return false;
            break;

        ///// ---------------------
            
        case ACCEL: // toggle between different cursor and wheel speeds

            if (record->event.pressed) {
                static bool accel = true;
                if (accel) {
                    mousekey_on(MS_ACL0);
                } else {
                    mousekey_on(MS_ACL1);
                }
                accel = !accel;
            }
            break;
    }
    return true;
}


//    %-------------------------%
//    |  AUTOMATIC MOUSE LAYER  |
//    %-------------------------%

 
 static uint32_t turn_off(uint32_t trigger_time, void *arg) {
     const uintptr_t layer = (uintptr_t)arg;
     layer_off(layer);
     return 0;
}

#define MOUSE_BUTTONS_LAYER MY_MAX_LAYER-1
// QMK has issue with mouse keys when the cursor is not moving,
// so we will use them only while moving the mouse with high sensitivity.
#define TURN_LAYER_OFF_TIMEOUT 300 //milliseconds
// ps2_mouse_moved_user is called only when the keyboard detects mouse movements.  
void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
    layer_on(MOUSE_BUTTONS_LAYER);

    static deferred_token token = INVALID_DEFERRED_TOKEN;
    cancel_deferred_exec(token); // cancel previous schedule

    // schedule layer turn-off, passing layer number as argument not to hardcode it on the previous function
    token = defer_exec(TURN_LAYER_OFF_TIMEOUT, turn_off, (void *)MOUSE_BUTTONS_LAYER);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //alphabetic
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_DQT ,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_BSPC,                        KC_H,    KC_UP,    KC_J,   KC_K,   KC_L,  KC_COMMA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,   KC_V,    KC_SPC,  KC_ENTER,           		KC_LEFT,  KC_DOWN, KC_RIGHT,  KC_B,   KC_N,   KC_M,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            	TD(META_TO6),  LEFT_TOGGLE, KC_LCTL, 	TD(TD_SHIFT_CAPS),  RIGHT_TOGGLE,  ESC_ALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3( //numeric
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_0,    KC_1,    KC_2,    KC_3,    KC_4,   KC_DQT,                      KC_PWR, KC_PSCR, KC_QUES, KC_EQL, MY_LESS, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_BSPC,                      ACCEL,  KC_UP,   KC_PAST, KC_PPLS, KC_SLASH, KC_COMMA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_DLR,  KC_BSLS, KC_AMPR, KC_LALT,  KC_SPC,  KC_ENTER,                 	KC_LEFT, KC_DOWN, KC_RIGHT, KC_LPRN, KC_LBRC, KC_LCBR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            	TD(META_TO6),  LEFT_TOGGLE, KC_LCTL, 	TD(TD_SHIFT_CAPS),  RIGHT_TOGGLE,  ESC_ALT
                                      //`--------------------------'  `--------------------------'
  ),

     [2] = LAYOUT_split_3x6_3( //stuff
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_TAB  ,                     UG_TOGG,  KC_PSCR, KC_MUTE, KC_VOLU, KC_MPLY,  EE_CLR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_BSPC,                     ACCEL,  KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F11, KC_F12,  KC_RALT, KC_LALT, KC_SPC,  KC_ENTER,            		 KC_LEFT, KC_DOWN, KC_RIGHT, TG(5), TG(4), TG(3),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  TD(META_TO6),  LEFT_TOGGLE, KC_LCTL, 	TD(TD_SHIFT_CAPS),  RIGHT_TOGGLE,  ESC_ALT
                                        //`--------------------------'  `--------------------------'
  ),



  // ------------------------------ ADD ADDITIONAL LAYERS ONLY AFTER THESE LAYERS, for hyerarchy purposes ------------------------------


  
     [3] = LAYOUT_split_3x6_3( //vr_chat
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_F12,  XXXXXXX, KC_E,   KC_W,   KC_R,   KC_C ,                    S(KC_F1), S(KC_F2), S(KC_F3), S(KC_F4), S(KC_F5), S(KC_F6),
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_V, TD(TD_SHIFT_CAPS), KC_A,  KC_S,     KC_D,   KC_Z,                      S(KC_F7), S(KC_F8), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_H,     KC_N,                      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TD(META_TO6), LEFT_TOGGLE,  KC_SPC,     XXXXXXX, RIGHT_TOGGLE, ESC_ALT
                                          //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3( //minecraft
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_M, KC_B, KC_E,  KC_W,   KC_F5,   KC_F1 ,                          KC_1,     KC_2,    KC_3,   KC_4,     KC_5,    KC_6,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_Q,   KC_LCTL,   KC_A,    KC_S,   KC_D,   KC_TILD,                      KC_7,     KC_8,   KC_9,    XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_T,    KC_C,   XXXXXXX, XXXXXXX, KC_V,   KC_EQL,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    TD(META_TO6), LEFT_TOGGLE,  TD(TD_SHIFT_CAPS),     KC_SPC, RIGHT_TOGGLE, ESC_ALT
                                          //`--------------------------'  `--------------------------'
  ),



  // ------------------------------ ADD ADDITIONAL LAYERS ONLY BEFORE THESE LAYERS, for hyerarchy purposes ------------------------------



  [MY_MAX_LAYER-1] = LAYOUT_split_3x6_3( // mouse transparent layer
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, MS_BTN1, MS_BTN3, MS_BTN2, KC_TRNS, KC_TRNS,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
  ),



  [MY_MAX_LAYER] = LAYOUT_split_3x6_3( // wheel transparent layer
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       ACCEL,  MS_WHLU, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       MS_WHLL, MS_WHLD, MS_WHLR, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
  )//,


};
