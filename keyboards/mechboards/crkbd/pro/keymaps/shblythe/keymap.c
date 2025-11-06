// Copyright 2025 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines for readability

// Layers
enum {
    L_BASE,
    L_GAME,
    L_NUM,
    L_SYM,
    L_RGB,
    L_TAB,
};

// Make Left Control + Escape
#define M_LCESC LCTL_T(KC_ESC)

// Home Row Mods
#define M_LS_A LSFT_T(KC_A)
#define M_LW_D LGUI_T(KC_D)
#define M_LC_F LCTL_T(KC_F)
#define M_RS_SC RSFT_T(KC_SCLN)
#define M_RW_K RGUI_T(KC_K)
#define M_RC_J RCTL_T(KC_J)

// Tab hold switches to layer 4, tap is KC_TAB
#define M_TAB LT(L_TAB, KC_TAB)

#define LS_NUBS LSFT(KC_NUBS)

// TODO
// - Fn keys?
// D Shifted NUBS/NUHS on layer 2
// D Ditch kanata for this keyboard
//   D Reimplement HRM here
//   D Add tab layer (momentary)
//   D Add gaming layer (replaces layer 0 when active, removes HRM)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Standard QWERTY layout with Home Row Mods
    [L_BASE] = LAYOUT_split_3x6_3(
        M_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    LS_NUBS,
        M_LCESC, M_LS_A,  KC_S,    M_LW_D,  M_LC_F,  KC_G,                          KC_H,    M_RC_J,  M_RW_K,  KC_L,   M_RS_SC, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                                        KC_LALT, MO(L_NUM),  KC_SPC,      KC_SPC,   MO(L_SYM), KC_BSPC
    ),

    // Gaming layer, mostly like standard, but no HRM
    [L_GAME] = LAYOUT_split_3x6_3(
        M_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                                        KC_LALT, MO(L_NUM),  KC_SPC,      KC_SPC,   MO(L_SYM), KC_BSPC
    ),

    // Number/symbol layer (activated by left thumb)
    [L_NUM] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_NUBS,                       KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,  KC_PIPE, KC_NUHS,
                                            _______, _______, _______,    _______, MO(L_RGB), _______
    ),

    // Number/symbol layer (activated by right thumb)
    // (Identical, but needed to handle both thumb keys lauching RGB layer)
    [L_SYM] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_NUBS,                       KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,  KC_PIPE, KC_NUHS,
                                            _______, MO(L_RGB), _______,  _______, _______, _______
    ),

    // RGB and system control
    [L_RGB] = LAYOUT_split_3x6_3(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, KC_SPC,      _______, _______, _______
    ),

    // Tab layer
    [L_TAB] = LAYOUT_split_3x6_3(
        _______, DF(L_BASE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_A,    KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX,
        XXXXXXX, KC_LSFT,    XXXXXXX, XXXXXXX, XXXXXXX, DF(L_GAME),                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT, XXXXXXX,
        XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, KC_SPC,      _______, _______, _______
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
[1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#endif

// clang-format on

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4,
        0x85, 0x86, 0x87, 0x88, 0x89,
        0xA5, 0xA6, 0xA7, 0xA8, 0xA9,
        0xC5, 0xC6, 0xC7, 0xC8, 0xC9,
        0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    oled_clear();
    oled_set_cursor(0, 0);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            oled_write_P(PSTR("Deflt"), false);
            break;
        case L_GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case L_NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case L_SYM:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        case L_TAB:
            oled_write_P(PSTR("Tab\n"), false);
            break;
        case L_RGB:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_write_P(PSTR("\n\n\n\n\n\n\n\n"), false);
    render_logo();
    return false;
}
#endif
