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
    _VIM_SFT,
    _VIM_CTL,
    _VIM_NUM,
    _DEL,
    _DEL_CTL,
    _VIS,
    _VIS_CTL,
    _VIS_NUM,
    _MEDIA,
    _GAME,
    _FG,
};

// See:
// https://docs.qmk.fm/feature_macros

enum custom_keycodes {
    COPY = SAFE_RANGE,
    UNDO,
    PASTE,
    MOVE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case COPY:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c"));
        } else {
        }
        break;

    case UNDO:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("z"));
        } else {
        }
        break;

    case PASTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("v"));
        } else {
        }
        break;

    case MOVE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x"));
        } else {
        }
        break;

    /*case PASTE:*/
    /*    if (record->event.pressed) {*/
    /*        SEND_STRING(SS_LCTL("v"));*/
    /*    } else {*/
    /*    }*/
    /*    break;*/
    /**/
    /*case PASTE:*/
    /*    if (record->event.pressed) {*/
    /*        SEND_STRING(SS_LCTL("v"));*/
    /*    } else {*/
    /*    }*/
    /*    break;*/
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
        KC_ESC,                 KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                       KC_Y,   KC_U,   KC_I,       KC_O,    KC_P,      KC_BSLS,
        MT(MOD_LALT, KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                       KC_H,   KC_J,   KC_K,       KC_L,    KC_SCLN,   KC_QUOT,
        KC_LSFT,                KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                       KC_N,   KC_M,   KC_COMM,    KC_DOT,  KC_SLSH,   KC_RSFT,
                                MT(MOD_LGUI, KC_SPC),   KC_LCTL,    MO(_MEDIA),     MT(MOD_LALT, KC_BSPC),  TG(_VIM),   LT(_NUM, KC_ENT)
    ),

    [_NUM] = LAYOUT_split_3x6_3(
        KC_GRV,     KC_1,   KC_2,   KC_3,       KC_4,       KC_5,                           KC_6,   KC_7,       KC_8,       KC_9,   KC_0,   KC_DEL,
        KC_LALT,    KC_NO,  KC_NO,  KC_MINS,    KC_EQL,     KC_NO,                          KC_NO,  KC_LBRC,    KC_RBRC,    KC_NO,  KC_F10, KC_F11,
        KC_LSFT,    KC_F1,  KC_F2,  KC_F3,      KC_F4,      KC_F5,                          KC_F6,  KC_F7,      KC_F8,      KC_F9,  KC_F12, KC_RSFT,
                                        KC_LGUI,   KC_LCTL,    KC_CAPS,         KC_NO,  KC_NO,   KC_TRNS
    ),

    [_VIM] = LAYOUT_split_3x6_3(
    KC_NO, KC_NO, C(KC_RGHT),KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    /*KC_NO, KC_NO, OSL(_DEL), KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,*/
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                        KC_NO, KC_NO, KC_NO,        KC_NO, TG(_VIM), KC_NO
    ),



























    [_MEDIA] = LAYOUT_split_3x6_3(
        MS_WHLU,    KC_MPRV,    KC_MNXT,    KC_MPLY,    KC_NO,      KC_PSCR,                            KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_NO,  KC_PWR,
        /*MS_WHLD,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_F20,     KC_NO,                              KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    TG(3),  TG(5),*/
        MS_WHLD,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_F20,     KC_NO,                              KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,  KC_NO,
        KC_LSFT,    KC_BRID,    KC_BRIU,    MS_BTN1,    MS_BTN2,    MS_BTN3,                            MS_LEFT,    MS_DOWN,    MS_UP,      MS_RGHT,    KC_NO,  KC_RSFT,
                                            KC_APP,     MT(MOD_LALT, KC_SPC),   KC_LCTL,            KC_TRNS,        KC_LGUI,    MT(MOD_RALT, KC_BSPC)
    ),

    /*[3] = LAYOUT_split_3x6_3(*/
    /*    KC_ESC,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                               KC_Y,   KC_U,   KC_I,       KC_O,    KC_P,      KC_BSLS,*/
    /*    KC_TAB,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                               KC_H,   KC_J,   KC_K,       KC_L,    KC_SCLN,   KC_ENT,*/
    /*    KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                               KC_N,   KC_M,   KC_COMM,    KC_DOT,  KC_SLSH,   KC_RSFT,*/
    /*                                KC_LALT,    KC_SPC,     KC_LCTL,                                MO(4),  KC_SPC,     KC_NO*/
    /*),*/
    /**/
    /*[4] = LAYOUT_split_3x6_3(*/
    /*    KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                               KC_6,   KC_7,   KC_8,       KC_9,   KC_0,   KC_NO,*/
    /*    KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                              KC_NO,  KC_NO,  KC_NO,      KC_NO,  TG(3),  KC_NO,*/
    /*    KC_NO,      KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                                              KC_F6,  KC_F7,  KC_F8,      KC_F9,  KC_F10, KC_NO,*/
    /*                                KC_LALT,    KC_SPC, KC_LCTL,                                KC_TRNS,    KC_SPC,     KC_NO*/
    /*),*/
    /**/
    /*// Layout for fighting games*/
    /*[5] = LAYOUT_split_3x6_3(*/
    /*    KC_ESC,     KC_NO,  KC_NO,      KC_UP,      KC_NO,      KC_NO,                                  KC_NO,  KC_U,  KC_I,    KC_O,  KC_NO,       KC_BSLS,*/
    /*    KC_TAB,     KC_NO,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                                 KC_NO,  KC_J,  KC_K,    KC_L,  KC_SCLN,     TG(5),*/
    /*    KC_LSFT,    KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,*/
    /*                                    KC_UP,      KC_SPC,     KC_LCTL,                            KC_1,   KC_2,   KC_3*/
    /*),*/
};
