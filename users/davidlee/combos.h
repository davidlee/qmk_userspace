#pragma once

//
// Combos
//

// Command -> ZX or ./ or RS or EI
const uint16_t PROGMEM combo_lcmd[]     = {KC_R,  KC_S,  COMBO_END};
const uint16_t PROGMEM combo_rcmd[]     = {KC_E,  KC_I,  COMBO_END};
const uint16_t PROGMEM combo_lcmd2[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_rcmd2[] = {KC_DOT, KC_SLSH, COMBO_END};

// W + F = (
const uint16_t PROGMEM combo_lprn[]      = {KC_W, KC_F, COMBO_END};
// F + P = )
const uint16_t PROGMEM combo_rprn[]      = {KC_F, KC_P, COMBO_END};

// X + C = [
const uint16_t PROGMEM combo_lbrc[]      = {KC_X, KC_C, COMBO_END};
// C + D = ]
const uint16_t PROGMEM combo_rbrc[]      = {KC_C, KC_D, COMBO_END};

// N + S = backspace word
const uint16_t PROGMEM combo_bs_word[]  = {KC_N,  KC_E,  COMBO_END};

// I + O = delete word
const uint16_t PROGMEM combo_del_word[] = {KC_I,  KC_O,  COMBO_END};

// A + R = caps word
const uint16_t PROGMEM combo_caps_word[]= {KC_A, KC_R,   COMBO_END};

// N + U = turn on PTR layer
const uint16_t PROGMEM combo_ptr[]      = {KC_N,  KC_U, COMBO_END};

// BOOT MODE -> PINKIES UP!
const uint16_t PROGMEM combo_boot[] = {KC_Q, KC_SCLN, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_lcmd,       KC_LGUI),
  COMBO(combo_rcmd,       KC_RGUI),
  COMBO(combo_lcmd,       KC_LCMD),
  COMBO(combo_rcmd,       KC_RCMD),
  COMBO(combo_lbrc,       KC_LBRC),
  COMBO(combo_rbrc,       KC_RBRC),
  COMBO(combo_lprn,       KC_LPRN),
  COMBO(combo_rprn,       KC_RPRN),

  COMBO(combo_bs_word,    BS_WORD),
  COMBO(combo_del_word,   DEL_WORD),
  COMBO(combo_caps_word,  CAP_WRD),
  COMBO(combo_ptr,        PTR_LCK),

  COMBO(combo_boot, QK_BOOT),

};
