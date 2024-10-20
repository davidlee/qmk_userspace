#pragma once
#include "quantum_keycodes.h"

enum userspace_keycodes {
  CAP_WRD = QK_USER, //SAFE_RANGE, // NEW_SAFE_RANGE
  BS_WORD,
  DEL_WORD,
  HRM_ON,  // ALPHA TAP / HOLD
  HRM_OFF,
  GAM_LOCK,
  RESET,
};

//
// custom keycodes
//

// function keys remapped in Karabiner
#define FN       KC_F24
#define SIRI     KC_F21

#define ENC_B1 QK_PROGRAMMABLE_BUTTON_5
#define ENC_B2 QK_PROGRAMMABLE_BUTTON_6


// misc
#define EM_DASH LOPT(KC_UNDERSCORE)

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)
#define CMD_MINS LCMD(KC_MINS)
#define CMD_EQL  LCMD(KC_EQL)

// alpha hold-tap keys
//

// HRM - Gallium

#define N_CTL  MT(MOD_LCTL, KC_N)
#define R_OPT  MT(MOD_LALT, KC_R)
#define T_CMD  MT(MOD_LGUI, KC_T)
#define S_SFT  MT(MOD_LSFT, KC_S)

#define H_SFT  MT(MOD_RSFT, KC_H)
#define A_CMD  MT(MOD_RGUI, KC_A)
#define E_OPT  MT(MOD_LALT, KC_E)
#define I_CTL  MT(MOD_RCTL, KC_I)

// right hand side mods
#define SLS_MEH MT(MOD_MEH, KC_SLASH)


// non-alpha / outer dual-function keys
//
// leftmost column
#define ESC_MEH  MT(MOD_MEH, KC_ESC)

#define GRV_HYP  MT(MOD_HYPR, KC_GRV) // better on planck
#define TAB_HYP  MT(MOD_HYPR, KC_TAB)

//
// bottom row
#define CMD_TAB  MT(MOD_LGUI, KC_TAB)
#define SPC_NUM  LT(_NUM, KC_SPC)
// #define ESC_PTR  LT(_PTR, ESC)

#define NAV      MO(_NAV)
#define BS_SFT   MT(MOD_RSFT, KC_BSPC)

//
// rightmost column
#define DEL_MEH  MT(MOD_MEH,  KC_DEL)   
#define BSL_HYP  MT(MOD_HYPR, KC_BACKSLASH)
#define ENT_SFT  MT(MOD_RSFT, KC_ENTER)

