#pragma once

//
// Combos
//

const uint16_t PROGMEM combo_bs_word[]   = {KC_H, KC_A,  COMBO_END};
const uint16_t PROGMEM combo_del_word[]  = {KC_E, KC_I,  COMBO_END};
const uint16_t PROGMEM combo_caps_word[] = {KC_N, KC_R,  COMBO_END};

const uint16_t PROGMEM combo_enter[]     = {KC_QUOT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_minus[]     = {KC_R, KC_T,       COMBO_END};

const uint16_t PROGMEM combo_lprn[]      = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM combo_rprn[]      = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_lbrc[]      = {KC_Q, KC_M, COMBO_END};
const uint16_t PROGMEM combo_rbrc[]      = {KC_M, KC_W, COMBO_END};

const uint16_t PROGMEM combo_boot[]      = {KC_X, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_bs_word,    BS_WORD),
  COMBO(combo_del_word,   DEL_WORD),
  COMBO(combo_caps_word,  CAP_WRD),
  COMBO(combo_enter,      KC_ENTER),
  COMBO(combo_minus,      KC_MINUS),
  COMBO(combo_boot,       QK_BOOT),
  COMBO(combo_lbrc,       KC_LBRC),
  COMBO(combo_rbrc,       KC_RBRC),
  COMBO(combo_lprn,       KC_LPRN),
  COMBO(combo_rprn,       KC_RPRN),
};
