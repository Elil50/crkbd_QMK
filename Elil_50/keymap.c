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

#if MY_TRACKPOINT_ENABLE
    #include "ps2_mouse.h"
    #include "ps2.h"
#endif

#define MY_LESS S(KC_COMM)
#define MY_GREAT S(KC_DOT)
#define LEFT_TOGGLE LT(1, KC_Q)
#define RIGHT_TOGGLE LT(1, KC_NO)
#define ESC_ALT MT(MOD_LALT, KC_ESC)

// #define MY_UNICODE_ENABLE 1  // it's in rules.mk
// #define MY_TRACKPOINT_ENABLE 1  // it's in rules.mk

#define MY_MAX_LAYER 7 
// if you disable the trackpoint, I automatically remove the
// mouse layer (you won't need it): reduce MY_MAX_LAYER by 1.
// It all becomes clear if you take a glance at the end of this file.  



//    %----------------------%
//    | UNICODE OS DETECTION |
//    %----------------------%

#if MY_UNICODE_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
        case OS_WINDOWS:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            break;
        case OS_IOS:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        case OS_UNSURE:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
    }
    
    return true;
}
#endif


//    %--------------%
//    |  TRACKPOINT  |
//    %--------------%

// Sensitivity: Adress: 0xE2 0x81 0x4A, value: 0 - 255 in hex. Default: 0x59
// Speed: Adress: 0xE2 0x81 0x60, value: 0 - 255 in hex. Default: 0x61
// Negative Inertia: Adress: 0xE2 0x81 0x4D, value: 0 - 255 in hex. Default: 0x06
// Toggle Press to select: Adress: 0xE2 0x81 0x2C, value: 0x01
// Threshold Press to select: Adress: 0xE2 0x81 0x5C, value: 0 - 255 in hex. Default: 0x08

#if MY_TRACKPOINT_ENABLE
void ps2_mouse_init_user() {
    PS2_MOUSE_SEND(0xE2, "tpspeed: 0xE2"); //address
    PS2_MOUSE_SEND(0x81, "tpspeed: 0x81"); //address
    PS2_MOUSE_SEND(0x60, "tpspeed: 0x60"); // address
    PS2_MOUSE_SEND(0xFF, "tpspeed: 0xFF"); // value

    PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2"); //address
    PS2_MOUSE_SEND(0x81, "tpsens: 0x81"); //address
    PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A"); // address
    PS2_MOUSE_SEND(0xB4, "tpsens: 0xB4"); // value

    // I tried enabling press to click, but the Z sensitivity is low even when maxed out

    // PS2_MOUSE_SEND(0xE2, "ptson: 0xE2"); //address
    // PS2_MOUSE_SEND(0x47, "ptson: 0x47"); //address
    // PS2_MOUSE_SEND(0x2C, "ptson: 0x2C"); // address
    // PS2_MOUSE_SEND(0x01, "ptson: 0x01"); // value
    // PS2_MOUSE_SEND(0xE2, "ptson_thr: 0xE2"); // address
    // PS2_MOUSE_SEND(0x81, "ptson_thr: 0x81"); //address
    // PS2_MOUSE_SEND(0x5C, "ptson_thr: 0x5C"); // address
    // PS2_MOUSE_SEND(0xFF, "ptson_thr: 0xFF"); // value
    // PS2_MOUSE_SEND(0xE2, "ptson_thr: 0xE2"); // address
    // PS2_MOUSE_SEND(0x81, "ptson_thr: 0x81"); //address
    // PS2_MOUSE_SEND(0x58, "ptson_thr: 0x5C"); // address
    // PS2_MOUSE_SEND(0x00, "ptson_thr: 0xFF"); // value
}
# endif



//    %-------------%
//    |   UNICODE   |
//    %-------------%
#if MY_UNICODE_ENABLE

enum unicode_name {
    // greek letters
    UALPH,
    UBETA,
    UGAMM,
    UDELT,
    UEPSI,
    UZETA,
    UETA,
    UTHET,
    UIOTA,
    UKAPP,
    ULAMB,
    UMU,
    UNU,
    UXI,
    UOMIC,
    UPI,
    URHO,
    USIGM,
    UTAU,
    UUPSI,
    UPHI,
    UCHI,
    UPSI,
    UOMEG,
  
    LALPH,
    LBETA,
    LGAMM,
    LDELT,
    LEPSI,
    LZETA,
    LETA,
    LTHET,
    LIOTA,
    LKAPP,
    LLAMB,
    LMU,
    LNU,
    LXI,
    LOMIC,
    LPI,
    LRHO,
    LSIGM,
    LTAU,
    LUPSI,
    LPHI,
    LCHI,
    LPSI,
    LOMEG,
    FSIGM,
  
    LTEQ,
    GTEQ,
    NOTEQ,
    PLMIN,
    FORALL,
};


