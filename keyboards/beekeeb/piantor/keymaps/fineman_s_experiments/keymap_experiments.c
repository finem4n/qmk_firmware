// Copyright 2022 beekeeb
// How does this copyright works if I modified the code and it's GPL-2?
// SPDX-License-Identifier: GPL-2.0-or-later

// In case you forgor:
// From QMK's docs:
// The modifiers (mod) argument to the MT() macro are prefixed with MOD_, not KC_

#include QMK_KEYBOARD_H

enum layer {
    _BASE,
    _NUM,
    _VIM,
    _MEDIA,
    _GAME,
    _GAME_NUM,
    _FG,
};

// See:
// https://docs.qmk.fm/feature_macros

enum custom_keycodes {
    REDO = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case REDO:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_Z)SS_UP(X_LSFT)SS_UP(X_LCTL));
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*[_TEMPLATE] = LAYOUT_split_3x6_3(*/
    /*KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,*/
    /*KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,*/
    /*KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,*/
    /*                    KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO*/
    /*),*/

    [_BASE] = LAYOUT_split_3x6_3(
        KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                       KC_Y,   KC_U,   KC_I,       KC_O,    KC_P,      KC_BSLS,
        KC_TAB, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                       KC_H,   KC_J,   KC_K,       KC_L,    KC_SCLN,   KC_ENT,
        MO(_MEDIA),  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                       KC_N,   KC_M,   KC_COMM,    KC_DOT,  KC_SLSH,   KC_QUOT,
                                MO(_LNUM), MO(_LMOD), MO(_VIM),           KC_SPC, MO(_RMOD), MO(_RNUM)
    ),

    [_LMOD] = LAYOUT_split_3x6_3(
        KC_ESC, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_BSLS,
        KC_TAB, KC_RALT,    KC_LCTL,    KC_LSFT,    KC_LGUI,    KC_LALT,                    KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_ENT,
        KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_QUOT,
                                                        KC_NO,  KC_TRNS, KC_NO,          KC_SPC, KC_BSPC, KC_NO
    ),

    [_RMOD] = LAYOUT_split_3x6_3(
        KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                       KC_NO,   KC_NO,   KC_NO,       KC_NO,    KC_NO,      KC_NO,
        KC_TAB, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                       KC_LALT,   KC_LGUI,   KC_LSFT,       KC_LCTL,    KC_RALT,   KC_NO,
        KC_NO,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                       KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,
                                    KC_NO, KC_DEL, KC_NO,           KC_NO, KC_TRNS, KC_NO
    ),

    [_LNUM] = LAYOUT_split_3x6_3(
        KC_ESC, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_6,   KC_7,   KC_8,       KC_9,   KC_0,       KC_NO,
        KC_TAB, KC_RALT,    KC_LCTL,    KC_LSFT,    KC_LGUI,    KC_LALT,                    KC_NO,   KC_LBRC,   KC_RBRC,       KC_NO,   KC_NO,    KC_F12,
        KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_F6,   KC_F7,   KC_F8,    KC_F9, KC_F10,    KC_F11,
                                                        KC_TRNS,  KC_NO, KC_NO,          KC_ENT, KC_BSPC, KC_NO
    ),

    [_RNUM] = LAYOUT_split_3x6_3(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       KC_NO,   KC_NO,   KC_NO,       KC_NO,    KC_NO,      KC_NO,
        KC_TAB, KC_NO,   KC_NO,   KC_MINS,   KC_EQL,   KC_NO,                       KC_LALT,   KC_LGUI,   KC_LSFT,       KC_LCTL,    KC_RALT,   KC_NO,
        KC_NO,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,
                                    KC_NO, KC_DEL, KC_SPC,           KC_NO, KC_NO, KC_TRNS
    ),
};
