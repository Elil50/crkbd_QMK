/*
// Copyright 2019 @foostan
// Copyright 2020 Drashna Jaelre <@drashna>
// Copyright 2025 Elil50 <@Elil50>
// SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

#if MY_TRACKPOINT_ENABLE
    #include "drivers/sensors/ps2_mouse.h"
    #include "ps2.h"
#endif

#define MY_LESS S(KC_COMM)
#define MY_GREAT S(KC_DOT)
#define LEFT_TOGGLE LT(1, KC_Q)
#define RIGHT_TOGGLE LT(1, KC_NO)
#define TWO_TOGGLE LT(1, KC_W)
#define ESC_ALT MT(MOD_LALT, KC_ESC)

// #define MY_UNICODE_ENABLE 1  // it's in rules.mk
// #define MY_TRACKPOINT_ENABLE 1  // it's in rules.mk



//    %--------------------------%
//    | AUTOMATIC LAYER ORDERING |
//    %--------------------------%

#if MY_UNICODE_ENABLE
    #define ADD_GREEK 1
    #define TG_GREEK_LAYER TG(3)
#else
    #define ADD_GREEK 0
    #define TG_GREEK_LAYER XXXXXXX
#endif

#if MY_TRACKPOINT_ENABLE
    #define ADD_MOUSE 1
#else
    #define ADD_MOUSE 0
#endif

#define BASE_LAYERS 2 // alphabetical + numerical + stuff layers
#define GREEK_LAYER (BASE_LAYERS+ADD_GREEK) // only if unicode is enabled
#define MOUSE_LAYER (GREEK_LAYER+ADD_MOUSE) // only if trackpoint is enabled
#define SCROLL_LAYER (MOUSE_LAYER+1)
#define ADD_LAYER (SCROLL_LAYER+1) // These are the user layers



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
            set_unicode_input_mode(UNICODE_MODE_MACOS);
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
void pointing_device_init_user() {
    PS2_MOUSE_SEND(0xE2, "tpspeed: 0xE2"); //address
    PS2_MOUSE_SEND(0x81, "tpspeed: 0x81"); //address
    PS2_MOUSE_SEND(0x60, "tpspeed: 0x60"); // address
    PS2_MOUSE_SEND(0xFF, "tpspeed: 0xFF"); // value

    PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2"); //address
    PS2_MOUSE_SEND(0x81, "tpsens: 0x81"); //address
    PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A"); // address
    PS2_MOUSE_SEND(0xB4, "tpsens: 0xFF"); // value

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
    
    set_auto_mouse_layer(MOUSE_LAYER);
    set_auto_mouse_enable(true);
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
    EUR,
    LEFTARR,
    RIGHTARR,
    LEFTRIGHTARR,
    INTEGR,
    NABLA,
    ELEMOF,
    EXIST,
    INFTY,

    SUB_0,
    SUB_1,
    SUB_2,
    SUB_3,
    SUB_4,
    SUB_5,
    SUB_6,
    SUB_7,
    SUB_8,
    SUB_9,

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
    [EUR] = 0x20AC,
    [LEFTARR] = 0x2190,
    [RIGHTARR] = 0x2192,
    [LEFTRIGHTARR] = 0x2194,
    [INTEGR] = 0x222B,
    [NABLA] = 0x2207,
    [ELEMOF] = 0x2208,
    [EXIST] = 0x2203,
    [INFTY] = 0x221E,

    // subscript
    [SUB_0] = 0x2080,
    [SUB_1] = 0x2081,
    [SUB_2] = 0x2082,
    [SUB_3] = 0x2083,
    [SUB_4] = 0x2084,
    [SUB_5] = 0x2085,
    [SUB_6] = 0x2086,
    [SUB_7] = 0x2087,
    [SUB_8] = 0x2088,
    [SUB_9] = 0x2089,

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
    [META_TO6] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, SCROLL_LAYER),
};


#if MY_UNICODE_ENABLE
    #define MY_INTEGR UM(INTEGR)
    #define MY_RIGHTARR UM(RIGHTARR)
    #define MY_EXIST UM(EXIST)
#else
    #define MY_INTEGR XXXXXXX
    #define MY_RIGHTARR XXXXXXX
    #define MY_EXIST XXXXXXX
#endif


//    %---------------%
//    |   OVERRIDES   |
//    %---------------%

#if MY_UNICODE_ENABLE
static bool send_unicode(bool activated, void *context) {
    if (activated) {
    	uint8_t saved_mods = get_mods();
    	unregister_mods(saved_mods); // temporarily clear user mods: we don't suppress them in MAKE_OVERRIDE

        uint32_t code = (uintptr_t)context;  // store UM(x) as integer in context
        register_unicodemap(unicodemap_index(code));

    	set_mods(saved_mods); // restore mods
    }
    return false;
}

#define MAKE_OVERRIDE(mods, trig, action, ctx, no_mod) \
(const key_override_t){ \
    .trigger_mods = mods, \
    .layers = ~0, \
    .options = ko_options_default, \
    .negative_mod_mask = (no_mod), \
    .custom_action = action, \
    .context = (void*)(uintptr_t)(ctx), \
    .trigger = trig, \
    .replacement = KC_NO, \
    .enabled = NULL, \
}

#define MAKE_UNICODE_OVERRIDE(mods, trig, unicode, no_mod) \
    MAKE_OVERRIDE(mods, trig, send_unicode, (unicode), (no_mod))

const key_override_t my_overrides_1 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, MY_LESS, UM(LTEQ), MOD_MASK_CTRL);
const key_override_t my_overrides_2 = MAKE_UNICODE_OVERRIDE(MOD_MASK_CA, MY_LESS, UM(GTEQ), 0);
const key_override_t my_overrides_3 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, KC_EQL, UM(NOTEQ), 0);
const key_override_t my_overrides_4 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, KC_PPLS, UM(PLMIN), 0);
const key_override_t my_overrides_5 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, MY_EXIST, UM(FORALL), 0);
const key_override_t my_overrides_16 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_DLR, UM(EUR), 0);

const key_override_t my_overrides_6 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_0, UM(SUB_0), 0);
const key_override_t my_overrides_7 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_1, UM(SUB_1), 0);
const key_override_t my_overrides_8 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_2, UM(SUB_2), 0);
const key_override_t my_overrides_9 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_3, UM(SUB_3), 0);
const key_override_t my_overrides_10 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_4, UM(SUB_4), 0);
const key_override_t my_overrides_11 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_5, UM(SUB_5), 0);
const key_override_t my_overrides_12 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_6, UM(SUB_6), 0);
const key_override_t my_overrides_13 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_7, UM(SUB_7), 0);
const key_override_t my_overrides_14 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_8, UM(SUB_8), 0);
const key_override_t my_overrides_15 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, KC_9, UM(SUB_9), 0);
const key_override_t my_overrides_30 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, MY_RIGHTARR, UM(LEFTARR), 0);
const key_override_t my_overrides_31 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, MY_RIGHTARR, UM(LEFTRIGHTARR), 0);
const key_override_t my_overrides_32 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, MY_EXIST, UM(ELEMOF), 0);
const key_override_t my_overrides_33 = MAKE_UNICODE_OVERRIDE(MOD_MASK_SHIFT, MY_INTEGR, UM(NABLA), 0);
const key_override_t my_overrides_34 = MAKE_UNICODE_OVERRIDE(MOD_MASK_ALT, MY_INTEGR, UM(INFTY), 0);
#endif

const key_override_t override_1 = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t override_2 = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t override_3 = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t override_4 = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_DOT);
const key_override_t override_6 = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_TILD);
const key_override_t override_9 = ko_make_basic(MOD_MASK_ALT, KC_PAST, KC_CIRC);
const key_override_t override_10 = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_PERC);
const key_override_t override_15 = ko_make_basic(MOD_MASK_ALT, KC_QUOTE, KC_GRV);
const key_override_t override_17 = ko_make_basic(MOD_MASK_SHIFT, KC_LT, KC_GT);
const key_override_t override_18 = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PMNS);;
const key_override_t override_20 = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_UNDS);
const key_override_t override_21 = ko_make_basic(MOD_MASK_SHIFT, KC_ENTER, KC_TAB);
const key_override_t override_22 = ko_make_basic(MOD_MASK_SHIFT, MY_LESS, MY_GREAT);
const key_override_t override_23 = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t override_24 = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_AT);
const key_override_t override_25 = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t override_27 = ko_make_basic(MOD_MASK_SHIFT, KC_PAST, KC_SLASH);
const key_override_t override_28 = ko_make_basic(MOD_MASK_CTRL, KC_VOLU, KC_VOLD);
const key_override_t override_29 = ko_make_basic(MOD_MASK_CTRL, KC_BRIU, KC_BRID);

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
  &override_27,
  &override_28,
  &override_29,
  #if MY_UNICODE_ENABLE
  &my_overrides_1,
  &my_overrides_2,
  &my_overrides_3,
  &my_overrides_4,
  &my_overrides_5,
  &my_overrides_6,
  &my_overrides_7,
  &my_overrides_8,
  &my_overrides_9,
  &my_overrides_10,
  &my_overrides_11,
  &my_overrides_12,
  &my_overrides_13,
  &my_overrides_14,
  &my_overrides_15,
  &my_overrides_16,
  &my_overrides_30,
  &my_overrides_31,
  &my_overrides_32,
  &my_overrides_33,
  &my_overrides_34,
  #endif
  NULL
};



//    %-------------%
//    |    COMBO    |
//    %-------------%

const uint16_t PROGMEM combo53[] = {TD(TD_SHIFT_CAPS), KC_A, COMBO_END};
const uint16_t PROGMEM combo54[] = {TD(TD_SHIFT_CAPS), KC_B, COMBO_END};
const uint16_t PROGMEM combo55[] = {TD(TD_SHIFT_CAPS), KC_C, COMBO_END};
const uint16_t PROGMEM combo56[] = {TD(TD_SHIFT_CAPS), KC_D, COMBO_END};
const uint16_t PROGMEM combo57[] = {TD(TD_SHIFT_CAPS), KC_E, COMBO_END};
const uint16_t PROGMEM combo58[] = {TD(TD_SHIFT_CAPS), KC_F, COMBO_END};
const uint16_t PROGMEM combo59[] = {TD(TD_SHIFT_CAPS), KC_G, COMBO_END};
const uint16_t PROGMEM combo60[] = {TD(TD_SHIFT_CAPS), KC_H, COMBO_END};
const uint16_t PROGMEM combo61[] = {TD(TD_SHIFT_CAPS), KC_I, COMBO_END};
const uint16_t PROGMEM combo62[] = {TD(TD_SHIFT_CAPS), KC_J, COMBO_END};
const uint16_t PROGMEM combo63[] = {TD(TD_SHIFT_CAPS), KC_K, COMBO_END};
const uint16_t PROGMEM combo64[] = {TD(TD_SHIFT_CAPS), KC_L, COMBO_END};
const uint16_t PROGMEM combo65[] = {TD(TD_SHIFT_CAPS), KC_M, COMBO_END};
const uint16_t PROGMEM combo66[] = {TD(TD_SHIFT_CAPS), KC_N, COMBO_END};
const uint16_t PROGMEM combo67[] = {TD(TD_SHIFT_CAPS), KC_O, COMBO_END};
const uint16_t PROGMEM combo68[] = {TD(TD_SHIFT_CAPS), KC_P, COMBO_END};
const uint16_t PROGMEM combo69[] = {TD(TD_SHIFT_CAPS), KC_Q, COMBO_END};
const uint16_t PROGMEM combo70[] = {TD(TD_SHIFT_CAPS), KC_R, COMBO_END};
const uint16_t PROGMEM combo71[] = {TD(TD_SHIFT_CAPS), KC_S, COMBO_END};
const uint16_t PROGMEM combo72[] = {TD(TD_SHIFT_CAPS), KC_T, COMBO_END};
const uint16_t PROGMEM combo73[] = {TD(TD_SHIFT_CAPS), KC_U, COMBO_END};
const uint16_t PROGMEM combo74[] = {TD(TD_SHIFT_CAPS), KC_V, COMBO_END};
const uint16_t PROGMEM combo75[] = {TD(TD_SHIFT_CAPS), KC_W, COMBO_END};
const uint16_t PROGMEM combo76[] = {TD(TD_SHIFT_CAPS), KC_X, COMBO_END};
const uint16_t PROGMEM combo77[] = {TD(TD_SHIFT_CAPS), KC_Y, COMBO_END};
const uint16_t PROGMEM combo78[] = {TD(TD_SHIFT_CAPS), KC_Z, COMBO_END};

const uint16_t PROGMEM combo053[] = {LEFT_TOGGLE, KC_A, COMBO_END};
const uint16_t PROGMEM combo054[] = {LEFT_TOGGLE, KC_B, COMBO_END};
const uint16_t PROGMEM combo055[] = {LEFT_TOGGLE, KC_C, COMBO_END};
const uint16_t PROGMEM combo056[] = {LEFT_TOGGLE, KC_D, COMBO_END};
const uint16_t PROGMEM combo057[] = {LEFT_TOGGLE, KC_E, COMBO_END};
const uint16_t PROGMEM combo058[] = {LEFT_TOGGLE, KC_F, COMBO_END};
const uint16_t PROGMEM combo059[] = {LEFT_TOGGLE, KC_G, COMBO_END};
const uint16_t PROGMEM combo060[] = {LEFT_TOGGLE, KC_H, COMBO_END};
const uint16_t PROGMEM combo063[] = {LEFT_TOGGLE, KC_K, COMBO_END};
const uint16_t PROGMEM combo064[] = {LEFT_TOGGLE, KC_L, COMBO_END};
const uint16_t PROGMEM combo065[] = {LEFT_TOGGLE, KC_M, COMBO_END};
const uint16_t PROGMEM combo066[] = {LEFT_TOGGLE, KC_N, COMBO_END};
const uint16_t PROGMEM combo067[] = {LEFT_TOGGLE, KC_O, COMBO_END};
const uint16_t PROGMEM combo068[] = {LEFT_TOGGLE, KC_P, COMBO_END};
const uint16_t PROGMEM combo069[] = {LEFT_TOGGLE, KC_Q, COMBO_END};
const uint16_t PROGMEM combo070[] = {LEFT_TOGGLE, KC_R, COMBO_END};
const uint16_t PROGMEM combo071[] = {LEFT_TOGGLE, KC_S, COMBO_END};
const uint16_t PROGMEM combo072[] = {LEFT_TOGGLE, KC_T, COMBO_END};
const uint16_t PROGMEM combo075[] = {LEFT_TOGGLE, KC_W, COMBO_END};
const uint16_t PROGMEM combo076[] = {LEFT_TOGGLE, KC_X, COMBO_END};
const uint16_t PROGMEM combo077[] = {LEFT_TOGGLE, KC_Y, COMBO_END};
const uint16_t PROGMEM combo078[] = {LEFT_TOGGLE, KC_Z, COMBO_END};

const uint16_t PROGMEM combo010[] = {LEFT_TOGGLE, ESC_ALT, KC_L, COMBO_END};

const uint16_t PROGMEM combo0054[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_B, COMBO_END};
const uint16_t PROGMEM combo0055[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_C, COMBO_END};
const uint16_t PROGMEM combo0060[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_H, COMBO_END};
const uint16_t PROGMEM combo0063[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_K, COMBO_END};
const uint16_t PROGMEM combo0064[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_L, COMBO_END};
const uint16_t PROGMEM combo0065[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_M, COMBO_END};
const uint16_t PROGMEM combo0066[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_N, COMBO_END};
const uint16_t PROGMEM combo0067[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_O, COMBO_END};
const uint16_t PROGMEM combo0068[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_P, COMBO_END};
const uint16_t PROGMEM combo0076[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_X, COMBO_END};
const uint16_t PROGMEM combo0077[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_Y, COMBO_END};
const uint16_t PROGMEM combo0078[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_Z, COMBO_END};

const uint16_t PROGMEM combo079[] = {RIGHT_TOGGLE, KC_0, COMBO_END};
const uint16_t PROGMEM combo080[] = {RIGHT_TOGGLE, KC_1, COMBO_END};
const uint16_t PROGMEM combo081[] = {RIGHT_TOGGLE, KC_2, COMBO_END};
const uint16_t PROGMEM combo082[] = {RIGHT_TOGGLE, KC_3, COMBO_END};
const uint16_t PROGMEM combo083[] = {RIGHT_TOGGLE, KC_4, COMBO_END};
const uint16_t PROGMEM combo084[] = {RIGHT_TOGGLE, KC_5, COMBO_END};
const uint16_t PROGMEM combo085[] = {RIGHT_TOGGLE, KC_6, COMBO_END};
const uint16_t PROGMEM combo086[] = {RIGHT_TOGGLE, KC_7, COMBO_END};
const uint16_t PROGMEM combo087[] = {RIGHT_TOGGLE, KC_8, COMBO_END};
const uint16_t PROGMEM combo088[] = {RIGHT_TOGGLE, KC_9, COMBO_END};
const uint16_t PROGMEM combo089[] = {RIGHT_TOGGLE, KC_DLR , COMBO_END};
const uint16_t PROGMEM combo090[] = {RIGHT_TOGGLE, KC_HASH, COMBO_END};
const uint16_t PROGMEM combo091[] = {RIGHT_TOGGLE, KC_AMPR, COMBO_END};
const uint16_t PROGMEM combo093[] = {RIGHT_TOGGLE, KC_QUES, COMBO_END};
const uint16_t PROGMEM combo096[] = {RIGHT_TOGGLE, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo097[] = {RIGHT_TOGGLE, MY_LESS, COMBO_END};
const uint16_t PROGMEM combo098[] = {RIGHT_TOGGLE, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo099[] = {RIGHT_TOGGLE, ACCEL, COMBO_END};
const uint16_t PROGMEM combo100[] = {RIGHT_TOGGLE, KC_PPLS, COMBO_END};
const uint16_t PROGMEM combo101[] = {RIGHT_TOGGLE, KC_PAST, COMBO_END};
const uint16_t PROGMEM combo102[] = {RIGHT_TOGGLE, KC_LPRN, COMBO_END};
const uint16_t PROGMEM combo103[] = {RIGHT_TOGGLE, KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo104[] = {RIGHT_TOGGLE, KC_LCBR, COMBO_END};

const uint16_t PROGMEM combo153[] = {KC_LCTL, KC_A, COMBO_END};
const uint16_t PROGMEM combo154[] = {KC_LCTL, KC_B, COMBO_END};
const uint16_t PROGMEM combo155[] = {KC_LCTL, KC_C, COMBO_END};
const uint16_t PROGMEM combo156[] = {KC_LCTL, KC_D, COMBO_END};
const uint16_t PROGMEM combo157[] = {KC_LCTL, KC_E, COMBO_END};
const uint16_t PROGMEM combo158[] = {KC_LCTL, KC_F, COMBO_END};
const uint16_t PROGMEM combo159[] = {KC_LCTL, KC_G, COMBO_END};
const uint16_t PROGMEM combo160[] = {KC_LCTL, KC_H, COMBO_END};
const uint16_t PROGMEM combo161[] = {KC_LCTL, KC_I, COMBO_END};
const uint16_t PROGMEM combo162[] = {KC_LCTL, KC_J, COMBO_END};
const uint16_t PROGMEM combo163[] = {KC_LCTL, KC_K, COMBO_END};
const uint16_t PROGMEM combo164[] = {KC_LCTL, KC_L, COMBO_END};
const uint16_t PROGMEM combo165[] = {KC_LCTL, KC_M, COMBO_END};
const uint16_t PROGMEM combo166[] = {KC_LCTL, KC_N, COMBO_END};
const uint16_t PROGMEM combo167[] = {KC_LCTL, KC_O, COMBO_END};
const uint16_t PROGMEM combo168[] = {KC_LCTL, KC_P, COMBO_END};
const uint16_t PROGMEM combo169[] = {KC_LCTL, KC_Q, COMBO_END};
const uint16_t PROGMEM combo170[] = {KC_LCTL, KC_R, COMBO_END};
const uint16_t PROGMEM combo171[] = {KC_LCTL, KC_S, COMBO_END};
const uint16_t PROGMEM combo172[] = {KC_LCTL, KC_T, COMBO_END};
const uint16_t PROGMEM combo173[] = {KC_LCTL, KC_U, COMBO_END};
const uint16_t PROGMEM combo174[] = {KC_LCTL, KC_V, COMBO_END};
const uint16_t PROGMEM combo175[] = {KC_LCTL, KC_W, COMBO_END};
const uint16_t PROGMEM combo176[] = {KC_LCTL, KC_X, COMBO_END};
const uint16_t PROGMEM combo177[] = {KC_LCTL, KC_Y, COMBO_END};
const uint16_t PROGMEM combo178[] = {KC_LCTL, KC_Z, COMBO_END};

const uint16_t PROGMEM combo2[] = {TD(TD_SHIFT_CAPS), KC_COMM, COMBO_END};
const uint16_t PROGMEM combo4[] = {TD(TD_SHIFT_CAPS), KC_EQL, COMBO_END};
const uint16_t PROGMEM combo7[] = {TD(TD_SHIFT_CAPS), KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo8[] = {ESC_ALT, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo9[] = {TD(TD_SHIFT_CAPS), KC_LT, COMBO_END};
const uint16_t PROGMEM combo10[] = {ESC_ALT, KC_PAST, COMBO_END};
const uint16_t PROGMEM combo15[] = {TD(TD_SHIFT_CAPS), KC_HASH, COMBO_END};
const uint16_t PROGMEM combo16[] = {TD(TD_SHIFT_CAPS), KC_LPRN, COMBO_END};
const uint16_t PROGMEM combo17[] = {TD(TD_SHIFT_CAPS), KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo18[] = {TD(TD_SHIFT_CAPS), KC_LCBR, COMBO_END};
const uint16_t PROGMEM combo25[] = {LEFT_TOGGLE, RIGHT_TOGGLE, COMBO_END};
const uint16_t PROGMEM combo29[] = {TD(TD_SHIFT_CAPS), KC_SPC, COMBO_END};
const uint16_t PROGMEM combo30[] = {TD(TD_SHIFT_CAPS), KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo31[] = {TD(TD_SHIFT_CAPS), MY_LESS, COMBO_END};
const uint16_t PROGMEM combo32[] = {TD(TD_SHIFT_CAPS), KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo33[] = {TD(TD_SHIFT_CAPS), KC_AMPR, COMBO_END};
const uint16_t PROGMEM combo34[] = {TD(TD_SHIFT_CAPS), KC_QUES, COMBO_END};
const uint16_t PROGMEM combo41[] = {TD(TD_SHIFT_CAPS), KC_PAST, COMBO_END};
const uint16_t PROGMEM combo0[] = {TD(TD_SHIFT_CAPS), KC_PPLS, COMBO_END};
const uint16_t PROGMEM combo01[] = {TD(TD_SHIFT_CAPS), KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo02[] = {TD(TD_SHIFT_CAPS), KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo03[] = {TD(TD_SHIFT_CAPS), KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo000[] = {TD(TD_SHIFT_CAPS), KC_LCTL, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo001[] = {TD(TD_SHIFT_CAPS), KC_LCTL, KC_LEFT, COMBO_END};

#if MY_UNICODE_ENABLE
const uint16_t PROGMEM combo36[] = {ESC_ALT, MY_LESS, COMBO_END};
const uint16_t PROGMEM combo37[] = {ESC_ALT, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo38[] = {ESC_ALT, KC_PPLS, COMBO_END};
const uint16_t PROGMEM combo40[] = {ESC_ALT, MY_EXIST, COMBO_END};
const uint16_t PROGMEM combo42[] = {TD(TD_SHIFT_CAPS), KC_DLR, COMBO_END};
const uint16_t PROGMEM combo43[] = {TD(TD_SHIFT_CAPS), KC_0, COMBO_END};
const uint16_t PROGMEM combo44[] = {TD(TD_SHIFT_CAPS), KC_1, COMBO_END};
const uint16_t PROGMEM combo45[] = {TD(TD_SHIFT_CAPS), KC_2, COMBO_END};
const uint16_t PROGMEM combo46[] = {TD(TD_SHIFT_CAPS), KC_3, COMBO_END};
const uint16_t PROGMEM combo47[] = {TD(TD_SHIFT_CAPS), KC_4, COMBO_END};
const uint16_t PROGMEM combo48[] = {TD(TD_SHIFT_CAPS), KC_5, COMBO_END};
const uint16_t PROGMEM combo49[] = {TD(TD_SHIFT_CAPS), KC_6, COMBO_END};
const uint16_t PROGMEM combo50[] = {TD(TD_SHIFT_CAPS), KC_7, COMBO_END};
const uint16_t PROGMEM combo51[] = {TD(TD_SHIFT_CAPS), KC_8, COMBO_END};
const uint16_t PROGMEM combo52[] = {TD(TD_SHIFT_CAPS), KC_9, COMBO_END};
const uint16_t PROGMEM combo1[] = {KC_LCTL, ESC_ALT, MY_LESS, COMBO_END};
const uint16_t PROGMEM combo3[] = {TD(TD_SHIFT_CAPS), MY_RIGHTARR, COMBO_END};
const uint16_t PROGMEM combo5[] = {ESC_ALT, MY_RIGHTARR, COMBO_END};

const uint16_t PROGMEM combo19[] = {TD(TD_SHIFT_CAPS), MY_EXIST, COMBO_END};
const uint16_t PROGMEM combo20[] = {ESC_ALT, MY_INTEGR, COMBO_END};
const uint16_t PROGMEM combo21[] = {TD(TD_SHIFT_CAPS), MY_INTEGR, COMBO_END};

const uint16_t PROGMEM combo061[] = {LEFT_TOGGLE, KC_I, COMBO_END};
const uint16_t PROGMEM combo073[] = {LEFT_TOGGLE, KC_U, COMBO_END};
const uint16_t PROGMEM combo074[] = {LEFT_TOGGLE, KC_V, COMBO_END};

const uint16_t PROGMEM combo037[] = {LEFT_TOGGLE, ESC_ALT, KC_O, COMBO_END};
const uint16_t PROGMEM combo038[] = {LEFT_TOGGLE, ESC_ALT, KC_K, COMBO_END};
const uint16_t PROGMEM combo040[] = {LEFT_TOGGLE, ESC_ALT, KC_I, COMBO_END};
const uint16_t PROGMEM combo05[] = {LEFT_TOGGLE, ESC_ALT, KC_V, COMBO_END};
const uint16_t PROGMEM combo020[] = {LEFT_TOGGLE, ESC_ALT, KC_U, COMBO_END};

const uint16_t PROGMEM combo0061[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_I, COMBO_END};
const uint16_t PROGMEM combo0073[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_U, COMBO_END};
const uint16_t PROGMEM combo0074[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_V, COMBO_END};
const uint16_t PROGMEM combo0053[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_A, COMBO_END};
const uint16_t PROGMEM combo0056[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_D, COMBO_END};
const uint16_t PROGMEM combo0057[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_E, COMBO_END};
const uint16_t PROGMEM combo0058[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_F, COMBO_END};
const uint16_t PROGMEM combo0059[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_G, COMBO_END};
const uint16_t PROGMEM combo0069[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_Q, COMBO_END};
const uint16_t PROGMEM combo0070[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_R, COMBO_END};
const uint16_t PROGMEM combo0071[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_S, COMBO_END};
const uint16_t PROGMEM combo0072[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_T, COMBO_END};
const uint16_t PROGMEM combo0075[] = {LEFT_TOGGLE,TD(TD_SHIFT_CAPS), KC_W, COMBO_END};

const uint16_t PROGMEM combo094[] = {RIGHT_TOGGLE, MY_INTEGR, COMBO_END};
const uint16_t PROGMEM combo095[] = {RIGHT_TOGGLE, MY_EXIST, COMBO_END};
const uint16_t PROGMEM combo092[] = {RIGHT_TOGGLE, MY_RIGHTARR, COMBO_END};

#endif

combo_t key_combos[] = {
  COMBO(combo53, S(KC_A)),
  COMBO(combo54, S(KC_B)),
  COMBO(combo55, S(KC_C)),
  COMBO(combo56, S(KC_D)),
  COMBO(combo57, S(KC_E)),
  COMBO(combo58, S(KC_F)),
  COMBO(combo59, S(KC_G)),
  COMBO(combo60, S(KC_H)),
  COMBO(combo61, S(KC_I)),
  COMBO(combo62, S(KC_J)),
  COMBO(combo63, S(KC_K)),
  COMBO(combo64, S(KC_L)),
  COMBO(combo65, S(KC_M)),
  COMBO(combo66, S(KC_N)),
  COMBO(combo67, S(KC_O)),
  COMBO(combo68, S(KC_P)),
  COMBO(combo69, S(KC_Q)),
  COMBO(combo70, S(KC_R)),
  COMBO(combo71, S(KC_S)),
  COMBO(combo72, S(KC_T)),
  COMBO(combo73, S(KC_U)),
  COMBO(combo74, S(KC_V)),
  COMBO(combo75, S(KC_W)),
  COMBO(combo76, S(KC_X)),
  COMBO(combo77, S(KC_Y)),
  COMBO(combo78, S(KC_Z)),

  COMBO(combo010, KC_CIRC),

  COMBO(combo053, KC_5),
  COMBO(combo054, KC_LPRN),
  COMBO(combo055, KC_AMPR),
  COMBO(combo056, KC_7),
  COMBO(combo057, KC_2),
  COMBO(combo058, KC_8),
  COMBO(combo059, KC_9),
  COMBO(combo060, KC_BSLS),
  COMBO(combo063, KC_PPLS),
  COMBO(combo064, KC_PAST),
  COMBO(combo065, KC_LCBR),
  COMBO(combo066, KC_LBRC),
  COMBO(combo067, KC_EQL),
  COMBO(combo068, MY_LESS),
  COMBO(combo069, KC_0),
  COMBO(combo070, KC_3),
  COMBO(combo071, KC_6),
  COMBO(combo072, KC_4),
  COMBO(combo075, KC_1),
  COMBO(combo076, KC_HASH),
  COMBO(combo077, KC_QUES),
  COMBO(combo078, KC_DLR),

  COMBO(combo0054, KC_RPRN),
  COMBO(combo0055, KC_AT),
  COMBO(combo0060, S(KC_BSLS)),
  COMBO(combo0063, KC_PMNS),
  COMBO(combo0064, KC_SLASH),
  COMBO(combo0065, KC_RCBR),
  COMBO(combo0066, KC_RBRC),
  COMBO(combo0067, KC_TILD),
  COMBO(combo0068, MY_GREAT),
  COMBO(combo0076, KC_PERC),
  COMBO(combo0077, KC_EXLM),

  COMBO(combo079, KC_Q),
  COMBO(combo080, KC_W),
  COMBO(combo081, KC_E),
  COMBO(combo082, KC_R),
  COMBO(combo083, KC_T),
  COMBO(combo084, KC_A),
  COMBO(combo085, KC_S),
  COMBO(combo086, KC_D),
  COMBO(combo087, KC_F),
  COMBO(combo088, KC_G),
  COMBO(combo089, KC_Z),
  COMBO(combo090, KC_X),
  COMBO(combo091, KC_C),
  COMBO(combo093, KC_Y),
  COMBO(combo096, KC_O),
  COMBO(combo097, KC_P),
  COMBO(combo098, KC_H),
  COMBO(combo099, KC_J),
  COMBO(combo100, KC_K),
  COMBO(combo101, KC_L),
  COMBO(combo102, KC_B),
  COMBO(combo103, KC_N),
  COMBO(combo104, KC_M),

  COMBO(combo153, C(KC_A)),
  COMBO(combo154, C(KC_B)),
  COMBO(combo155, C(KC_C)),
  COMBO(combo156, C(KC_D)),
  COMBO(combo157, C(KC_E)),
  COMBO(combo158, C(KC_F)),
  COMBO(combo159, C(KC_G)),
  COMBO(combo160, C(KC_H)),
  COMBO(combo161, C(KC_I)),
  COMBO(combo162, C(KC_J)),
  COMBO(combo163, C(KC_K)),
  COMBO(combo164, C(KC_L)),
  COMBO(combo165, C(KC_M)),
  COMBO(combo166, C(KC_N)),
  COMBO(combo167, C(KC_O)),
  COMBO(combo168, C(KC_P)),
  COMBO(combo169, C(KC_Q)),
  COMBO(combo170, C(KC_R)),
  COMBO(combo171, C(KC_S)),
  COMBO(combo172, C(KC_T)),
  COMBO(combo173, C(KC_U)),
  COMBO(combo174, C(KC_V)),
  COMBO(combo175, C(KC_W)),
  COMBO(combo176, C(KC_X)),
  COMBO(combo177, C(KC_Y)),
  COMBO(combo178, C(KC_Z)),

  COMBO(combo01, S(KC_SCLN)),
  COMBO(combo02, S(KC_COMMA)),
  COMBO(combo03, S(KC_BSLS)),
  COMBO(combo2, KC_DOT),
  COMBO(combo4, KC_TILD),
  COMBO(combo7, KC_DQT),
  COMBO(combo8, KC_GRV),
  COMBO(combo9, KC_GT),
  COMBO(combo10, KC_CIRC),
  COMBO(combo15, KC_PERC),
  COMBO(combo16, KC_RPRN),
  COMBO(combo17, KC_RBRC),
  COMBO(combo18, KC_RCBR),
  COMBO(combo25, TWO_TOGGLE),
  COMBO(combo29, KC_UNDS),
  COMBO(combo30, KC_TAB),
  COMBO(combo31, MY_GREAT),
  COMBO(combo32, KC_DEL),
  COMBO(combo33, KC_AT),
  COMBO(combo34, KC_EXLM),
  COMBO(combo41, KC_SLASH),
  COMBO(combo0, KC_PMNS),
  COMBO(combo000, LCS(KC_RIGHT)),
  COMBO(combo001, LCS(KC_LEFT)),
  
  #if MY_UNICODE_ENABLE
  COMBO(combo36, UM(LTEQ)),
  COMBO(combo37, UM(NOTEQ)),
  COMBO(combo38, UM(PLMIN)),
  COMBO(combo40, UM(FORALL)),
  COMBO(combo42, UM(EUR)),
  COMBO(combo43, UM(SUB_0)),
  COMBO(combo44, UM(SUB_1)),
  COMBO(combo45, UM(SUB_2)),
  COMBO(combo46, UM(SUB_3)),
  COMBO(combo47, UM(SUB_4)),
  COMBO(combo48, UM(SUB_5)),
  COMBO(combo49, UM(SUB_6)),
  COMBO(combo50, UM(SUB_7)),
  COMBO(combo51, UM(SUB_8)),
  COMBO(combo52, UM(SUB_9)),
  COMBO(combo1, UM(GTEQ)),
  COMBO(combo3, UM(LEFTARR)),
  COMBO(combo5, UM(LEFTRIGHTARR)),
  COMBO(combo19, UM(ELEMOF)),
  COMBO(combo20, UM(INFTY)),
  COMBO(combo21, UM(NABLA)),

  COMBO(combo073, MY_INTEGR),
  COMBO(combo074, MY_RIGHTARR),
  COMBO(combo061, MY_EXIST),

  COMBO(combo037, UM(NOTEQ)),
  COMBO(combo038, UM(PLMIN)),
  COMBO(combo040, UM(FORALL)),
  COMBO(combo05, UM(LEFTRIGHTARR)),
  COMBO(combo020, UM(INFTY)),

  COMBO(combo0061, UM(ELEMOF)),
  COMBO(combo0073, UM(NABLA)),
  COMBO(combo0074, UM(LEFTARR)),
  COMBO(combo0078, UM(EUR)),
  COMBO(combo0053, UM(SUB_5)),
  COMBO(combo0056, UM(SUB_7)),
  COMBO(combo0057, UM(SUB_2)),
  COMBO(combo0058, UM(SUB_8)),
  COMBO(combo0059, UM(SUB_9)),
  COMBO(combo0069, UM(SUB_0)),
  COMBO(combo0070, UM(SUB_3)),
  COMBO(combo0071, UM(SUB_6)),
  COMBO(combo0072, UM(SUB_4)),
  COMBO(combo0075, UM(SUB_1)),

  COMBO(combo092, KC_V),
  COMBO(combo094, KC_U),
  COMBO(combo095, KC_I),
  #endif
};



//    %---------------------%
//    |  NEW KEY BEHAVIOUR  |
//    %---------------------%

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case RIGHT_TOGGLE:

            if (record->event.pressed) {
               layer_state = 1; // 1000... in binary
                //for(uint16_t i=1; i<=MY_MAX_LAYER; i++){
                //    layer_off(i);
                //}
            }
            else {
                if (!record->tap.count) {
                    layer_state = 3; // 1100... in binary
                    //layer_on(1);
                }
            }
            return false;
            break;

        ///// ---------------------

        case LEFT_TOGGLE:

            if (record->event.pressed) {
                layer_state = 3; // 1100... in binary
                //layer_on(1);
                //for(uint16_t i=2; i<=MY_MAX_LAYER; i++){
                //    layer_off(i);
                //}
            }
            else {
                if (!record->tap.count) {
                    layer_state = 1; // 1000... in binary
                    //layer_off(1);
                }
            }
            return false;
            break;

         ///// ---------------------

         case TWO_TOGGLE:

            if (record->event.pressed) {
                layer_state = 7; // 1110... in binary
                //layer_on(2);
                //for(uint16_t i=3; i<=MY_MAX_LAYER; i++){
                //    layer_off(i);
                //}
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
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC, KC_ENTER,           		      KC_B,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_N,   KC_M,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            	   TD(META_TO6),LEFT_TOGGLE,KC_LCTL,  TD(TD_SHIFT_CAPS),RIGHT_TOGGLE,ESC_ALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3( //numeric
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_0,    KC_1,    KC_2,    KC_3,    KC_4,  KC_QUOTE,                     KC_QUES,MY_INTEGR,MY_EXIST, KC_EQL, MY_LESS, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_BSPC,                      KC_BSLS,  ACCEL,   KC_UP,  KC_PPLS, KC_PAST, KC_COMMA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DLR, KC_HASH,KC_AMPR,MY_RIGHTARR,KC_SPC,KC_ENTER,                   	KC_LPRN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LBRC, KC_LCBR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   TD(META_TO6),LEFT_TOGGLE,KC_LCTL,  TD(TD_SHIFT_CAPS),RIGHT_TOGGLE,ESC_ALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3( //stuff
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_PWR,                      UG_TOGG,KC_PSCR,XXXXXXX,XXXXXXX,TG(ADD_LAYER+1),TG(ADD_LAYER),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_BSPC,                TG_GREEK_LAYER, ACCEL,  KC_UP,  KC_BRIU,  KC_VOLU, KC_MUTE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F11,   KC_F12, XXXXXXX, XXXXXXX, KC_SPC, KC_ENTER,            	      KC_CALC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MPLY, EE_CLR,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     TD(META_TO6),LEFT_TOGGLE,KC_LCTL, 	TD(TD_SHIFT_CAPS),RIGHT_TOGGLE,ESC_ALT
                                        //`--------------------------'  `--------------------------'
  ),

  #if MY_UNICODE_ENABLE
    [GREEK_LAYER] = LAYOUT_split_3x6_3( //greek
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,   FSIGM,   EPSI,   RHO,   TAU,  KC_QUOTE  ,                        UPSI,    THET,    IOTA,    OMIC,    PI,    KC_SCLN,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         ALPH,    SIGM,    DELT,    PHI,     GAMM,  KC_BSPC,                        ETA,     XI,     KC_UP,    KAPP,   LAMB,   KC_COMMA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         ZETA,    CHI,     PSI,     OMEG,   KC_SPC, KC_ENTER,                       BETA,  KC_LEFT, KC_DOWN, KC_RIGHT,   NU,      MU,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            	   TD(META_TO6),LEFT_TOGGLE,KC_LCTL,  TD(TD_SHIFT_CAPS),RIGHT_TOGGLE,ESC_ALT
                                        //`--------------------------'  `--------------------------'
  ),
  #endif

  #if MY_TRACKPOINT_ENABLE
    [MOUSE_LAYER] = LAYOUT_split_3x6_3( // mouse transparent layer
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, MS_BTN1, MS_BTN3, MS_BTN2, KC_TRNS, KC_TRNS,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                          //`--------------------------'  `--------------------------'
  ),
  #endif



  [SCROLL_LAYER] = LAYOUT_split_3x6_3( // scroll transparent layer
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, KC_TRNS, MS_BTN4, MS_BTN5, KC_TRNS, KC_TRNS,                      KC_TRNS, MS_BTN1, MS_BTN3, MS_BTN2, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  ACCEL, MS_WHLU,  KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLR, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
  ),



  // ------------------------------ ADD ADDITIONAL LAYERS ONLY AFTER THESE LAYERS, for hyerarchy purposes ------------------------------



    [ADD_LAYER] = LAYOUT_split_3x6_3( //vr_chat
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_F12,  XXXXXXX,  KC_E,    KC_W,    KC_R,    KC_C,                     S(KC_F1), S(KC_F2), S(KC_F3), S(KC_F4), S(KC_F5), S(KC_F6),
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_V, TD(TD_SHIFT_CAPS), KC_A,  KC_S,    KC_D,    KC_Z,                      S(KC_F7), S(KC_F8), KC_UP,  XXXXXXX,  XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_H,     KC_N,                      XXXXXXX,  KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        TD(META_TO6),LEFT_TOGGLE,KC_SPC,   XXXXXXX,RIGHT_TOGGLE,ESC_ALT
                                          //`--------------------------'  `--------------------------'
  ),

    [ADD_LAYER+1] = LAYOUT_split_3x6_3( //minecraft
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_M,    KC_B,    KC_E,    KC_W,   KC_F5,   KC_F1,                         KC_1,   KC_2,     KC_3,    KC_4,    KC_5,    KC_6,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_Q,   KC_LCTL,   KC_A,    KC_S,   KC_D,   KC_TILD,                        KC_7,    KC_8,    KC_UP,   KC_9,   XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_T,    KC_C,   XXXXXXX, XXXXXXX, KC_V,   KC_EQL,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             TD(META_TO6),LEFT_TOGGLE,TD(TD_SHIFT_CAPS),   KC_SPC,RIGHT_TOGGLE,ESC_ALT
                                          //`--------------------------'  `--------------------------'
  )//,

};