const uint32_t unicode_map[] PROGMEM = { 
    // greek letters
    [UALPH] = 0x0391,
    [UBETA] = 0x0392,
    [UGAMM] = 0x0393,
    [UDELT] = 0x0394,
    [UEPSI] = 0x0395,
    [UZETA] = 0x0396,
    [UETA] = 0x0397,
    [UTHET] = 0x0398,
    [UIOTA] = 0x0399,
    [UKAPP] = 0x039A,
    [ULAMB] = 0x039B,
    [UMU] = 0x039C,
    [UNU] = 0x039D,
    [UXI] = 0x039E,
    [UOMIC] = 0x039F,
    [UPI] = 0x03A0,
    [URHO] = 0x03A1,
    [USIGM] = 0x03A3,
    [UTAU] = 0x03A4,
    [UUPSI] = 0x03A5,
    [UPHI] = 0x03A6,
    [UCHI] = 0x03A7,
    [UPSI] = 0x03A8,
    [UOMEG] = 0x03A9,

    [LALPH] = 0x03B1,
    [LBETA] = 0x03B2,
    [LGAMM] = 0x03B3,
    [LDELT] = 0x03B4,
    [LEPSI] = 0x03B5,
    [LZETA] = 0x03B6,
    [LETA] = 0x03B7,
    [LTHET] = 0x03B8,
    [LIOTA] = 0x03B9,
    [LKAPP] = 0x03BA,
    [LLAMB] = 0x03BB,
    [LMU] = 0x03BC,
    [LNU] = 0x03BD,
    [LXI] = 0x03BE,
    [LOMIC] = 0x03BF,
    [LPI] = 0x03C0,
    [LRHO] = 0x03C1,
    [LSIGM] = 0x03C3,
    [LTAU] = 0x03C4,
    [LUPSI] = 0x03C5,
    [LPHI] = 0x03C6,
    [LCHI] = 0x03C7,
    [LPSI] = 0x03C8,
    [LOMEG] = 0x03C9,

    [FSIGM] = 0x03C2,
  
    // other
    [LTEQ] = 0x2264, // less than or equal
    [GTEQ] = 0x2265, // greater than or equal
    [NOTEQ] = 0x2260, // not equal
    [PLMIN] = 0xB1, // plus minus
    [FORALL] = 0x2200, // plus minus
};

#define ALPH UP(LALPH,UALPH)
#define BETA UP(LBETA,UBETA)
#define GAMM UP(LGAMM,UGAMM)
#define DELT UP(LDELT,UDELT)
#define EPSI UP(LEPSI,UEPSI)
#define ZETA UP(LZETA,UZETA)
#define ETA UP(LETA,UETA)
#define THET UP(LTHET,UTHET)
#define IOTA UP(LIOTA,UIOTA)
#define KAPP UP(LKAPP,UKAPP)
#define LAMB UP(LLAMB,ULAMB)
#define MU UP(LMU,UMU)
#define NU UP(LNU,UNU)
#define XI UP(LXI,UXI)
#define OMIC UP(LOMIC,UOMIC)
#define PI UP(LPI,UPI)
#define RHO UP(LRHO,URHO)
#define SIGM UP(LSIGM,USIGM)
#define TAU UP(LTAU,UTAU)
#define UPSIL UP(LUPSI,UUSPI)
#define PHI UP(LPHI,UPHI)
#define CHI UP(LCHI,UCHI)
#define PSI UP(LPSI,UPSI)
#define OMEG UP(LOMEG,UOMEG)

#endif



//    %--------------%
//    |   NEW KEYS   |
//    %--------------%

enum tap_dance_keys { //tap dance enum needs to be separate from new keys enum
    TD_SHIFT_CAPS,
    META_TO6,
};

enum new_keys {
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

#if MY_UNICODE_ENABLE
static bool send_unicode(bool activated, void *context) {
    if (activated) {
        uint32_t code = (uintptr_t)context;  // store UM(x) as integer in context
        register_unicodemap(unicodemap_index(code));
    }
    return false;
}

#define MAKE_OVERRIDE(mods, trig, action, ctx) \
(const key_override_t){ \
    .trigger_mods = mods, \
    .layers = ~0, \
    .suppressed_mods = mods, \
    .options = ko_options_default, \
    .negative_mod_mask = 0, \
    .custom_action = action, \
    .context = (void*)(uintptr_t)(ctx), \
    .trigger = trig, \
    .replacement = KC_NO, \
    .enabled = NULL, \
}

#define MAKE_UNICODE_OVERRIDE(mods, trig, unicode) \
    MAKE_OVERRIDE(mods, trig, send_unicode, (unicode))

const key_override_t my_overrides_1 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, MY_LESS, UM(LTEQ));
const key_override_t my_overrides_2 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SA, MY_LESS, UM(GTEQ));
const key_override_t my_overrides_3 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, KC_EQL, UM(NOTEQ));
const key_override_t my_overrides_4 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, KC_PPLS, UM(PLMIN));
const key_override_t my_overrides_5 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, KC_BSLS, UM(FORALL));
#endif

