// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// In case you forgor:
// From QMK's docs:
// The modifiers (mod) argument to the MT() macro are prefixed with MOD_, not KC_

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        KC_ESC,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                               KC_Y,   KC_U,   KC_I,       KC_O,    KC_P,      KC_BSLS,
        KC_TAB,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                               KC_H,   KC_J,   KC_K,       KC_L,    KC_SCLN,   KC_ENT,
        KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                               KC_N,   KC_M,   KC_COMM,    KC_DOT,  KC_SLSH,   KC_RSFT,
                                    MO(1),  MT(MOD_LALT, KC_SPC),   KC_LCTL,                        MO(2),  KC_LGUI,    MT(MOD_RALT, KC_BSPC)
    ),

    [1] = LAYOUT_split_3x6_3(
        KC_GRV,     KC_1,   KC_2,   KC_3,       KC_4,       KC_5,                                       KC_6,   KC_7,       KC_8,       KC_9,   KC_0,   KC_DEL,
        KC_CAPS,    KC_NO,  KC_NO,  KC_MINS,    KC_EQL,     KC_NO,                                      KC_NO,  KC_LBRC,    KC_RBRC,    KC_NO,  KC_F10, KC_F11,
        KC_LSFT,    KC_F1,  KC_F2,  KC_F3,      KC_F4,      KC_F5,                                      KC_F6,  KC_F7,      KC_F8,      KC_F9,  KC_F12, KC_RSFT,
                                    KC_TRNS,    MT(MOD_LALT, KC_SPC),   KC_LCTL,                    KC_RCTL,    KC_LGUI,    MT(MOD_RALT, KC_BSPC)
    ),

    [2] = LAYOUT_split_3x6_3(
        MS_WHLU,    KC_MPRV,    KC_MNXT,    KC_MPLY,    KC_NO,      KC_PSCR,                            KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_NO,  KC_PWR,
        MS_WHLD,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_F20,     KC_NO,                              KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    TG(3),  TG(5),
        KC_LSFT,    KC_BRID,    KC_BRIU,    MS_BTN1,    MS_BTN2,    MS_BTN3,                            MS_LEFT,    MS_DOWN,    MS_UP,      MS_RGHT,    KC_NO,  KC_RSFT,
                                            KC_APP,     MT(MOD_LALT, KC_SPC),   KC_LCTL,            KC_TRNS,        KC_LGUI,    MT(MOD_RALT, KC_BSPC)
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_ESC,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                               KC_Y,   KC_U,   KC_I,       KC_O,    KC_P,      KC_BSLS,
        KC_TAB,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                               KC_H,   KC_J,   KC_K,       KC_L,    KC_SCLN,   KC_ENT,
        KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                               KC_N,   KC_M,   KC_COMM,    KC_DOT,  KC_SLSH,   KC_RSFT,
                                    KC_LALT,    KC_SPC,     KC_LCTL,                                MO(4),  KC_SPC,     KC_NO
    ),

    [4] = LAYOUT_split_3x6_3(
        KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                               KC_6,   KC_7,   KC_8,       KC_9,   KC_0,   KC_NO,
        KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                              KC_NO,  KC_NO,  KC_NO,      KC_NO,  TG(3),  KC_NO,
        KC_NO,      KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                                              KC_F6,  KC_F7,  KC_F8,      KC_F9,  KC_F10, KC_NO,
                                    KC_LALT,    KC_SPC, KC_LCTL,                                KC_TRNS,    KC_SPC,     KC_NO
    ),

    // Layout for fighting games
    [5] = LAYOUT_split_3x6_3(
        KC_ESC,     KC_NO,  KC_NO,      KC_UP,      KC_NO,      KC_NO,                                  KC_NO,  KC_U,  KC_I,    KC_O,  KC_NO,       KC_BSLS,
        KC_TAB,     KC_NO,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                                 KC_NO,  KC_J,  KC_K,    KC_L,  KC_SCLN,     TG(5),
        KC_LSFT,    KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
                                        KC_UP,      KC_SPC,     KC_LCTL,                            KC_1,   KC_2,   KC_3
    ),
};
