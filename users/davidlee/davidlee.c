#include "davidlee.h"
#include "keycodes.h"
#include "combos.h"

#define LAYER_MASK_DEFAULT (1 << _GAL | 1 << _HRM)

//
// Function Overrides
//

void keyboard_post_init_user(void) {
  default_layer_set(LAYER_MASK_DEFAULT); // COLEMAK & ALPHA TAP/HOLD layers
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
// give precedence to tap rather than hold for home row mods, to avoid accidental mistypes
// NOTE: this gives _hold_ precedence for bottom row mods Z_CTL, X_OPT, C_CMD and COM_CMD, DOT_OPT, SLS_CTL
// as well as all hold/tap keys on the side and lower rows

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


// TODO:
//
// 1. extract mapping of layer state => RGB MATRIX mode for use in layer_state_set_user
// 2. consider using rgb_matrix_indicators_advanced_user in 
//    place of caps_word_set_user / the first stanza of layer_state_set_user
// 3. use global variable layer_state along with said mapping 
//    for the "caps disabled" branch, to return to the appropriate layer indication

void caps_word_set_user(bool active) {
  if (active) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);      

  } else {
    // TODO FIXME hax 
    // this should call layer_state_set_user, or 
    // we need to implement layer indications using some other hook
    rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
  }
}

// helper method for caps lock layer indication
// bool _is_caps_lock_on(void) {
//   return host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK);
// }

layer_state_t layer_state_set_user(layer_state_t state) {
  
  // CAPS LOCK / CAPS WORD indication
  // without this, activation via a momentary layer (vs say, a combo) 
  // will have its indication cancelled when layer changes back ...
  // still, it feels a bit like a crude hack.
  // if (_is_caps_lock_on() || is_caps_word_on()) {
  //   rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
  //   return state;
  // }

  switch (get_highest_layer(state)) {
    case _NUM:
    case _NAV:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
      break;
    // case _PTR:
    //   rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
    //   break;
    // case _GAM:
    //   rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
    //   break;
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
    // case GAM_LCK:
    //   layer_on(_GAM);
    //   #ifdef AUDIO_ENABLE
    //     PLAY_SONG(arp_song);
    //   #endif
    //   return false;

    // case PTR_LCK:
    //   layer_on(_PTR);
    //   rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
    //   return false;

    // // EXIT LAYERS

    // case EXT_GAM:
    //   layer_off(_GAM);
    //   #ifdef AUDIO_ENABLE
    //     PLAY_SONG(arp_song);
    //   #endif
    //   return false;

    // case EXT_PTR:
    //   layer_off(_PTR);
    //   #ifdef AUDIO_ENABLE
    //     PLAY_SONG(blip_song);
    //   #endif
    //   return false;

    // other functions

    case CAP_WRD:
      if (record->event.pressed) {
        caps_word_on();
        #ifdef AUDIO_ENABLE
          PLAY_SONG(blip_song);
        #endif
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

    // case MO_SYM:
    //   if (record->event.pressed) {
    //     layer_on(_SYM);
    //   } else {
    //     layer_off(_SYM);
    //   }
    //   return false;

    default:
      return true; /* Process all other keycodes normally */
  }
}

void _reset(void) {
  default_layer_set(LAYER_MASK_DEFAULT);
  layer_state_set(LAYER_MASK_DEFAULT);
}

// 
// LEADER KEY 
// 
#ifdef LEADER_ENABLE
bool did_leader_succeed;
void leader_end_user(void) {
  bool did_leader_succeed = false;

  // Layer: default
  if(leader_sequence_two_keys(KC_L, KC_L)){
    _reset();
    did_leader_succeed = true;
  }

  if(leader_sequence_two_keys(KC_F, KC_F)) {
    SEND_STRING("function => {");
  }


  // (H)ome row (E)nable
  if(leader_sequence_two_keys(KC_H, KC_E)){
    _reset();
    did_leader_succeed = true;
  }

  // (H)ome row (D)isable
  if(leader_sequence_two_keys(KC_H, KC_D)){
    default_layer_set(_GAL);
    layer_state_set(_GAL);
    did_leader_succeed = true;
  }

  if (did_leader_succeed) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
  } else {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_PINWHEEL_SAT);
  }
}

void leader_start_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_VAL);
}

#endif
// END LEADER KEY
