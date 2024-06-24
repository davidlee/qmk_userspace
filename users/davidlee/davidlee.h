#pragma once
#include QMK_KEYBOARD_H

enum userspace_layers {
  _GAL,   // Colemak-DH
  _HRM,   // Home Row Mods / alpha hold-taps
  _GAM,   // Gaming / QWERTY
  // _GRT,   // Gaming right hand transposed left mirrored w. fn keys
  _NUM,   // Numbers
  _PTR,   // Pointer
  _NAV,   // Navigation
  // _FUN,   // Function keys
  // _MED,   // Media & right hand mods
  // _SYM,   // Dedicated symbol layer 
};

void _reset(void);
bool _is_caps_lock_on(void);
