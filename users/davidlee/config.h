#pragma once

/*
#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(COLEMAK_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
    #define MUSIC_MASK (keycode != KC_NO)
#endif
*/
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300

#define COMBO_COUNT 16

#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY 

// allows mod tap to resolve to a mod after a tap
#define TAPPING_FORCE_HOLD       
#define TAP_CODE_DELAY 5

// we want permissive hold for all tap-hold keys except home row mods
#define PERMISSIVE_HOLD_PER_KEY  
#define QUICK_TAP_TERM_PER_KEY 
#define QUICK_TAP_TERM 30

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_STRICT_TIMER

// time to get all combo keys down - keep it short!
#define COMBO_TERM 20               
// time to hold to trigger delayed combo
#define COMBO_HOLD 30               
#define COMBO_ONLY_FROM_LAYER 0

#define CAPSWORD_USE_SHIFT 
#define CAPS_WORD_IDLE_TIMEOUT 500  
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD 
#define QMK_KEYS_PER_SCAN 4

#define DYNAMIC_MACRO_NO_NESTING 

// MOUSE KEYS
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
//
#define MK_C_OFFSET_0 5
#define MK_C_OFFSET_1 10
#define MK_C_OFFSET_UNMOD 20
#define MK_C_OFFSET_2 40
//
#define MK_C_INTERVAL_UNMOD 16
#define MK_C_INTERVAL_0 16
#define MK_C_INTERVAL_1 16
#define MK_C_INTERVAL_2 16
//
#define MK_W_OFFSET_UNMOD   1         
#define MK_W_INTERVAL_UNMOD 20           
#define MK_W_INTERVAL_0     60       
#define MK_W_INTERVAL_1     40       
#define MK_W_INTERVAL_2     10       
