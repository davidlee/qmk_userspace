#pragma once
//
// combos - config https://docs.qmk.fm/features/combo
//

const uint16_t PROGMEM boot[]      = {KC_X, KC_DOT, COMBO_END};

const uint16_t PROGMEM bs_word[]   = {KC_H, KC_A,  COMBO_END};
const uint16_t PROGMEM del_word[]  = {KC_E, KC_I,  COMBO_END};
const uint16_t PROGMEM caps_word[] = {KC_N, KC_R,  COMBO_END};

const uint16_t PROGMEM enter[]     = {KC_QUOT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM minus[]     = {KC_R, KC_T,       COMBO_END};
const uint16_t PROGMEM under[]     = {KC_T, KC_S,       COMBO_END};

const uint16_t PROGMEM lprn[]      = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM rprn[]      = {KC_D, KC_C, COMBO_END};

const uint16_t PROGMEM lbrc[]      = {KC_Q, KC_M, COMBO_END};
const uint16_t PROGMEM rbrc[]      = {KC_M, KC_W, COMBO_END};

const uint16_t PROGMEM pause[]     = {KC_J, KC_Y, COMBO_END};
const uint16_t PROGMEM vol_u[]     = {KC_H, KC_O, COMBO_END};
const uint16_t PROGMEM vol_d[]     = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM prev_trk[]     = {KC_P, KC_Y, COMBO_END};
const uint16_t PROGMEM next_trk[]     = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
  COMBO(boot,       QK_BOOT),
  COMBO(bs_word,    BS_WORD),
  COMBO(del_word,   DEL_WORD),
  COMBO(caps_word,  CAP_WRD),
  COMBO(enter,      KC_ENTER),
  COMBO(minus,      KC_MINUS),
  COMBO(under,      KC_UNDS),
  COMBO(lbrc,       KC_LBRC),
  COMBO(rbrc,       KC_RBRC),
  COMBO(lprn,       KC_LPRN),
  COMBO(rprn,       KC_RPRN),
  COMBO(pause,      KC_MPLY),
  COMBO(vol_u,      KC_VOLU),
  COMBO(vol_d,      KC_VOLD),
  COMBO(prev_trk,   KC_VOLD),
  COMBO(next_trk,   KC_VOLD),
};

