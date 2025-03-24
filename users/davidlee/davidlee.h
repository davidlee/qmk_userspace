#pragma once
#include QMK_KEYBOARD_H

enum userspace_layers {
  _GAL,   // Colemak-DH
  _HRM,   // Home Row Mods / alpha hold-taps
  _GAM,   // Gaming / QWERTY
  _NUM,   // Numbers
  _NAV,   // Navigation
  _COMBO_REF // only used for combo definitions
};

void _reset(void);
bool _is_caps_lock_on(void);
void _gam_lock(void);

#define COMBO_ONLY_FROM_LAYER _COMBO_REF;
