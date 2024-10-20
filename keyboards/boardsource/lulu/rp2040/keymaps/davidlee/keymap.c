#include QMK_KEYBOARD_H
#include "davidlee.c"
#include "encoder.h"
#include "custom_oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_GAL] = LAYOUT(
// GALLIUM
KC_GRV,   KC_1,    KC_2,    KC_3,  KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_LEAD,
TAB_HYP,  KC_B,    KC_L,    KC_D,  KC_C,    KC_V,                      KC_J,    KC_Y,    KC_O,    KC_U,    KC_COMM, BSL_HYP,
ESC_MEH,  KC_N,    KC_R,    KC_T,  KC_S,    KC_G,                      KC_P,    KC_H,    KC_A,    KC_E,    KC_I,    SLS_MEH,
FN,       KC_X,    KC_Q,    KC_M,  KC_W,    KC_Z,    ENC_B1,  ENC_B2,  KC_K,    KC_F,    KC_QUOT, KC_SCLN, KC_DOT,  ENT_SFT,
                            FN,    CMD_TAB, SPC_NUM, CMD_TAB, NAV,     BS_SFT,  KC_LBRC, KC_RBRC
  ),
    
  [_HRM] = LAYOUT(
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
_______, N_CTL,   R_OPT,   T_CMD,   S_SFT,   _______,                   _______, H_SFT,   A_CMD,   E_OPT,   I_CTL,   _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT(
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______,
_______, KC_EXLM, KC_AT,   KC_HASH, KC_EQUAL,KC_LPRN,                   KC_RPRN, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,  _______,
_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
_______, KC_GRV,  KC_UNDS, KC_BSLS, KC_LCBR, KC_LBRC, _______, _______, KC_RBRC, KC_RCBR, KC_SLSH, KC_COLN, KC_DOT,   _______,
                           _______, _______, _______, _______, KC_0,    _______, KC_DOT,  _______
  ),

  [_NAV] = LAYOUT(
_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  GAM_LOCK,
KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_WH_U, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WH_U,
KC_ESC,  KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,                   KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_WH_D, CMD_LBRC,CMD_MINS,CMD_EQL, CMD_RBRC,KC_WH_D,
                           _______, KC_TAB,  KC_SPC,  _______, _______, _______, _______, _______
  ),

  [_GAM] = LAYOUT(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_LEAD,
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                           KC_LGUI, KC_LALT, KC_SPC,  KC_LCTL, NAV,     KC_BSPC, KC_ENT,  RESET
  ),
  
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return false;
}
#endif
