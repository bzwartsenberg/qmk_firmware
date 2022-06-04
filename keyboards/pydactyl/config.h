#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    qmkbuilder
#define PRODUCT         keyboard
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
/* #define MATRIX_COL_PINS { C6, D7, E6, B4, B5 } */
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6 }
#define UNUSED_PINS

/* encoders */
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Mod tap stuff:  */
#define TAPPING_TOGGLE  2
#define TAPPING_TERM    200
//Note: it seems that  this i the important one below: (the ignore mod tap interrupt)
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)
/* fix space cadet rollover issue */
#define DISABLE_SPACE_CADET_ROLLOVER
/* NKRO */
#ifndef FORCE_NKRO
    #define FORCE_NKRO  // Depends on NKRO_ENABLE.
#endif


//Combos:
#define COMBO_COUNT 3

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

#define SOFT_SERIAL_PIN D0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define EE_HANDS

#define RGB_DI_PIN D3

#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SPLIT
#define RGBLED_NUM 16
#define RGBLIGHT_HUE_STEP 16
#define RGBLIGHT_SAT_STEP 16
#define RGBLIGHT_VAL_STEP 16
#define RGBLIGHT_LIMIT_VAL 100
#endif

#endif
