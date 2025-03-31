#pragma once

//
// mod taps
// 

#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY 

// allows mod tap to resolve to a mod after a tap
#define TAPPING_FORCE_HOLD       
#define TAP_CODE_DELAY 5

// we want permissive hold for all tap-hold keys except home row mods
#define PERMISSIVE_HOLD_PER_KEY  
#define QUICK_TAP_TERM_PER_KEY 
#define QUICK_TAP_TERM 30

//
// combos
//

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_STRICT_TIMER
// _COMBO_REF
#define COMBO_ONLY_FROM_LAYER 0

// time to get all combo keys down - keep it short!
#define COMBO_TERM 20
// time to hold to trigger delayed combo
#define COMBO_HOLD 30

//
// caps word
//

#define CAPSWORD_USE_SHIFT 
#define CAPS_WORD_IDLE_TIMEOUT 500  
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD 

//
// other
// 

#define QMK_KEYS_PER_SCAN 4
#define DYNAMIC_MACRO_NO_NESTING 
