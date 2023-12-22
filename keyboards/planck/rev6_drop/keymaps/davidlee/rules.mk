ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