const key_override_t override_1 = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t override_2 = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t override_3 = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t override_4 = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_DOT);
const key_override_t override_6 = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_TILD);
const key_override_t override_9 = ko_make_basic(MOD_MASK_SHIFT, KC_PAST, KC_CIRC);
const key_override_t override_10 = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_PERC);
const key_override_t override_15 = ko_make_basic(MOD_MASK_ALT, KC_QUOTE, KC_GRV);
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
  #if MY_UNICODE_ENABLE
  &my_overrides_1,
  &my_overrides_2,
  &my_overrides_3,
  &my_overrides_4,
  &my_overrides_5,
  #endif
  NULL
};



//    %-------------%
//    |    COMBO    |
//    %-------------%

const uint16_t PROGMEM combo2[] = {TD(TD_SHIFT_CAPS), KC_COMM, COMBO_END};
const uint16_t PROGMEM combo4[] = {TD(TD_SHIFT_CAPS), KC_EQL, COMBO_END};
const uint16_t PROGMEM combo7[] = {TD(TD_SHIFT_CAPS), KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo8[] = {ESC_ALT, KC_QUOTE, COMBO_END};
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
#if MY_UNICODE_ENABLE
const uint16_t PROGMEM combo36[] = {ESC_ALT, MY_LESS, COMBO_END};
const uint16_t PROGMEM combo37[] = {ESC_ALT, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo38[] = {ESC_ALT, KC_PPLS, COMBO_END};
const uint16_t PROGMEM combo40[] = {ESC_ALT, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo39[] = {TD(TD_SHIFT_CAPS), ESC_ALT, MY_LESS, COMBO_END};
#endif 

combo_t key_combos[] = {
  COMBO(combo2, KC_DOT),
  COMBO(combo4, KC_TILD),
  COMBO(combo7, KC_DQT),
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
  #if MY_UNICODE_ENABLE
  COMBO(combo36, UM(LTEQ)),
  COMBO(combo37, UM(NOTEQ)),
  COMBO(combo38, UM(PLMIN)),
  COMBO(combo40, UM(FORALL)),
  COMBO(combo39, UM(GTEQ)),
  #endif
};



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

#if MY_TRACKPOINT_ENABLE
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
# endif


//    %---------------------%
//    |   KEYBOARD LAYERS   |
//    %---------------------%

#if MY_UNICODE_ENABLE 
    #define GREEK_LAYER TG(3)
    #define ADD_LAYER 4
#else 
    #define GREEK_LAYER XXXXXXX
    #define ADD_LAYER 3
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3( //alphabetic
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_QUOTE,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_SCLN,
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
       KC_0,    KC_1,    KC_2,    KC_3,    KC_4,  KC_QUOTE,                      KC_PWR, KC_PSCR, KC_QUES, KC_EQL, MY_LESS, KC_SCLN,
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
        KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_BSPC,                    ACCEL,  KC_UP, GREEK_LAYER, XXXXXXX,XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F11, KC_F12,  KC_RALT, KC_LALT, KC_SPC,  KC_ENTER,            		   KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, TG(ADD_LAYER+1), TG(ADD_LAYER),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  TD(META_TO6),  LEFT_TOGGLE, KC_LCTL, 	TD(TD_SHIFT_CAPS),  RIGHT_TOGGLE,  ESC_ALT
                                        //`--------------------------'  `--------------------------'
  ),

  #if MY_UNICODE_ENABLE
    [3] = LAYOUT_split_3x6_3( //greek
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,   FSIGM,   EPSI,   RHO,   TAU,  KC_QUOTE  ,                        UPSI,    THET,    IOTA,    OMIC,    PI,    KC_SCLN,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         ALPH,    SIGM,    DELT,    PHI,     GAMM,  KC_BSPC,                        ETA,     KC_UP,     XI,    KAPP,   LAMB,   KC_COMMA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         ZETA,    CHI,     PSI,     OMEG,   KC_SPC,  KC_ENTER,            		  KC_LEFT,  KC_DOWN, KC_RIGHT, BETA,    NU,        MU,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  TD(META_TO6),  LEFT_TOGGLE, KC_LCTL, 	TD(TD_SHIFT_CAPS),  RIGHT_TOGGLE,  ESC_ALT
                                        //`--------------------------'  `--------------------------'
  ),
  #endif



  // ------------------------------ ADD ADDITIONAL LAYERS ONLY AFTER THESE LAYERS, for hyerarchy purposes ------------------------------


  
    [ADD_LAYER] = LAYOUT_split_3x6_3( //vr_chat
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

    [ADD_LAYER+1] = LAYOUT_split_3x6_3( //minecraft
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


   #if MY_TRACKPOINT_ENABLE
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
  #endif



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
