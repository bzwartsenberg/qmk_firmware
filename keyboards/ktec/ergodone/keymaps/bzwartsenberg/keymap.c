#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOUSE 2 // media keys
#define NAV 4 // nav keys
#define NUM 3 // number keys

#define TAPPING_TOGGLE 2

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  -   |           |  =   |   6  |   7  |   8  |   9  |   0  | BSPC   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    Tab |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ESC   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     |    '   |
 * |--------+------+------+------+------+------| `    |           |   '  |------+------+------+------+------+--------|
 * | LShift |Z     |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL |  CMD |Alt   | L3   | L1   |                                       |  L2  | L4   |   Alt| CMD  |  CTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | left |right|       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Enter|Tab   |------|       |------|  BSPC  |SPC   |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox( //layer 0 : default
        // left hand
        KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,
        KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV,
        KC_LCTL, KC_LGUI, KC_LALT, MO(3), MO(1),
        KC_LEFT, KC_RGHT,
        KC_HOME,
        KC_ENT, KC_TAB, KC_END,


        // right hand
        KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        TT(2), TT(4), KC_LALT, KC_LGUI, KC_LCTL,
        KC_UP, KC_DOWN,
        KC_PGUP,
        KC_PGDN, KC_BSPC, KC_SPC),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   $  |   +  |   (  |   )  |   @  |------|           |------|   *  |   -  |   =  |   _  |   ^  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   #  |   {  |   }  |   ~  |      |           |      |   &  |   [  |   ]  |   %  |   |  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,
        KC_TRNS, KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,
        KC_TRNS, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD, KC_TRNS,
        KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO,
        KC_NO, KC_NO,
        KC_NO,
        KC_NO, KC_NO, KC_NO,

       // right hand
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
        KC_ASTR, KC_MINS, KC_EQL, KC_UNDS, KC_CIRC, KC_NO,
        KC_TRNS, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_PIPE, KC_NO,
        KC_NO, KC_NO, KC_LALT, KC_LGUI, KC_LCTL,
        KC_NO, KC_NO,
        KC_NO,
        KC_NO, KC_NO, KC_NO),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |WHL_U |      |M_Ac2 |      |      |           |      |      |      | PSCR |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |WHL_L |WHL_D |WHL_R |M_Ac1 |      |------|           |------| MsLe | MsDn | MsUp | MsRi |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |M_Ac0 |      |      |           |TO(0) |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |BT_1  |BT_3  |      |       |      | BT_4 |BT_2  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |BT_5  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUSE] = LAYOUT_ergodox(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_ACL2, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_ACL1, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_BTN1, KC_BTN3, KC_TRNS,

      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
      TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_BTN5, KC_BTN4, KC_BTN2),

/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | BrDn | BrUp | MPrev| Mplay|Mnext |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  Up  |      |      |      |      |           |      |Home  |pgdn  |Pgup  |End   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Left | Down |Right |      |      |------|           |------|Left  | Down | Up   |Right |      |        |
 * |--------+------+------+------+------+------|      |           | TO(0)|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
//NAV and MEDIA
[NAV] = LAYOUT_ergodox(
      KC_NO, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,
      KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_NO, KC_NO,

      KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
      KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO,
      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
      TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_NO, KC_NO),



/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  1   |  2   |   3  |   4  |   5  |------|           |------|  6   |   7  |  8   |  9   |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
//NUM
[NUM] = LAYOUT_ergodox(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_NO, KC_NO,

      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
             KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_NO, KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
