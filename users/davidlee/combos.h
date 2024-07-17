#pragma once

//
// Combos
//

const uint16_t PROGMEM bs_word[]   = {KC_H, KC_A,  COMBO_END};
const uint16_t PROGMEM del_word[]  = {KC_E, KC_I,  COMBO_END};
const uint16_t PROGMEM caps_word[] = {KC_N, KC_R,  COMBO_END};

const uint16_t PROGMEM enter[]     = {KC_QUOT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM enter2[]    = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM minus[]     = {KC_R, KC_T,       COMBO_END};
const uint16_t PROGMEM under[]     = {KC_T, KC_S, COMBO_END};

const uint16_t PROGMEM lprn[]      = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM rprn[]      = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM lbrc[]      = {KC_Q, KC_M, COMBO_END};
const uint16_t PROGMEM rbrc[]      = {KC_M, KC_W, COMBO_END};

const uint16_t PROGMEM boot[]      = {KC_X, KC_DOT, COMBO_END};

const uint16_t PROGMEM pause[]     = {KC_J, KC_Y, COMBO_END};
const uint16_t PROGMEM vol_u[]     = {KC_J, KC_Y, COMBO_END};
const uint16_t PROGMEM vol_d[]     = {KC_J, KC_Y, COMBO_END};
// KC_MNXT KC_MPRV

combo_t key_combos[COMBO_COUNT] = {
  COMBO(bs_word,    BS_WORD),
  COMBO(del_word,   DEL_WORD),
  COMBO(caps_word,  CAP_WRD),
  COMBO(enter,      KC_ENTER),
  COMBO(enter2,     KC_ENTER),
  COMBO(minus,      KC_MINUS),
  COMBO(boot,       QK_BOOT),
  COMBO(pause,      KC_MPLY),
  COMBO(vol_u,      KC_VOLU),
  COMBO(vol_d,      KC_VOLD),
  COMBO(under,      KC_UNDS),
  COMBO(lbrc,       KC_LBRC),
  COMBO(rbrc,       KC_RBRC),
  COMBO(lprn,       KC_LPRN),
  COMBO(rprn,       KC_RPRN),
};

/* TODO 
em dash
*/
