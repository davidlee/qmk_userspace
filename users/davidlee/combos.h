#pragma once

//
// Combos
//

// Command -> ZX or ./ or RS or EI

const uint16_t PROGMEM combo_lprn[]      = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_rprn[]      = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_lbrc[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_rbrc[]      = {KC_C, KC_D, COMBO_END};

const uint16_t PROGMEM combo_bs_word[]   = {KC_N,  KC_E,  COMBO_END};
const uint16_t PROGMEM combo_del_word[]  = {KC_I,  KC_O,  COMBO_END};
const uint16_t PROGMEM combo_caps_word[] = {KC_A, KC_R,   COMBO_END};


// BOOT MODE -> PINKIES UP!
const uint16_t PROGMEM combo_boot[]      = {KC_Q, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_boot,       QK_BOOT),

  COMBO(combo_lbrc,       KC_LBRC),
  COMBO(combo_rbrc,       KC_RBRC),
  COMBO(combo_lprn,       KC_LPRN),
  COMBO(combo_rprn,       KC_RPRN),

  COMBO(combo_bs_word,    BS_WORD),
  COMBO(combo_del_word,   DEL_WORD),
  COMBO(combo_caps_word,  CAP_WRD),

};
