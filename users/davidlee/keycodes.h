#pragma once
#include "quantum_keycodes.h"

enum userspace_keycodes {
  CAP_WRD = QK_USER, //SAFE_RANGE, // NEW_SAFE_RANGE
  BS_WORD,
  DEL_WORD,
  HRM_ON,  // ALPHA TAP / HOLD
  HRM_OFF,
};

//
// custom keycodes
//

// function keys remapped in Karabiner
#define FN       KC_F24
#define SIRI     KC_F21

#define ENC_B1 QK_PROGRAMMABLE_BUTTON_5
#define ENC_B2 QK_PROGRAMMABLE_BUTTON_6

// clipboard
// #define UNDO   LCMD(KC_Z)
// #define CUT    LCMD(KC_X)
// #define COPY   LCMD(KC_C)
// #define PASTE  LCMD(KC_V)

// misc
#define EM_DASH LOPT(KC_UNDERSCORE)

#define CMD_LBRC LCMD(KC_LBRC)
#define CMD_RBRC LCMD(KC_RBRC)
#define CMD_MINS LCMD(KC_MINS)
#define CMD_EQL  LCMD(KC_EQL)

// #define MO_PTR MO(_PTR)
// #define ENT_PTR LT(_PTR, KC_ENTER)

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
// #define SLS_CTL MT(MOD_RCTL, KC_SLASH)
#define SLS_MEH MT(MOD_MEH, KC_SLASH)
// #define DOT_OPT MT(MOD_RALT, KC_DOT)
// #define COM_CMD MT(MOD_RGUI, KC_COMMA)

//
// left hand side mods
// #define Z_CTL MT(MOD_RCTL, KC_Z)
// #define X_OPT MT(MOD_RALT, KC_X)
// #define C_CMD MT(MOD_RGUI, KC_C)


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
// #define FUN      MO(_FUN)

#define NAV      MO(_NAV)
#define BS_SFT   MT(MOD_RSFT, KC_BSPC)
// #define ENT_MED  LT(_MED, KC_ENTER)

//
// rightmost column
#define DEL_MEH  MT(MOD_MEH,  KC_DEL)   
// #define QOT_OPT  MT(MOD_RALT, KC_QUOTE) 

#define DEL_HYP  MT(MOD_HYPR, KC_DEL)
// #define QOT_MEH  MT(MOD_MEH,  KC_QUOTE)
#define ENT_SFT  MT(MOD_RSFT, KC_ENTER)
