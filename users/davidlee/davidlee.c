#include "davidlee.h"
#include "keycodes.h"
#include "combos.h"

#define LAYER_MASK_DEFAULT (1 << _GAL | 1 << _HRM)
#define LAYER_MASK_GAM_LOCK (1 << _GAM)

void keyboard_post_init_user(void) {
  _reset();
}

void _reset(void) {
  default_layer_set(LAYER_MASK_DEFAULT); // BASE & HRM layers
  layer_state_set(LAYER_MASK_DEFAULT);
  oneshot_enable(); // this should not be necessary but ... weird bug
  rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
}

void _gam_lock(void) {
  default_layer_set(LAYER_MASK_GAM_LOCK);
  layer_state_set(LAYER_MASK_GAM_LOCK);
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  if (keycode == BS_SFT)
    return QUICK_TAP_TERM - 20;
  else
    return QUICK_TAP_TERM;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  return !is_home_row_mod_keycode(keycode);
}

bool is_home_row_mod_keycode(uint16_t keycode) {
  return (
    keycode == N_CTL || 
    keycode == R_OPT ||
    keycode == T_CMD ||
    keycode == S_SFT ||
    keycode == H_SFT ||
    keycode == A_CMD ||
    keycode == E_OPT ||
    keycode == I_CTL
  );
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  if(is_home_row_mod_keycode(keycode)) 
    return TAPPING_TERM + 40;
  else 
    return TAPPING_TERM;
}

void caps_word_set_user(bool active) {
  if (active) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);      
  } else {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _NUM:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_FRACTAL);
      break;
    case _NAV:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
      break;
    case _GAM:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_FRACTAL);
    case _GAL:
    default:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
      break;
  }
  
  return state;
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case CAP_WRD:
      if (record->event.pressed) {
        caps_word_on();
      }
      return false;

    case BS_WORD:
      if (record->event.pressed) {
        tap_code16(LOPT(KC_BSPC));
      }
      return false;

    case DEL_WORD:
      if (record->event.pressed) {
        tap_code16(LOPT(KC_DELETE));
      }
      return false;

    case GAM_LOCK:
      if (record->event.pressed) {
        _gam_lock();
      }
      return false;
      
    case RESET:
      if (record->event.pressed) {
        _reset();
      }
      return false;
      
    default:
      return true; /* Process all other keycodes normally */
  }
}
