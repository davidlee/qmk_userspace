#include "davidlee.h"
#include "keycodes.h"
#include "combos.h"

#define LAYER_MASK_DEFAULT (1 << _GAL | 1 << _HRM)

void keyboard_post_init_user(void) {
  default_layer_set(LAYER_MASK_DEFAULT); // BASE & HRM layers
  oneshot_enable(); // should not be necessary but ... weird bug
  rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BS_SFT:
            return QUICK_TAP_TERM - 20;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case N_CTL: 
    case R_OPT:
    case T_CMD:
    case S_SFT:
    case H_SFT:
    case A_CMD:
    case E_OPT:
    case I_CTL:
      return false;
      default:
      return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case N_CTL:
      case I_CTL:
        return TAPPING_TERM + 40;
      case E_OPT:
      case R_OPT:
        return TAPPING_TERM + 40; 
      case T_CMD:
      case A_CMD:
        return TAPPING_TERM + 40;
      case S_SFT:
      case H_SFT:
        return TAPPING_TERM + 30;
      // 
      default:
        return TAPPING_TERM;
    }
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
    case _NAV:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
      break;
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

    default:
      return true; /* Process all other keycodes normally */
  }
}

void _reset(void) {
  default_layer_set(LAYER_MASK_DEFAULT);
  layer_state_set(LAYER_MASK_DEFAULT);
}

// // 
// // LEADER KEY 
// // 
// #ifdef LEADER_ENABLE
// bool did_leader_succeed;
// void leader_end_user(void) {
//   bool did_leader_succeed = false;

//   // Layer: default
//   if(leader_sequence_two_keys(KC_L, KC_L)){
//     _reset();
//     did_leader_succeed = true;
//   }

//   if(leader_sequence_two_keys(KC_F, KC_F)) {
//     SEND_STRING("function => {");
//   }


//   // (H)ome row (E)nable
//   if(leader_sequence_two_keys(KC_H, KC_E)){
//     _reset();
//     did_leader_succeed = true;
//   }

//   // (H)ome row (D)isable
//   if(leader_sequence_two_keys(KC_H, KC_D)){
//     default_layer_set(_GAL);
//     layer_state_set(_GAL);
//     did_leader_succeed = true;
//   }

//   if (did_leader_succeed) {
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
//   } else {
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_PINWHEEL_SAT);
//   }
// }

// void leader_start_user(void) {
//   rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_VAL);
// }
// #endif
// // END LEADER KEY
